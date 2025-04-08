#ifndef DEBUFF_STATS_H
#define DEBUFF_STATS_H
#include "../Unit/Trigger_Function.h"
using namespace std;
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12




void Debuff_single_target(Enemy *ptr, string stats_type, string Attack_type, double Value) {
    ptr->Stats_type[stats_type][Attack_type] += Value;
}

void Debuff_single_target(Enemy *ptr, string stats_type, string Attack_type, string Element, double Value) {
    ptr->Stats_each_element[stats_type][Element][Attack_type] += Value;
}

void Debuff_All_Enemy_Apply_ver(SubUnit *ptr, string stats_type, string Attack_type, double Value, string Debuff_Name) {
    for (int i = 1; i <= Total_enemy; i++) {
        allEventApplyDebuff(ptr, Enemy_unit[i].get());
        if (Enemy_unit[i]->Debuff[Debuff_Name] != 0) continue;
        Enemy_unit[i]->Debuff[Debuff_Name] = 1;
        Enemy_unit[i]->Total_debuff++;

        Debuff_single_target(Enemy_unit[i].get(), stats_type, Attack_type, Value);
    }
}

void Debuff_All_Enemy_Apply_ver(SubUnit *ptr, string stats_type, string Attack_type, string Element, double Value, string Debuff_Name) {
    for (int i = 1; i <= Total_enemy; i++) {
        allEventApplyDebuff(ptr, Enemy_unit[i].get());
        if (Enemy_unit[i]->Debuff[Debuff_Name] != 0) continue;
        Enemy_unit[i]->Debuff[Debuff_Name] = 1;
        Enemy_unit[i]->Total_debuff++;

        Debuff_single_target(Enemy_unit[i].get(), stats_type, Attack_type, Element, Value);
    }
}

//stack buff/debuff
void Stack_Debuff_single_target(Enemy *ptr, string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
    if (ptr->Debuff[Stack_Name] >= Stack_limit) return;
    if (ptr->Debuff[Stack_Name] + Stack_increase > Stack_limit) {
        Stack_increase = Stack_limit - ptr->Debuff[Stack_Name];
    }
    if (ptr->Debuff[Stack_Name] == 0) ptr->Total_debuff++;

    Debuff_single_target(ptr, stats_type, Attack_type, Stack_increase * Value_per_stack);
    ptr->Debuff[Stack_Name] += Stack_increase;
}

void Stack_Debuff_single_target(Enemy *ptr, string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
    if (ptr->Debuff[Stack_Name] >= Stack_limit) return;
    if (ptr->Debuff[Stack_Name] + Stack_increase > Stack_limit) {
        Stack_increase = Stack_limit - ptr->Debuff[Stack_Name];
    }
    if (ptr->Debuff[Stack_Name] == 0) ptr->Total_debuff++;

    Debuff_single_target(ptr, stats_type, Attack_type, Element, Stack_increase * Value_per_stack);
    ptr->Debuff[Stack_Name] += Stack_increase;
}

void Stack_Debuff_All_Enemy(SubUnit *ptr, string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
    int original_increase = Stack_increase;
    for (int i = 1; i <= Total_enemy; i++) {
        allEventApplyDebuff(ptr, Enemy_unit[i].get());
        if (Enemy_unit[i]->Debuff[Stack_Name] < Stack_limit) {
            if (Enemy_unit[i]->Debuff[Stack_Name] == 0) Enemy_unit[i]->Total_debuff++;
            if (Enemy_unit[i]->Debuff[Stack_Name] + Stack_increase > Stack_limit) {
                Stack_increase = Stack_limit - Enemy_unit[i]->Debuff[Stack_Name];
            }
            Enemy_unit[i]->Debuff[Stack_Name] += Stack_increase;

            Debuff_single_target(Enemy_unit[i].get(), stats_type, Attack_type, Stack_increase * Value_per_stack);
            Stack_increase = original_increase;
        }
    }
}

void Stack_Debuff_All_Enemy(SubUnit *ptr, string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
    int original_increase = Stack_increase;
    for (int i = 1; i <= Total_enemy; i++) {
        allEventApplyDebuff(ptr, Enemy_unit[i].get());
        if (Enemy_unit[i]->Debuff[Stack_Name] < Stack_limit) {
            if (Enemy_unit[i]->Debuff[Stack_Name] == 0) Enemy_unit[i]->Total_debuff++;
            if (Enemy_unit[i]->Debuff[Stack_Name] + Stack_increase > Stack_limit) {
                Stack_increase = Stack_limit - Enemy_unit[i]->Debuff[Stack_Name];
            }
            Enemy_unit[i]->Debuff[Stack_Name] += Stack_increase;

            Debuff_single_target(Enemy_unit[i].get(), stats_type, Attack_type, Element, Stack_increase * Value_per_stack);
            Stack_increase = original_increase;
        }
    }
}


#endif