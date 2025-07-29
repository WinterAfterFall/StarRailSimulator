#include "../include.h"

namespace Luocha{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Talent(Ally *ptr);
    void Abyss_Flower(Ally *ptr);


    
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(101,100,100,E,ElementType::Imaginary,Path::Abundance,"Luocha",TYPE_STD);
        ptr->SetAllyBaseStats(1280,756,363);

        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(150);
        ptr->setRelicMainStats(Stats::HEALING_OUT,Stats::FLAT_SPD,Stats::ATK_P,Stats::ER);

        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        
       ptr->Sub_Unit_ptr[0]->Turn_func = [ptr]() {
            Basic_Atk(ptr);
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_DEBUFF, [ptr]() {
            if (ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"] >= 2) return;
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr->getSubUnit(),TT_AOE,"Luocha Ult",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Attack(act);
            ++ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"];
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
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 28;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::HP_P][AType::None] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DEF_P][AType::None] += 12.5;

            // relic

            // substats
        }));


        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Charptr = ptr->Sub_Unit_ptr[0].get()]() {
            if (turn->Char_Name == "Luocha") {
                if (Charptr->isBuffEnd("Cycle_of_Life")) {
                    if (ptr->Eidolon >= 1) {
                        buffAllAlly({{Stats::ATK_P,AType::None,-20}});
                    }
                    Charptr->setStack("Abyss_Flower",0);
                }
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Technique == 1) {
                ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"] = 2;
                Abyss_Flower(ptr);
            }
        }));

        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"] >= 2) {
                ptr->getSubUnit()->RestoreHP(
                    act->Attacker,
                    HealSrc(HealSrcType::ATK,18,HealSrcType::CONST,240),
                    HealSrc(HealSrcType::ATK,7,HealSrcType::CONST,93)
                );

            }
        }));
        

    }


    void Talent(Ally *ptr){
        Increase_energy(ptr,30);
        ++ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"];
        ptr->getSubUnit()->RestoreHP(HealSrc(HealSrcType::ATK,60,HealSrcType::CONST,800),HealSrc(),HealSrc());
        Abyss_Flower(ptr);
        
    }
    void Abyss_Flower(Ally *ptr){
        if(ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"]==2){
            ptr->Sub_Unit_ptr[0]->extendBuffTime("Cycle _of_Life",2);
        if(ptr->Eidolon>=1){
            buffAllAlly({{Stats::ATK_P,AType::None,20}});
        }
        }
    }
    void Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TT_SINGLE,"Luocha BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(act);
            if(ptr->Sub_Unit_ptr[0]->Atv_stats->turnCnt%2==1){
                Talent(ptr);
            }
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,30,3));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,30,3));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,40,4));
        act->addToActionBar();

    }





    

    
}