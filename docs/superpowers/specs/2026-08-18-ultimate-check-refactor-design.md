# Ultimate Check Refactor — Design Spec

## Problem

`allUltimateCheck()` is currently called from 3 different places in
[`Combat.h`](../../../src/Defination/Function/Combat/Combat.h):

1. In `Take_action()`, before `turn->charptr->Turn_func()` runs.
2. In `Take_action()`, again right after `Turn_func()`/`Deal_damage()`
   (when `phaseStatus` becomes `AfterTurn`).
3. In `Deal_damage()`'s while-loop, after every individual action popped
   from `Action_bar` finishes.

Call site 2 is redundant with call site 3 (in the common case, the
`Deal_damage()` triggered by `Turn_func()` will itself trigger the
in-loop check), and none of the three call sites communicate *why*
an ult check is happening — every registered `Ultimate_List` entry
re-derives its own "is this my moment?" logic ad hoc via `phaseStatus`
and `turn->isSameUnit(...)` comparisons (see Huohuo, Saber, Castorice,
Tingyun, Hanabi, HanabiV1, Bronya, Gallagher).

## Goal

Reduce the ult-check trigger points to exactly two well-defined cases,
and remove the redundant third:

1. **Before a turn**: the moment a unit's turn is about to start, gated
   on that unit being a "controlable" character.
2. **After any action ends**: unchanged from the existing in-loop check
   inside `Deal_damage()`.

## Non-goals

- This does **not** touch per-character `addUltCondition` bodies.
  Existing checks like `phaseStatus == PhaseStatus::BeforeTurn &&
  turn->isSameUnit(...)` in Huohuo/Saber/Castorice/Tingyun/Hanabi/
  HanabiV1/Bronya/Gallagher stay exactly as they are. `controlable`
  is not a "whose turn is it" mechanism — that's still handled by
  `turn->canCastToAllyUnit()` inside `Combat.h`.
- This does not implement any crowd-control/stun system. `controlable`
  is added as a forward-looking hook for such a system but nothing
  sets it to `false` yet.
- This does not touch the `AhaInstantBar`/`Action_bar` duplication or
  the missing `BeforeAhaInstant()`/`AfterAhaInstant()` calls in
  `AhaInstant(int PL)` — both were raised earlier in discussion but are
  explicitly out of scope for this change.

## Design

### 1. New field: `AllyUnit::controlable`

In [`AllyUnit.h`](../../../src/Defination/Class/Unit/AllyUnit.h):

```cpp
bool controlable = true;
```

Defaults to `true` for every `AllyUnit`. Nothing sets it to `false`
anywhere in this change — it exists purely as a hook so a future
disable/stun system can flip it per-unit without touching the
ult-check call sites.

### 2. `Combat.h` call sites

`allUltimateCheck()` itself is unchanged — no parameters, no internal
gating logic.

Remove all 3 existing call sites and replace with exactly 2:

```cpp
void Take_action(){
    if(!turn->charptr){
        AhaTurn();
        return;
    }
    phaseStatus = PhaseStatus::DotBeforeTurn;
    if(!turn->extraTurn){
        ++(turn->turnCnt);
        allEventBeforeTurn();
    }

    // case 1: before turn, gated on the turn owner being controlable
    AllyUnit *ally = turn->canCastToAllyUnit();
    if(ally && ally->controlable) allUltimateCheck();

    Print();
    if(Turn_Skip==0){
        turn->charptr->Turn_func();
        Deal_damage();
    }
    phaseStatus = PhaseStatus::AfterTurn;
    if(!turn->extraTurn)allEventAfterTurn();
}
```

```cpp
void Deal_damage(){
    if(actionBarUse)return;
    actionBarUse = true;
    ...
    while(!Action_bar.empty()){
        ...
        allEventAfterAction(temp);
        if(turn)allUltimateCheck();   // case 2: unchanged
        Action_bar.pop();
    }
    actionBarUse = false;
    ...
}
```

The old post-`Turn_func()` call (previously right after
`phaseStatus = PhaseStatus::AfterTurn;`) is deleted — it is covered by
case 2, since `Turn_func()` runs through `Deal_damage()` immediately
before it.

### 3. Files touched

- [`src/Defination/Class/Unit/AllyUnit.h`](../../../src/Defination/Class/Unit/AllyUnit.h) — add `controlable` field.
- [`src/Defination/Function/Combat/Combat.h`](../../../src/Defination/Function/Combat/Combat.h) — collapse 3 call sites into 2 in `Take_action()`; no change to `Deal_damage()`'s existing call.

No character files are touched.

## Risk / Verification

- `Take_action()` is the core turn loop; every character and every
  Ultimate_List entry runs through it. The behavioral risk is narrow
  because `allUltimateCheck()` itself is untouched — only the *number
  and placement* of its call sites changes, and the removed call site
  is provably redundant with the kept one (both fire directly after
  `Turn_func()` executes, one via explicit call, one via the
  `Deal_damage()` while-loop it invokes).
- Enemy turns: when `turn->charptr` is an enemy, `ally` is `nullptr`,
  so case 1 is skipped — matches current behavior where ult checks
  during enemy turns only ever fired through the in-loop
  (`Deal_damage()`) path in practice.
- Verify after implementation: run a combat simulation covering at
  least one character from each of the 8 files with custom
  `addUltCondition` bodies (Huohuo, Saber, Castorice, Tingyun, Hanabi,
  HanabiV1, Bronya, Gallagher) plus one unconditional one (YaoGuang or
  Hibana), and confirm ults still trigger at the same points as before
  the refactor.
