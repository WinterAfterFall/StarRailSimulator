
#include "../include.h"

namespace The_Herta{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
//temp
    void Basic_Atk(CharUnit *ptr);
    void Skill(CharUnit *ptr);
    void Enchance_Skill(CharUnit *ptr);
    void Apply_Herta_Stack(CharUnit* ptr ,Enemy* target,int Stack);
    void Herta_reset_Stack();
    bool Enchance_Skill_Condition(CharUnit *ptr);


    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(99,220,220,E,ElementType::Ice,Path::Erudition,"The_Herta",UnitType::Standard);
        AllyUnit* Hertaptr = ptr;
        ptr->SetAllyBaseStats(1164,679,485);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(20);
        ptr->setRelicMainStats(Stats::CR,Stats::ATK_P,Stats::DMG,Stats::ATK_P);



        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        ptr->Turn_func = [ptr, allyPtr = ptr]() {

            if (Enchance_Skill_Condition(ptr)) {
                return;
            } else if (sp > Sp_Safety || spMode == SPMode::Positive) {
                Skill(ptr);
            } else {
                Basic_Atk(ptr);
            }
        };

        ptr->addUltCondition([ptr]() -> bool {
            if ((ptr->Atv_stats->atv < ptr->Atv_stats->Max_atv * 0.2)) return false;
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr,Hertaptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr,TraceType::Aoe,"THerta Ult",
            [ptr,Hertaptr](shared_ptr<AllyAttackAction> &act){
                double Increase_mtpr = ptr->Stack["The_Herta_A6"];
                act->addDamage(DmgSrcType::ATK,Increase_mtpr);
                ptr->Buff_note["The_Herta_Skill_Enchance"]++;
                if (ptr->Eidolon >= 2) {
                    ptr->Buff_note["The_Herta_Skill_Enchance"]++;
                }
                buffSingle(Hertaptr,{{Stats::ATK_P,AType::None,80}},"Ult_The_Herta_Buff",3);

                if (ptr->Print)CharCmd::printUltStart("The Herta");
                Attack(act);

                Action_forward(ptr->Atv_stats.get(), 100);
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
            ptr->Stats_type[Stats::ATK_P][AType::None] += 18;
            ptr->Stats_each_element[Stats::DMG][ElementType::Ice][AType::None] += 22.4;
            ptr->Atv_stats->flatSpeed += 5;

            // relic

            // substats
            int cnt = 0;
            for (int i = 1; i <= Total_ally; i++) {
                for (auto e : charUnit[i]->path) {
                    if (e == Path::Erudition) cnt++;
                }
                if (cnt >= 2) {
                    ptr->Buff_check["Two_Erudition"] = 1;
                    break;
                }
            }
        }));


        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Hertaptr]() {
            if (ptr->Technique == 1) {
                buffSingle(Hertaptr,{{Stats::ATK_P,AType::None,60}},"The_Herta_Technique",2);
            }
            Apply_Herta_Stack(ptr, enemyUnit[Main_Enemy_num].get(), 25);
            for (int i = 1; i <= Total_enemy; i++) {
                Apply_Herta_Stack(ptr, enemyUnit[i].get(), 1);
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,Hertaptr]() {
            if (isBuffEnd(Hertaptr,"The_Herta_Technique")) {
                buffSingle(Hertaptr,{{Stats::ATK_P,AType::None,-60}});
            }
            if (isBuffEnd(Hertaptr,"Ult_The_Herta_Buff")) {
                buffSingle(Hertaptr,{{Stats::ATK_P,AType::None,-80}});
            }
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Buff_check["Two_Erudition"] == 1) {
                buffAllAlly({{Stats::CD,AType::None,80}});
            }
        }));

        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_BUFF, [ptr,Hertaptr](shared_ptr<AllyAttackAction> &act){
            if(act->actionName=="THerta ESkill"){
                buffSingle(Hertaptr,{{Stats::DMG,AType::None,-50}});
                if(ptr->Eidolon >= 2)Action_forward(ptr->Atv_stats.get(),35);
            }
            bool Erudition_check = 0;

            for(auto e : act->Attacker->owner->path){
                if(e == Path::Erudition) Erudition_check = 1;
            }
            for(auto e : act->targetList){
                Apply_Herta_Stack(ptr, e, 1);
            }
            if(Erudition_check){
                Apply_Herta_Stack(ptr, enemyUnit[Main_Enemy_num].get(), 3);
            } else {
                Apply_Herta_Stack(ptr, enemyUnit[Main_Enemy_num].get(), 1);
            }
            int energy_gen = act->targetList.size();
            if(energy_gen < 9) energy_gen = 9;
            Increase_energy(ptr, 0, energy_gen);
        }));

        Enemy_Death_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, AllyUnit *Killer) {
            Apply_Herta_Stack(ptr, enemyUnit[Main_Enemy_num].get(), 1);
        }));


        
    }
    

    bool Stack_Herta_Check(CharUnit *ptr){
        int temp = enemyUnit[Main_Enemy_num]->Debuff["Herta_Stack"];
        if(ptr->Eidolon>=1){
            int mx = -1;
            for(int i=1;i<=Total_enemy;i++){
                if(i==Main_Enemy_num)continue;
                mx = max(mx,enemyUnit[i]->Debuff["Herta_Stack"]);
            }
            temp+=mx;

        }
        if(temp>=42)return true;
        
        return true;
    }
    bool Enchance_Skill_Condition(CharUnit *ptr){
        if(ptr->Eidolon>=2&&driverType==DriverType::DoubleTurn&&charUnit[Driver_num]->Atv_stats->Max_atv < ptr->Atv_stats->Max_atv&&ptr->Atv_stats->Max_atv*0.65<charUnit[Driver_num]->Atv_stats->atv){
            if(ptr->Current_energy>=190&&(CharCmd::Using_Skill(ptr)||ptr->Current_energy<200)){
                if(ptr->Buff_note["The_Herta_Skill_Enchance"]>0){
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
        if(ptr->Buff_note["The_Herta_Skill_Enchance"]>0){
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

    void Basic_Atk(CharUnit *ptr){
        Skill_point(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"THerta BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,20);
            Attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,100,10));
        act->addToActionBar();
    }

    void Skill(CharUnit *ptr){
        Skill_point(ptr,-1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Blast,"THerta Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,30);
            Apply_Herta_Stack(ptr,enemyUnit[Main_Enemy_num].get(),1);
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

    void Enchance_Skill(CharUnit *ptr){
        Skill_point(ptr,-1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Aoe,"THerta ESkill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,30);
            double Increase_mtpr = enemyUnit[Main_Enemy_num]->Debuff["Herta_Stack"];
            double mx =-1;
            if(ptr->Eidolon>=1){
                for(int i=2;i<=Total_enemy;i++){
                if(enemyUnit[i]->Debuff["Herta_Stack"]>mx){
                    mx = enemyUnit[i]->Debuff["Herta_Stack"];
                }
                }
                Increase_mtpr+=(0.5*mx);
            }
            
            if(ptr->Buff_check["Two_Erudition"]==1){
                Increase_mtpr*=2;
            }
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,40+Increase_mtpr*8,5),
                DmgSrc(DmgSrcType::ATK,40+Increase_mtpr*4,5),
                DmgSrc(DmgSrcType::ATK,40+Increase_mtpr*4,5)
            );
            ptr->Buff_note["The_Herta_Skill_Enchance"]--;

            enemyUnit[Main_Enemy_num]->Debuff["Herta_Stack"] = 1;
            if(ptr->Eidolon>=1){
                enemyUnit[Main_Enemy_num]->Debuff["Herta_Stack"] = 15;
            }
            Herta_reset_Stack();

            Apply_Herta_Stack(ptr,enemyUnit[Main_Enemy_num].get(),1);
            buffSingle(ptr,{{Stats::DMG,AType::None,50}});
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
            vec.push_back(enemyUnit[i]->Debuff["Herta_Stack"]);
        }
        sort(vec.begin(),vec.end(),greater<int>());
        for(int i=1;i<=Total_enemy;i++){
            enemyUnit[i]->Debuff["Herta_Stack"] = vec[i-1];
        }
        
    }
    void Apply_Herta_Stack(CharUnit* ptr ,Enemy* target,int Stack){
        if(ptr->Stack["The_Herta_A6"]+Stack>99){
            ptr->Stack["The_Herta_A6"] = 99;
        }else{
            ptr->Stack["The_Herta_A6"]+=Stack;
        }
        if(target->Debuff["Herta_Stack"]==42){
            for(int i=1;i<=Total_enemy;i++){
                if(enemyUnit[i]->Debuff["Herta_Stack"]<42){
                    if(enemyUnit[i]->Debuff["Herta_Stack"]+Stack>42){
                        enemyUnit[i]->Debuff["Herta_Stack"] = 42;
                    }else{
                        enemyUnit[i]->Debuff["Herta_Stack"] += Stack;
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