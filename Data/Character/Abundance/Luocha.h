
#ifndef Luocha_H
#define Luocha_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Luocha{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Talent(Ally *ptr);
    void Abyss_Flower(Ally *ptr);


    
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(101,100,100,E,"Imaginary","Abundance","Luocha",TYPE_STD);
        ptr->SetAllyBaseStats(1280,756,363);

        ptr->pushSubstats(ST_ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(150);
        ptr->setRelicMainStats(ST_HEALING_OUT,ST_FLAT_SPD,ST_ATK_P,ST_EnergyRecharge);

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
            shared_ptr<AllyAttackAction> data_ = 
            make_shared<AllyAttackAction>(ActionType::Ult,ptr->getSubUnit(),TT_AOE,"Luocha Ult",
        [ptr](shared_ptr<AllyAttackAction> data_){
            Attack(data_);
            ++ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"];
            Abyss_Flower(ptr);
        });
            data_->addDamageIns(
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20));
            data_->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AT_NONE] += 28;
            ptr->Sub_Unit_ptr[0]->Stats_type["Hp%"][AT_NONE] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type["Def%"][AT_NONE] += 12.5;

            // relic

            // substats
        }));


        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Charptr = ptr->Sub_Unit_ptr[0].get()]() {
            if (turn->Char_Name == "Luocha") {
                if (Charptr->isBuffEnd("Cycle_of_Life")) {
                    if (ptr->Eidolon >= 1) {
                        buffAllAlly({{ST_ATK_P,AT_NONE,-20}});
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

        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &data_) {
            if (ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"] >= 2) {
                RestoreHP({18, 0, 0, 240, 0, 0}, {7, 0, 0, 93, 0, 0}, ptr->Sub_Unit_ptr[0].get(), data_->Attacker);
            }
        }));
        

    }


    void Talent(Ally *ptr){
        Increase_energy(ptr,30);
        ++ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"];
        RestoreHP(ptr->getSubUnit(),{60,0,0,800,0,0},{},{});
        Abyss_Flower(ptr);
        
    }
    void Abyss_Flower(Ally *ptr){
        if(ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"]==2){
            ptr->Sub_Unit_ptr[0]->extendBuffTime("Cycle _of_Life",2);
        if(ptr->Eidolon>=1){
            buffAllAlly({{ST_ATK_P,AT_NONE,20}});
        }
        }
    }
    void Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyAttackAction> data_ = 
        make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_SINGLE,"Luocha BA",
        [ptr](shared_ptr<AllyAttackAction> data_){
            Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
            if(ptr->Sub_Unit_ptr[0]->Atv_stats->turn_cnt%2==1){
                Talent(ptr);
            }
        });
        data_->addDamageIns(DmgSrc(DmgSrcType::ATK,30,3));
        data_->addDamageIns(DmgSrc(DmgSrcType::ATK,30,3));
        data_->addDamageIns(DmgSrc(DmgSrcType::ATK,40,4));
        data_->addToActionBar();

    }





    

    
}
#endif
