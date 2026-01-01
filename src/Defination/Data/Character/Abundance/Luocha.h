#include "../include.h"

namespace Luocha{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void Basic_Atk(CharUnit *ptr);
    void Talent(CharUnit *ptr);
    void Abyss_Flower(CharUnit *ptr);


    
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(101,100,100,E,ElementType::Imaginary,Path::Abundance,"Luocha",UnitType::Standard);
        ptr->SetAllyBaseStats(1280,756,363);

        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(150);
        ptr->setRelicMainStats(Stats::HEALING_OUT,Stats::FLAT_SPD,Stats::ATK_P,Stats::ER);

        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        
       ptr->Turn_func = [ptr]() {
            Basic_Atk(ptr);
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_DEBUFF, [ptr]() {
            if (ptr->Stack["Abyss_Flower"] >= 2) return;
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr,TraceType::Aoe,"Luocha Ult",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Attack(act);
            ++ptr->Stack["Abyss_Flower"];
            Abyss_Flower(ptr);
        });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20));
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::ATK_P][AType::None] += 28;
            ptr->Stats_type[Stats::HP_P][AType::None] += 18;
            ptr->Stats_type[Stats::DEF_P][AType::None] += 12.5;

            // relic

            // substats
        }));


        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Charptr = ptr]() {
            if (turn->UnitName == "Luocha") {
                if (isBuffEnd(Charptr,"Cycle_of_Life")) {
                    if (ptr->Eidolon >= 1) {
                        buffAllAlly({{Stats::ATK_P,AType::None,-20}});
                    }
                    Charptr->setStack("Abyss_Flower",0);
                }
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Technique == 1) {
                ptr->Stack["Abyss_Flower"] = 2;
                Abyss_Flower(ptr);
            }
        }));

        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (ptr->Stack["Abyss_Flower"] >= 2) {
                ptr->RestoreHP(
                    act->Attacker,
                    HealSrc(HealSrcType::ATK,18,HealSrcType::CONST,240),
                    HealSrc(HealSrcType::ATK,7,HealSrcType::CONST,93)
                );

            }
        }));
        

    }


    void Talent(CharUnit *ptr){
        Increase_energy(ptr,30);
        ++ptr->Stack["Abyss_Flower"];
        ptr->RestoreHP(HealSrc(HealSrcType::ATK,60,HealSrcType::CONST,800),HealSrc(),HealSrc());
        Abyss_Flower(ptr);
        
    }
    void Abyss_Flower(CharUnit *ptr){
        if(ptr->Stack["Abyss_Flower"]==2){
            extendBuffTime(ptr,"Cycle _of_Life",2);
        if(ptr->Eidolon>=1){
            buffAllAlly({{Stats::ATK_P,AType::None,20}});
        }
        }
    }
    void Basic_Atk(CharUnit *ptr){
        
        Skill_point(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"Luocha BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,20);
            Attack(act);
            if(ptr->Atv_stats->turnCnt%2==1){
                Talent(ptr);
            }
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,30,3));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,30,3));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,40,4));
        act->addToActionBar();

    }





    

    
}