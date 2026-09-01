#include "../include.h"

//========================  Tingyun (ถิงหยุน) — Lightning / Harmony / 4★  ========================
// kit อ้างอิง: docs/character-kit-reference/Tingyun.md
// ตัวเลข ability = 4★ ที่ E6  →  Basic ATK Lv.7 / Skill·Ultimate·Talent Lv.12
namespace Tingyun{

    // ---- buff keys ของ Tingyun (prefix ชื่อตัวละคร: Buff_check/Buff_countdown เป็น map เดียวทั้งเกม) ----
    static const string BUFF_BENEDICTION = "Tingyun Benediction";        // Skill  : ATK%  (บนเป้าหมาย)
    static const string BUFF_NOURISHED   = "Tingyun Nourished Joviality"; // A2     : SPD%  (บนตัว Tingyun)
    static const string BUFF_REJOICING   = "Tingyun Rejoicing Clouds";    // Ult    : DMG%  (บนเป้าหมาย)
    static const string BUFF_WINDFALL    = "Tingyun Windfall";            // Ult E1 : SPD%  (บนเป้าหมาย)

    // ---- ขนาดบัฟ: apply กับ remove อ้างค่าเดียวกัน กันเลื่อน ----
    constexpr double BENEDICTION_ATK = 55;   // Skill Lv.12
    constexpr double NOURISHED_SPD   = 20;
    constexpr double REJOICING_DMG   = 56;   // Ult Lv.12
    constexpr double WINDFALL_SPD    = 20;

    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){

        // ---------- stats / build ----------
        CharUnit *ptr = SetCharBasicStats(112, 130, 130, E, ElementType::Lightning, Path::Harmony, "Tingyun", UnitType::Standard);
        AllyUnit *TYptr = ptr;
        ptr->SetAllyBaseStats(847, 529, 397);
        ptr->Technique = 2;                     // one-off: Technique = "จำนวน technique" → energy = 50 * 2 (ดู Start_game_List)
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(140);
        ptr->setRelicMainStats(Stats::ATK_P, Stats::FLAT_SPD, Stats::ATK_P, Stats::ER);

        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        // ---------- helper: "Benediction" มีผลกับเป้าหมาย Skill ล่าสุดเท่านั้น (Tingyun support เป้าหมายเดียว) ----------
        // เก็บ holder จริงผ่าน ptr->buffSubUnitTarget (แยกจาก chooseSubUnitBuff ซึ่งอ่าน currentCharNum ณ ปัจจุบัน
        // เผื่อมันเปลี่ยนไปแล้วตั้งแต่ครั้งก่อนที่ลงบัฟ) — ถ้า holder เดิม != เป้าหมายใหม่ ให้ถอนบัฟจากตัวเดิมก่อน
        // ใช้ isBuffGoneByDeath เพราะเคลียร์ทั้ง Buff_check + Buff_countdown → กัน isBuffEnd มายิง -stat ซ้ำ
        function<void(AllyUnit*)> clearStaleAllyBuffs = [ptr](AllyUnit *keep){
            auto retarget = [ptr, keep](const string &name, Stats stat, double value) {
                AllyUnit *old = ptr->getBuffSubUnitTarget(name);
                if (old && old != keep && isBuffGoneByDeath(old, name))
                    buffSingle(old, {{stat, AType::None, -value}});
                ptr->setBuffSubUnitTarget(name, keep);
            };
            retarget(BUFF_BENEDICTION, Stats::ATK_P, BENEDICTION_ATK);
            retarget(BUFF_REJOICING,   Stats::DMG,   REJOICING_DMG);
            retarget(BUFF_WINDFALL,    Stats::SPD_P, WINDFALL_SPD);
        };

        #pragma region Ability

        // Basic ATK: Dislodged (Lv.7 = 110%, model เป็น 2 จังหวะ)
        function<void()> BA = [ptr, TYptr]() {
            genSkillPoint(ptr, 1);
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::BA, ptr, TraceType::Single, "TY BA",
            [ptr](shared_ptr<AllyAttackAction> &act){
                Increase_energy(ptr, 20);
                Attack(act);
            });
            act->addDamageIns(DmgSrc(DmgSrcType::ATK, 33, 3));
            act->addDamageIns(DmgSrc(DmgSrcType::ATK, 77, 7));
            act->addToActionBar();
        };

        // Skill: Soothing Melody
        function<void()> Skill = [ptr, TYptr, clearStaleAllyBuffs]() {
            genSkillPoint(ptr, -1);
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::SKILL, ptr, TraceType::Single, "TY Skill",
            [ptr, clearStaleAllyBuffs](shared_ptr<AllyBuffAction> &act){
                AllyUnit *target = act->buffTargetList[0];
                Increase_energy(ptr, 30);

                // Benediction: ATK% ให้เป้าหมาย (kit: cap 25% ของ ATK Tingyun — ตัดทิ้ง, ATK Tingyun สูงพอเสมอ)
                clearStaleAllyBuffs(target);
                buffSingle(target, {{Stats::ATK_P, AType::None, BENEDICTION_ATK}}, BUFF_BENEDICTION, 3);

                // A2 Nourished Joviality: SPD% บนตัว Tingyun 1 เทิร์น (holder = Tingyun เอง, ไม่ retarget)
                buffSingle(ptr, {{Stats::SPD_P, AType::None, NOURISHED_SPD}}, BUFF_NOURISHED, 1);
                ptr->setBuffSubUnitTarget(BUFF_NOURISHED, ptr);
            });
            act->addBuffSingleTarget(chooseSubUnitBuff(ptr));
            act->addToActionBar();
        };

        #pragma endregion

        // ---------- Turn AI: เป้าหมายยังไม่มี Benediction → Skill, มีแล้ว → Basic ----------
        // เช็ค chooseSubUnitBuff สด (เป้าหมายที่ "ตั้งใจ" ซัพตอนนี้) ไม่ใช่ tracker —
        // ถ้าเป้าหมายเปลี่ยน อยากให้ Skill ทับใส่ตัวใหม่ (clearStaleAllyBuffs จะถอนของตัวเก่าเอง)
        ptr->Turn_func = [ptr, TYptr, BA, Skill]() {
            if (!chooseSubUnitBuff(ptr)->getBuffCheck(BUFF_BENEDICTION))
                Skill();
            else
                BA();
        };

        // ---------- Ult-timing AI ----------
        // อย่ายิง ult ถ้าเป้าหมายใกล้จะ ult เอง (เหลือ energy <= 30) — รอให้เขา ult ก่อน
        // escape hatch: Saber (energy 360, กติกาต่าง) / เป้าหมายที่ไม่มี energy (Max_energy == 0)
        ptr->addUltCondition([ptr, TYptr]() -> bool {
            if (chooseSubUnitBuff(TYptr)->isSameName("Saber")) return true;
            if (charUnit[ptr->currentCharNum]->Max_energy == 0) return true;
            if (charUnit[ptr->currentCharNum]->Max_energy - charUnit[ptr->currentCharNum]->Current_energy <= 30) return false;
            return true;
        });

        // ---------- Ultimate: Amidst the Rejoicing Clouds ----------
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, ptr, [ptr, TYptr, clearStaleAllyBuffs]() {
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::Ult, ptr, TraceType::Single, "TY Ult",
            [ptr, TYptr, clearStaleAllyBuffs](shared_ptr<AllyBuffAction> &act){
                CharCmd::printUltStart("Tingyun");
                AllyUnit *target = chooseSubUnitBuff(ptr);

                // energy → ตัว "character" (ไม่ใช่ memosprite) ของเป้าหมาย
                Increase_energy(charUnit[ptr->currentCharNum].get(), 0, (ptr->Eidolon >= 6) ? 60 : 50);

                clearStaleAllyBuffs(target);   // เป้าหมายเปลี่ยน → ถอนบัฟของ holder เดิม

                // E1 Windfall of Lucky Springs: SPD% 1 เทิร์น
                if (ptr->Eidolon >= 1)
                    buffSingle(target, {{Stats::SPD_P, AType::None, WINDFALL_SPD}}, BUFF_WINDFALL, 1);

                // Rejoicing Clouds: DMG% 2 เทิร์น
                // ลงตอนเทิร์นเป้าหมาย (BeforeTurn) → ใช้ dur 1 กัน over-count 1 เทิร์น (บั๊ก ult Tingyun/Bronya)
                bool onTargetTurn = (turn->Name == charUnit[ptr->currentCharNum]->Atv_stats->Name
                                     && phaseStatus == PhaseStatus::BeforeTurn);
                buffSingle(target, {{Stats::DMG, AType::None, REJOICING_DMG}}, BUFF_REJOICING, onTargetTurn ? 1 : 2);
            });
            act->addBuffSingleTarget(chooseSubUnitBuff(ptr));
            act->addToActionBar();
            Deal_damage();
        }));

        // ---------- Minor traces (รวม) + A4 Knell Subdual (Basic ATK DMG +40%) ----------
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr, TYptr]() {
            ptr->Stats_each_element[Stats::DMG][ElementType::Lightning][AType::None] += 8;   // Lightning DMG +8%
            ptr->Stats_type[Stats::ATK_P][AType::None] += 28;                                // ATK +28%
            ptr->Stats_type[Stats::DEF_P][AType::None] += 22.5;                              // DEF +22.5%
            // relic / substats: จัดการที่อื่น
            ptr->Stats_type[Stats::DMG][AType::BA] += 40;                                    // A4
        }));

        // ---------- A6 Jubilant Passage: +5 energy ต้นเทิร์นของ Tingyun ----------
        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr, TYptr]() {
            if (turn->Name != ptr->Atv_stats->Name) return;
            Increase_energy(ptr, 5);
        }));

        // ---------- Buff expiry: ถอน stat delta เมื่อบัฟหมดเวลา (holder = buffSubUnitTarget) ----------
        // isBuffEnd เช็คเองว่าเป็นเทิร์นของ holder → เรียกทุก After_turn ปลอดภัย
        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr, TYptr]() {
            auto expire = [ptr](const string &name, Stats stat, double value) {
                AllyUnit *h = ptr->getBuffSubUnitTarget(name);
                if (h && isBuffEnd(h, name)) buffSingle(h, {{stat, AType::None, -value}});
            };
            expire(BUFF_BENEDICTION, Stats::ATK_P, BENEDICTION_ATK);
            expire(BUFF_NOURISHED,   Stats::SPD_P, NOURISHED_SPD);
            expire(BUFF_REJOICING,   Stats::DMG,   REJOICING_DMG);
            expire(BUFF_WINDFALL,    Stats::SPD_P, WINDFALL_SPD);
        }));

        // ---------- Technique Gentle Breeze: energy ต้นการต่อสู้ (50 ต่อ technique) ----------
        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr, TYptr]() {
            Increase_energy(ptr, 0, 50 * ptr->Technique);
        }));

        // ---------- Additional DMG (Benediction ถืออยู่บนเป้าหมาย) ----------
        //   Tingyun ตี  → Talent "Violet Sparknado" : 66% (E4 → 86%) ATK ของเป้าหมาย
        //   เป้าหมายตี → Skill  "Soothing Melody"   : 44% (E4 → 64%) ATK ของเป้าหมาย
        //   * additional สเกลกับ ATK ของ "เป้าหมาย" ไม่ใช่ Tingyun → source = ผู้ถือ Benediction
        //   * holder อ้าง buffSubUnitTarget (ผู้ถือจริง) ไม่ใช่ chooseSubUnitBuff สด
        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTTACK, [ptr, TYptr](shared_ptr<AllyAttackAction> &act) {
            AllyUnit *holder = ptr->getBuffSubUnitTarget(BUFF_BENEDICTION);
            if (!holder || !holder->getBuffCheck(BUFF_BENEDICTION)) return;

            if (act->Attacker->Atv_stats->Name == ptr->Atv_stats->Name) {
                // Talent — Tingyun เป็นผู้โจมตี
                shared_ptr<AllyAttackAction> add =
                make_shared<AllyAttackAction>(AType::Addtional, holder, TraceType::Single, "TY Talent");
                add->addDamageIns(DmgSrc(DmgSrcType::ATK, (ptr->Eidolon >= 4) ? 86 : 66));
                Attack(add);
            }
            else if (act->Attacker->isSameName(holder)) {
                // Skill — ผู้ถือ Benediction เป็นผู้โจมตี
                shared_ptr<AllyAttackAction> add =
                make_shared<AllyAttackAction>(AType::Addtional, act->Attacker, TraceType::Single, "TY Talent");
                add->addDamageIns(DmgSrc(DmgSrcType::ATK, (ptr->Eidolon >= 4) ? 64 : 44));
                Attack(add);
            }
        }));

        // ---------- Death: ถอนบัฟของ Tingyun จาก ally ที่ตาย (isBuffEnd ไม่ยิงให้ unit ที่ไม่มีเทิร์น) ----------
        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr, TYptr](AllyUnit* target) {
            if (isBuffGoneByDeath(target, BUFF_BENEDICTION)) buffSingle(target, {{Stats::ATK_P, AType::None, -BENEDICTION_ATK}});
            if (isBuffGoneByDeath(target, BUFF_REJOICING))   buffSingle(target, {{Stats::DMG,   AType::None, -REJOICING_DMG}});
            if (isBuffGoneByDeath(target, BUFF_WINDFALL))    buffSingle(target, {{Stats::SPD_P, AType::None, -WINDFALL_SPD}});
            if (isBuffGoneByDeath(target, BUFF_NOURISHED))   buffSingle(target, {{Stats::SPD_P, AType::None, -NOURISHED_SPD}});
        }));
    }
}
