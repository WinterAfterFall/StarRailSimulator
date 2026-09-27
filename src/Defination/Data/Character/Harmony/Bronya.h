#include "../include.h"

namespace Bronya{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    

//temp
    void skill(CharUnit *ptr);

    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(99,120,120,eidolon,ElementType::WIND,Path::HARMONY,"Bronya",UnitType::STANDARD);
        AllyUnit *bronyaPtr = ptr;
        ptr->setAllyBaseStats(1242,582,534);
        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->setTotalSubstats(25);
        ptr->setRelicMainStats(Stats::CD,Stats::FLAT_SPD,Stats::DMG,Stats::ER);
        ptr->setSpeedRequire(134);

        driverNum = bronyaPtr->atvStats->num;

        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->turnFunc = [ptr](){            
            skill(ptr);
        };

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [bronyaPtr](CharUnit *ptr){
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::ULT,ptr,TraceType::AOE,"Bronya Ult",
            [ptr](shared_ptr<AllyBuffAction> &act){
                //Ult ATKBUFF
                buffAllAlly({{Stats::ATK_P,AType::NONE,55}},"Bronya_Ult",2);

                //Ult CritBuff
                double temp = calculateCritdamForBuff(ptr,16)+20;
                for(auto &e : act->buffTargetList){
                    buffSingle(e,{{Stats::CD,AType::NONE,temp - e->buffNote["Bronya_Ult"]}});
                    buffSingle(e,{{Stats::CD,AType::TEMP,temp - e->buffNote["Bronya_Ult"]}});
                    e->buffNote["Bronya_Ult"] = temp;
                }

                //ดักในกรณีที่บัพในเทิร์นตัวละครอื่น
                if(phaseStatus == PhaseStatus::BEFORE_TURN && (turn->side == Side::MEMOSPRITE || turn->side == Side::ALLY)){
                    AllyUnit *temp = dynamic_cast<AllyUnit*>(turn->charptr);
                    extendBuffTime(temp,"Bronya_Ult",1);
                }
                if(ptr->print)CharCmd::printUltStart("Bronya");
            });
            act->addBuffAllAllies();
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr){
            ptr->statsType[Stats::CD][AType::NONE] += 24;
            ptr->statsType[Stats::RES][AType::NONE] += 10;
            ptr->statsEachElement[Stats::DMG][ElementType::WIND][AType::NONE] += 22.4;
            // substats
            ptr->statsType[Stats::CR][AType::BA] = 100;
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [bronyaPtr](CharUnit *ptr){
            if(ptr->technique == 1)buffAllAlly({{Stats::ATK_P,AType::NONE,15}},"Bronya_Technique",2);
            buffAllAlly({{Stats::DEF_P,AType::NONE,20}},"Bronya_A4",2);
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [bronyaPtr](CharUnit *ptr){
            AllyUnit *tempstats = dynamic_cast<AllyUnit*>(turn->charptr);
            if(!tempstats) return;
            
            //BuffEND Skill
            if(isBuffEnd(tempstats,"Bronya_Skill")){
                buffSingle(tempstats,{{Stats::DMG,AType::NONE,-66}});
            }

            //E1 Cooldon reset
            if(isBuffEnd(bronyaPtr,"Bronya_Skill_E1")){
                ptr->stack["Bronya_Skill_E1"] = 0;
            }
             //E2 buffend
            if(isBuffEnd(tempstats,"Bronya_Skill_E2")){
                buffSingle(tempstats,{{Stats::SPD_P,AType::NONE,-30}});
            }
            if(isBuffEnd(tempstats,"Bronya_Ult")){
                buffSingle(tempstats,{{Stats::ATK_P,AType::NONE,-55}});
                buffSingle(tempstats,{{Stats::CD,AType::TEMP,-tempstats->buffNote["Bronya_Ult"]}});
                buffSingle(tempstats,{{Stats::CD,AType::NONE,-tempstats->buffNote["Bronya_Ult"]}});
                tempstats->buffNote["Bronya_Ult"] = 0;
            }
            if(isBuffEnd(tempstats,"Bronya_A4")){
                buffSingle(tempstats,{{Stats::DEF_P,AType::NONE,-20}});
            }
            if(isBuffEnd(tempstats,"Bronya_Technique")){
                buffSingle(tempstats,{{Stats::ATK_P,AType::NONE,-15}});
            }
        }));

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr){
            if(turn->name == "Bronya"){
                ptr->buffCheck["Bronya_E4"] = 0;
            }
            if(ptr->atvStats->num != driverNum) return;
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr){
            buffAllAlly({{Stats::DMG,AType::NONE,10}});
        }));

        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act){
            if(act->isSameAction("Bronya",AType::BA)){
                actionForward(ptr->atvStats.get(),30);
            }
            if(ptr->eidolon >= 4 && act->isSameAction(AType::BA)&&!act->isSameName("Bronya")&& ptr->buffCheck["Bronya_E4"] == 0){
                shared_ptr<AllyAttackAction> newAct = 
                make_shared<AllyAttackAction>(AType::FUA,ptr,TraceType::SINGLE,"Bronya E4",
                [ptr](shared_ptr<AllyAttackAction> &act){
                    increaseEnergy(ptr,5);
                    attack(act);
                });
                newAct->addDamageIns(DmgSrc(DmgSrcType::ATK,80,10));
                ptr->buffCheck["Bronya_E4"] = 1;
                newAct->addToActionBar();
            }
        }));



        
    }


    
    void skill(CharUnit *ptr){

        genSkillPoint(ptr,-1);
        //E1 คืน Sp
        if(ptr->eidolon>=1){
            if(ptr->stack["Bronya_Skill_E1"]==1&&isHaveToAddBuff(ptr,"Bronya_Skill_E1",1)){
                genSkillPoint(ptr,1);
                
            }
            ptr->stack["Bronya_Skill_E1"]++;
        }
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::SINGLE,"Bronya Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            increaseEnergy(ptr,30);

            //Buff นานแค่ไหน
            if(ptr->eidolon>=6)
            buffSingle(chooseAllyBuff(ptr),{{Stats::DMG,AType::NONE,66}},"Bronya_Skill",2);
            else
            buffSingle(chooseAllyBuff(ptr),{{Stats::DMG,AType::NONE,66}},"Bronya_Skill",1);

            actionForward(chooseAllyBuff(ptr)->atvStats.get(),100);

            //E2 buff Speed
            if(ptr->eidolon>=2)
            buffSingle(chooseAllyBuff(ptr),{{Stats::SPD_P,AType::NONE,30}},"Bronya_Skill_E2",1  );
            

        });
        act->addBuffSingleTarget(chooseAllyBuff(ptr));
        act->addToActionBar();
    }
}