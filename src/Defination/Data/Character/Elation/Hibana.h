#include "../include.h"

namespace Hibana{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(107,160,160,E,ElementType::Fire,Path::Elation,"Hibana",UnitType::Standard);
        ptr->SetAllyBaseStats(1051,640,460);

        //substats
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::CD);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(134);
        ptr->setAtkRequire(3600);
        ptr->setRelicMainStats(Stats::CR,Stats::FLAT_SPD,Stats::ATK_P,Stats::ATK_P);

        
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);

        #pragma region Ability

        function<void()> BA = [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"Hibana BA",
            [ptr](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,1);
                Increase_energy(ptr,20);
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> EBA = [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Blast,"Hibana EBA",
            [ptr](shared_ptr<AllyAttackAction> &act){
                int skillCharge = 0;
                while(sp){
                    if(ptr->getStack("Hbn Thrill")){
                        ptr->addStack("Hbn Thrill",-1);
                        if(ptr->Eidolon>=2){
                            buffStackSingle(ptr,{{Stats::CD,AType::None,10}},1,4,"Hbn E2",2);
                        }
                        allEventSkillPoint(ptr,-1);
                    }
                    else genSkillPoint(ptr,-1);
                    skillCharge++;
                    ptr->addStack("Hibana Skill Count",1);
                    if(ptr->Stack["Hibana Skill Count"]%6==3){
                        genSkillPoint(ptr,2);   
                        genPunchLine(ptr,2);
                    }
                    else genPunchLine(ptr,1);
                }
                act->multiplyDmg(100 + 20*skillCharge);
                
                genSkillPoint(ptr,1);
                Increase_energy(ptr,40);
                Attack(act);
                shared_ptr<AllyAttackAction> elDmg = make_shared<AllyAttackAction>(AType::ElationDMG,ptr,TraceType::Blast,"Hbn EBA Elation");
                elDmg->addDamageIns(
                    DmgSrc(DmgSrcType::Elation,40),
                    DmgSrc(DmgSrcType::Elation,20)
                );
                elDmg->addEnemyBounce(DmgSrc(DmgSrcType::Elation,20),skillCharge);
                Attack(elDmg);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10),
                DmgSrc(DmgSrcType::ATK,50,5)
            );
            act->addToActionBar();
        };

        #pragma endregion
        ptr->Turn_func = [ptr,BA,EBA]() {
            if(sp + ptr->getStack("Hbn Thrill") >=3)EBA();
            else BA();
        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (!ultUseCheck(ptr)) return;
            CharCmd::printUltStart("Hibana");
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::Ult,ptr,TraceType::Aoe,"Hibana Ult",
            [ptr](shared_ptr<AllyAttackAction> &act){

                ptr->addStack("Hbn Thrill",1);
                if(elationCount==1)genPunchLine(ptr,2+2);
                else if(elationCount==2)genPunchLine(ptr,2+4);
                else{
                    genPunchLine(ptr,2+8);
                    ptr->addStack("Hbn Thrill",3);
                }
                if(ptr->Eidolon>=4){
                    genPunchLine(ptr,5);
                    buffSingle(ptr,{{Stats::Elation,AType::None,36}},"Hbn E4",3);
                }


                Attack(act);
                shared_ptr<AllyAttackAction> elDmg = make_shared<AllyAttackAction>(AType::ElationDMG,ptr,TraceType::Aoe,"Hbn Ult Elation");
                elDmg->addDamageIns(
                    DmgSrc(DmgSrcType::Elation,48),
                    DmgSrc(DmgSrcType::Elation,48),
                    DmgSrc(DmgSrcType::Elation,48)
                );
                Attack(elDmg);
            });
            double mtpr = 0.6 * calculateElationOnStats(ptr) + 50;
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,mtpr,20),
                DmgSrc(DmgSrcType::ATK,mtpr,20),
                DmgSrc(DmgSrcType::ATK,mtpr,20)
            );
            act->addToActionBar();
            Deal_damage();
        }));

        ElationSkill_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::ElationSkill,ptr,TraceType::Aoe,"Hbn Elation",
            [ptr](shared_ptr<AllyAttackAction> &act){
                ptr->addStack("Hbn Thrill",2);
                Increase_energy(ptr,5);    
                Attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::Elation,50),
                DmgSrc(DmgSrcType::Elation,50),
                DmgSrc(DmgSrcType::Elation,50)
            );
            act->addEnemyBounce(
                DmgSrc(DmgSrcType::Elation,25),20
            );

            if(ptr->Eidolon>=6)act->addEnemyBounce(DmgSrc(DmgSrcType::Elation,25),min(punchline,40));
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::Elation][AType::None] += 28;
            ptr->Stats_type[Stats::CR][AType::None] += 12;
            ptr->Stats_type[Stats::CD][AType::None] += 13.3;

            ptr->Stats_type[Stats::Elation][AType::None] += 80;

            if(ptr->Eidolon>=6)ptr->Stats_type[Stats::RESPEN][AType::None] += 20;

        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,BA,EBA]() {
            if(isBuffEnd(ptr,"Hbn E2")){
            buffResetStack(ptr,{{Stats::CD,AType::None,10}},"Hbn E2");
            }
            if(isBuffEnd(ptr,"Hbn E4")){
            buffSingle(ptr,{{Stats::Elation,AType::None,-36}});
            }
        }));



        PunchLine_List.push_back(TriggerSkill_point_func(PRIORITY_IMMEDIATELY, [ptr](AllyUnit *SP_maker, int SP) {
            int buff = max(0,min(10,punchline));
            buffAllAlly({
                {Stats::CD,AType::TEMP,buff*8 - ptr->Buff_note["Hbn Buff"]},
                {Stats::CD,AType::None,buff*8 - ptr->Buff_note["Hbn Buff"]}
            });
            ptr->setBuffNote("Hbn Buff",buff*8);
            if(ptr->Eidolon<1)return;
            buffAllAlly({
                {Stats::RESPEN,AType::TEMP,buff*1.5 - ptr->Buff_note["Hbn E1"]},
                {Stats::RESPEN,AType::None,buff*1.5 - ptr->Buff_note["Hbn E1"]}
            });
            ptr->setBuffNote("Hbn E1",buff*1.5);
        }));

        
        AfterAhaInstant_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,BA,EBA]() {
            if(ptr->Eidolon>=1)genPunchLine(ptr,1);

            if(ptr->Eidolon>=2){
                if(sp + ptr->getStack("Hbn Thrill") >=3)EBA();
                else BA();
                Deal_damage();
            }
        }));

    }
}
