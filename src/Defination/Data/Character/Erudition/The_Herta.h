
#include "../include.h"

namespace The_Herta{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
//temp
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);
    void Enchance_Skill(Ally *ptr);
    void Apply_Herta_Stack(Ally* ptr ,Enemy* target,int Stack);
    void Herta_reset_Stack();
    bool Enchance_Skill_Condition(Ally *ptr);


    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(99,220,220,E,ElementType::Ice,"Erudition","The_Herta",TYPE_STD);
        SubUnit* Hertaptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(1164,679,485);

        //substats
        ptr->pushSubstats(ST_CD);
        ptr->pushSubstats(ST_CR);
        ptr->pushSubstats("Atk%");
        ptr->setTotalSubstats(20);
        ptr->setRelicMainStats(ST_CR,ST_ATK_P,ST_DMG,ST_ATK_P);



        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {

            if (Enchance_Skill_Condition(ptr)) {
                return;
            } else if (sp > Sp_Safety || Sp_status == "Positive") {
                Skill(ptr);
            } else {
                Basic_Atk(ptr);
            }
        };

        ptr->addUltCondition([ptr]() -> bool {
            if ((ptr->Sub_Unit_ptr[0]->Atv_stats->atv < ptr->Sub_Unit_ptr[0]->Atv_stats->Max_atv * 0.2)) return false;
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr,Hertaptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(ActionType::Ult,ptr->getSubUnit(),TT_AOE,"THerta Ult",
            [ptr,Hertaptr](shared_ptr<AllyAttackAction> &act){
                double Increase_mtpr = ptr->Sub_Unit_ptr[0]->Stack["The_Herta_A6"];
                act->addDamage(DmgSrcType::ATK,Increase_mtpr);
                ptr->Sub_Unit_ptr[0]->Buff_note["The_Herta_Skill_Enchance"]++;
                if (ptr->Eidolon >= 2) {
                    ptr->Sub_Unit_ptr[0]->Buff_note["The_Herta_Skill_Enchance"]++;
                }
                Hertaptr->buffSingle({{ST_ATK_P,AT_NONE,80}},"Ult_The_Herta_Buff",3);

                if (ptr->Print)CharCmd::printUltStart("The Herta");
                Attack(act);

                Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 100);
                Herta_reset_Stack();
            });
            act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,200,20),
                    DmgSrc(DmgSrcType::ATK,200,20),
                    DmgSrc(DmgSrcType::ATK,200,20)
            );
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AT_NONE] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG][ElementType::Ice][AT_NONE] += 22.4;
            ptr->Sub_Unit_ptr[0]->Atv_stats->flatSpeed += 5;

            // relic

            // substats
            int cnt = 0;
            for (int i = 1; i <= Total_ally; i++) {
                for (auto e : Ally_unit[i]->Path) {
                    if (e == "Erudition") cnt++;
                }
                if (cnt >= 2) {
                    ptr->Sub_Unit_ptr[0]->Buff_check["Two_Erudition"] = 1;
                    break;
                }
            }
        }));


        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Hertaptr]() {
            if (ptr->Technique == 1) {
                Hertaptr->buffSingle({{ST_ATK_P,AT_NONE,60}},"The_Herta_Technique",2);
            }
            Apply_Herta_Stack(ptr, Enemy_unit[Main_Enemy_num].get(), 25);
            for (int i = 1; i <= Total_enemy; i++) {
                Apply_Herta_Stack(ptr, Enemy_unit[i].get(), 1);
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,Hertaptr]() {
            if (Hertaptr->isBuffEnd("The_Herta_Technique")) {
                Hertaptr->buffSingle({{ST_ATK_P,AT_NONE,-60}});
            }
            if (Hertaptr->isBuffEnd("Ult_The_Herta_Buff")) {
                Hertaptr->buffSingle({{ST_ATK_P,AT_NONE,-80}});
            }
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Sub_Unit_ptr[0]->Buff_check["Two_Erudition"] == 1) {
                buffAllAlly({{ST_CD,AT_NONE,80}});
            }
        }));

        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_BUFF, [ptr,Hertaptr](shared_ptr<AllyAttackAction> &act){
            if(act->actionName=="THerta ESkill"){
                Hertaptr->buffSingle({{ST_DMG,AT_NONE,-50}});
                if(ptr->Eidolon >= 2)Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(),35);
            }
            bool Erudition_check = 0;

            for(auto e : act->Attacker->ptrToChar->Path){
                if(e == "Erudition") Erudition_check = 1;
            }
            for(auto e : act->targetList){
                Apply_Herta_Stack(ptr, e, 1);
            }
            if(Erudition_check){
                Apply_Herta_Stack(ptr, Enemy_unit[Main_Enemy_num].get(), 3);
            } else {
                Apply_Herta_Stack(ptr, Enemy_unit[Main_Enemy_num].get(), 1);
            }
            int energy_gen = act->targetList.size();
            if(energy_gen < 9) energy_gen = 9;
            Increase_energy(ptr, 0, energy_gen);
        }));

        Enemy_Death_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, SubUnit *Killer) {
            Apply_Herta_Stack(ptr, Enemy_unit[Main_Enemy_num].get(), 1);
        }));


        
    }
    

    bool Stack_Herta_Check(Ally *ptr){
        int temp = Enemy_unit[Main_Enemy_num]->Debuff["Herta_Stack"];
        if(ptr->Eidolon>=1){
            int mx = -1;
            for(int i=1;i<=Total_enemy;i++){
                if(i==Main_Enemy_num)continue;
                mx = max(mx,Enemy_unit[i]->Debuff["Herta_Stack"]);
            }
            temp+=mx;

        }
        if(temp>=42)return true;
        
        return true;
    }
    bool Enchance_Skill_Condition(Ally *ptr){
        if(ptr->Eidolon>=2&&Driver_Type=="Double_turn"&&Ally_unit[Driver_num]->Sub_Unit_ptr[0]->Atv_stats->Max_atv < ptr->Sub_Unit_ptr[0]->Atv_stats->Max_atv&&ptr->Sub_Unit_ptr[0]->Atv_stats->Max_atv*0.65<Ally_unit[Driver_num]->Sub_Unit_ptr[0]->Atv_stats->atv){
            if(ptr->Current_energy>=190&&(CharCmd::Using_Skill(ptr)||ptr->Current_energy<200)){
                if(ptr->Sub_Unit_ptr[0]->Buff_note["The_Herta_Skill_Enchance"]>0){
                    Enchance_Skill(ptr);
                }else{
                    Skill(ptr);  
                }
                return true;
            }else if(ptr->Current_energy>=200){
                Basic_Atk(ptr);
                return true;
            }else{
                Enchance_Skill(ptr);
                return true;
            }
            
        }
        if(ptr->Sub_Unit_ptr[0]->Buff_note["The_Herta_Skill_Enchance"]>0){
            // if(CharCmd::Using_Skill(ptr)&&Stack_Herta_Check(ptr)){
            //     Enchance_Skill(ptr);
            // }else{
            //     Basic_Atk(ptr);
            // }
            Enchance_Skill(ptr);
            
            return true;
        }
        return false;
    }

    void Basic_Atk(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_SINGLE,"THerta BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,100,10));
        act->addToActionBar();
    }

    void Skill(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::SKILL,ptr->getSubUnit(),TT_BLAST,"THerta Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Apply_Herta_Stack(ptr,Enemy_unit[Main_Enemy_num].get(),1);
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,70,5));
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,70,5),
            DmgSrc(DmgSrcType::ATK,70,5)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,70,5),
            DmgSrc(DmgSrcType::ATK,70,5),
            DmgSrc(DmgSrcType::ATK,70,5)
        );
        act->addToActionBar();
    }

    void Enchance_Skill(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::SKILL,ptr->getSubUnit(),TT_AOE,"THerta ESkill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            double Increase_mtpr = Enemy_unit[Main_Enemy_num]->Debuff["Herta_Stack"];
            double mx =-1;
            if(ptr->Eidolon>=1){
                for(int i=2;i<=Total_enemy;i++){
                if(Enemy_unit[i]->Debuff["Herta_Stack"]>mx){
                    mx = Enemy_unit[i]->Debuff["Herta_Stack"];
                }
                }
                Increase_mtpr+=(0.5*mx);
            }
            
            if(ptr->Sub_Unit_ptr[0]->Buff_check["Two_Erudition"]==1){
                Increase_mtpr*=2;
            }
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,40+Increase_mtpr*8,5),
                DmgSrc(DmgSrcType::ATK,40+Increase_mtpr*4,5),
                DmgSrc(DmgSrcType::ATK,40+Increase_mtpr*4,5)
            );
            ptr->Sub_Unit_ptr[0]->Buff_note["The_Herta_Skill_Enchance"]--;

            Enemy_unit[Main_Enemy_num]->Debuff["Herta_Stack"] = 1;
            if(ptr->Eidolon>=1){
                Enemy_unit[Main_Enemy_num]->Debuff["Herta_Stack"] = 15;
            }
            Herta_reset_Stack();

            Apply_Herta_Stack(ptr,Enemy_unit[Main_Enemy_num].get(),1);
            ptr->getSubUnit()->buffSingle({{ST_DMG,AT_NONE,50}});
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,80,5));
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,80,5),
            DmgSrc(DmgSrcType::ATK,80,5)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,80,5),
            DmgSrc(DmgSrcType::ATK,80,5),
            DmgSrc(DmgSrcType::ATK,80,5)
        );
        act->addToActionBar();
    }

    
    void Herta_reset_Stack(){
        vector<int> vec;
        for(int i=1;i<=Total_enemy;i++){
            vec.push_back(Enemy_unit[i]->Debuff["Herta_Stack"]);
        }
        sort(vec.begin(),vec.end(),greater<int>());
        for(int i=1;i<=Total_enemy;i++){
            Enemy_unit[i]->Debuff["Herta_Stack"] = vec[i-1];
        }
        
    }
    void Apply_Herta_Stack(Ally* ptr ,Enemy* target,int Stack){
        if(ptr->Sub_Unit_ptr[0]->Stack["The_Herta_A6"]+Stack>99){
            ptr->Sub_Unit_ptr[0]->Stack["The_Herta_A6"] = 99;
        }else{
            ptr->Sub_Unit_ptr[0]->Stack["The_Herta_A6"]+=Stack;
        }
        if(target->Debuff["Herta_Stack"]==42){
            for(int i=1;i<=Total_enemy;i++){
                if(Enemy_unit[i]->Debuff["Herta_Stack"]<42){
                    if(Enemy_unit[i]->Debuff["Herta_Stack"]+Stack>42){
                        Enemy_unit[i]->Debuff["Herta_Stack"] = 42;
                    }else{
                        Enemy_unit[i]->Debuff["Herta_Stack"] += Stack;
                    }               
                    return;     
                }
            }
            return;
        }
        if(target->Debuff["Herta_Stack"]+Stack>42){
            target->Debuff["Herta_Stack"] = 42;
        }else{
            target->Debuff["Herta_Stack"] += Stack;
        }
    }
}