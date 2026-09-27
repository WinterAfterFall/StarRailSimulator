
#include "../include.h"

namespace TheHerta{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
//temp
    void basicAtk(CharUnit *ptr);
    void skill(CharUnit *ptr);
    void enchanceSkill(CharUnit *ptr);
    void applyHertaStack(CharUnit* ptr ,Enemy* target,int stack);
    void hertaResetStack();
    bool enchanceSkillCondition(CharUnit *ptr);


    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(99,220,220,eidolon,ElementType::ICE,Path::ERUDITION,"The_Herta",UnitType::STANDARD);
        AllyUnit* hertaPtr = ptr;
        ptr->setAllyBaseStats(1164,679,485);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setRelicMainStats(Stats::CR,Stats::ATK_P,Stats::DMG,Stats::ATK_P);


        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        ptr->turnFunc = [ptr, allyPtr = ptr]() {

            if (enchanceSkillCondition(ptr)) {
                return;
            } else if (sp > spSafety || spMode == SPMode::POSITIVE) {
                skill(ptr);
            } else {
                basicAtk(ptr);
            }
        };

        ptr->addUltCondition([ptr]() -> bool {
            if ((ptr->atvStats->atv < ptr->atvStats->maxAtv * 0.2)) return false;
            return true;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_ACTTACK, ptr, [hertaPtr](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"THerta Ult",
            [ptr,hertaPtr](shared_ptr<AllyAttackAction> &act){
                double increaseMtpr = ptr->stack["The_Herta_A6"];
                act->addDamage(DmgSrcType::ATK,increaseMtpr);
                ptr->buffNote["The_Herta_Skill_Enchance"]++;
                if (ptr->eidolon >= 2) {
                    ptr->buffNote["The_Herta_Skill_Enchance"]++;
                }
                buffSingle(hertaPtr,{{Stats::ATK_P,AType::NONE,80}},"Ult_The_Herta_Buff",3);

                if (ptr->print)CharCmd::printUltStart("The Herta");
                attack(act);

                actionForward(ptr->atvStats.get(), 100);
                hertaResetStack();
            });
            act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,200,20),
                    DmgSrc(DmgSrcType::ATK,200,20),
                    DmgSrc(DmgSrcType::ATK,200,20)
            );
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::ATK_P][AType::NONE] += 18;
            ptr->statsEachElement[Stats::DMG][ElementType::ICE][AType::NONE] += 22.4;
            ptr->atvStats->flatSpeed += 5;

            // relic

            // substats
            int cnt = 0;
            for (int i = 1; i <= totalAlly; i++) {
                if (charUnit[i]->path == Path::ERUDITION) cnt++;
                if (cnt >= 2) {
                    ptr->buffCheck["Two_Erudition"] = 1;
                    break;
                }
            }
        }));


        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [hertaPtr](CharUnit *ptr) {
            if (ptr->technique == 1) {
                buffSingle(hertaPtr,{{Stats::ATK_P,AType::NONE,60}},"The_Herta_Technique",2);
            }
            applyHertaStack(ptr, enemyUnit[mainEnemyNum].get(), 25);
            for (int i = 1; i <= totalEnemy; i++) {
                applyHertaStack(ptr, enemyUnit[i].get(), 1);
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [hertaPtr](CharUnit *ptr) {
            if (isBuffEnd(hertaPtr,"The_Herta_Technique")) {
                buffSingle(hertaPtr,{{Stats::ATK_P,AType::NONE,-60}});
            }
            if (isBuffEnd(hertaPtr,"Ult_The_Herta_Buff")) {
                buffSingle(hertaPtr,{{Stats::ATK_P,AType::NONE,-80}});
            }
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if (ptr->buffCheck["Two_Erudition"] == 1) {
                buffAllAlly({{Stats::CD,AType::NONE,80}});
            }
        }));

        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_BUFF, [ptr,hertaPtr](shared_ptr<AllyAttackAction> &act){
            if(act->actionName=="THerta ESkill"){
                buffSingle(hertaPtr,{{Stats::DMG,AType::NONE,-50}});
                if(ptr->eidolon >= 2)actionForward(ptr->atvStats.get(),35);
            }
            bool eruditionCheck = act->attacker->owner->path == Path::ERUDITION;
            for(auto e : act->targetList){
                applyHertaStack(ptr, e, 1);
            }
            if(eruditionCheck){
                applyHertaStack(ptr, enemyUnit[mainEnemyNum].get(), 3);
            } else {
                applyHertaStack(ptr, enemyUnit[mainEnemyNum].get(), 1);
            }
            // A2: energy คงที่ 3 ต่อเป้าหมายที่โดน นับสูงสุด 5 เป้า
            // A4 (ทีมมี Erudition >= 2): นับอย่างน้อย 3 เป้า
            int targetCnt = act->targetList.size();
            if(ptr->buffCheck["Two_Erudition"] == 1 && targetCnt < 3) targetCnt = 3;
            if(targetCnt > 5) targetCnt = 5;
            increaseEnergy(ptr, 0, 3 * targetCnt);
        }));

        enemyDeathList.push_back(TriggerBySomeAllyFunc(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, AllyUnit *killer) {
            applyHertaStack(ptr, enemyUnit[mainEnemyNum].get(), 1);
        }));


        
    }
    

    // Interpretation ที่ Enhanced Skill จะนับได้จริง ถึงเกณฑ์ A2 (42) หรือยัง
    // ต้องนับแบบเดียวกับที่ enchanceSkill คำนวณ multiplier (E1 = +50% ของ stack สูงสุดตัวอื่น)
    bool stackHertaCheck(CharUnit *ptr){
        double temp = enemyUnit[mainEnemyNum]->debuffCheck["Herta_Stack"];
        if(ptr->eidolon>=1){
            double mx = 0;
            for(int i=1;i<=totalEnemy;i++){
                if(i==mainEnemyNum)continue;
                mx = max(mx,(double)enemyUnit[i]->debuffCheck["Herta_Stack"]);
            }
            temp+=0.5*mx;
        }
        if(temp>=42)return true;
        
        return false;
    }
    bool enchanceSkillCondition(CharUnit *ptr){
        if(ptr->eidolon>=2&&driverType==DriverType::DOUBLE_TURN&&charUnit[driverNum]->atvStats->maxAtv < ptr->atvStats->maxAtv&&ptr->atvStats->maxAtv*0.65<charUnit[driverNum]->atvStats->atv){
            if(ptr->currentEnergy>=190&&(CharCmd::usingSkill(ptr)||ptr->currentEnergy<200)){
                if(ptr->buffNote["The_Herta_Skill_Enchance"]>0){
                    enchanceSkill(ptr);
                }else{
                    skill(ptr);  
                }
                return true;
            }else if(ptr->currentEnergy>=200){
                basicAtk(ptr);
                return true;
            }else{
                enchanceSkill(ptr);
                return true;
            }
            
        }
        if(ptr->buffNote["The_Herta_Skill_Enchance"]>0){
            // คุ้มที่จะปล่อย Enhanced Skill ตอนนี้ไหม: SP พอ + stack ถึงเกณฑ์ A2
            // ยังไม่ถึง -> กด Basic ATK รอสะสม stack ต่อ (เก็บ Inspiration ไว้)
            if(CharCmd::usingSkill(ptr)&&stackHertaCheck(ptr)){
                enchanceSkill(ptr);
            }else{
                basicAtk(ptr);
            }
            return true;
        }
        return false;
    }

    void basicAtk(CharUnit *ptr){
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"THerta BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,20);
            attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,100,10));
        act->addToActionBar();
    }

    void skill(CharUnit *ptr){
        genSkillPoint(ptr,-1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BLAST,"THerta Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,30);
            applyHertaStack(ptr,enemyUnit[mainEnemyNum].get(),1);
            attack(act);
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

    void enchanceSkill(CharUnit *ptr){
        genSkillPoint(ptr,-1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::AOE,"THerta ESkill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,30);
            double increaseMtpr = enemyUnit[mainEnemyNum]->debuffCheck["Herta_Stack"];
            double mx =-1;
            if(ptr->eidolon>=1){
                for(int i=2;i<=totalEnemy;i++){
                if(enemyUnit[i]->debuffCheck["Herta_Stack"]>mx){
                    mx = enemyUnit[i]->debuffCheck["Herta_Stack"];
                }
                }
                increaseMtpr+=(0.5*mx);
            }
            
            if(ptr->buffCheck["Two_Erudition"]==1){
                increaseMtpr*=2;
            }
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,40+increaseMtpr*8,5),
                DmgSrc(DmgSrcType::ATK,40+increaseMtpr*4,5),
                DmgSrc(DmgSrcType::ATK,40+increaseMtpr*4,5)
            );
            ptr->buffNote["The_Herta_Skill_Enchance"]--;

            enemyUnit[mainEnemyNum]->debuffCheck["Herta_Stack"] = 1;
            if(ptr->eidolon>=1){
                enemyUnit[mainEnemyNum]->debuffCheck["Herta_Stack"] = 15;
            }
            hertaResetStack();

            applyHertaStack(ptr,enemyUnit[mainEnemyNum].get(),1);
            buffSingle(ptr,{{Stats::DMG,AType::NONE,50}});
            attack(act);
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

    
    void hertaResetStack(){
        vector<int> vec;
        for(int i=1;i<=totalEnemy;i++){
            vec.push_back(enemyUnit[i]->debuffCheck["Herta_Stack"]);
        }
        sort(vec.begin(),vec.end(),greater<int>());
        for(int i=1;i<=totalEnemy;i++){
            enemyUnit[i]->debuffCheck["Herta_Stack"] = vec[i-1];
        }
        
    }
    void applyHertaStack(CharUnit* ptr ,Enemy* target,int stack){
        if(ptr->stack["The_Herta_A6"]+stack>99){
            ptr->stack["The_Herta_A6"] = 99;
        }else{
            ptr->stack["The_Herta_A6"]+=stack;
        }
        if(target->debuffCheck["Herta_Stack"]==42){
            for(int i=1;i<=totalEnemy;i++){
                if(enemyUnit[i]->debuffCheck["Herta_Stack"]<42){
                    if(enemyUnit[i]->debuffCheck["Herta_Stack"]+stack>42){
                        enemyUnit[i]->debuffCheck["Herta_Stack"] = 42;
                    }else{
                        enemyUnit[i]->debuffCheck["Herta_Stack"] += stack;
                    }               
                    return;     
                }
            }
            return;
        }
        if(target->debuffCheck["Herta_Stack"]+stack>42){
            target->debuffCheck["Herta_Stack"] = 42;
        }else{
            target->debuffCheck["Herta_Stack"] += stack;
        }
    }
}