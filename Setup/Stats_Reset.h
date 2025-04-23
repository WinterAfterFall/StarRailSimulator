#ifndef Setup_Stats_H
#define Setup_Stats_H
#include "../Class/Trigger_Function.h"

void Basic_reset(){
    
    for(int i=1;i<=Total_ally;i++){
        
        //flat atk
        for(auto &e1:Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type){
            for(auto &e2:e1.second){
                e2.second = 0;
            }

        }
        for(auto &e1:Ally_unit[i]->Sub_Unit_ptr[0]->Stats_each_element){
            for(auto &e2:e1.second){
                for(auto &e3:e2.second){
                    e3.second = 0;
                }
                
            }

        }
        
        
        //ally edit
            Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed = 0;
            Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Speed_percent = 0;
            Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->turn_cnt = 0;
            Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->priority = 0;
            Ally_unit[i]->Energy_recharge = 100;
            Ally_unit[i]->Current_energy = Ally_unit[i]->Max_energy/2;
            Ally_unit[i]->Sub_Unit_ptr[0]->currentAllyTargetNum = Ally_unit[i]->Sub_Unit_ptr[0]->defaultAllyTargetNum;
            Ally_unit[i]->Sub_Unit_ptr[0]->currentSubUnitTargetNum = Ally_unit[i]->Sub_Unit_ptr[0]->defaultSubUnitTargetNum;
            Ally_unit[i]->Sub_Unit_ptr[0]->tauntMtpr = 100;
            Ally_unit[i]->Sub_Unit_ptr[0]->taunt = Ally_unit[i]->Sub_Unit_ptr[0]->tauntBase;
            Ally_unit[i]->Sub_Unit_ptr[0]->currentSheild = 0;
            
            for(auto &e:Ally_unit[i]->Sub_Unit_ptr[0]->Stack){
                e.second = 0;
            }
            for(auto &e:Ally_unit[i]->Sub_Unit_ptr[0]->Buff_countdown){
                e.second = 0;
            }
            for(auto &e:Ally_unit[i]->Sub_Unit_ptr[0]->Buff_note){
                e.second = 0;
            }
            for(auto &e:Ally_unit[i]->Sub_Unit_ptr[0]->Buff_check){
                e.second = 0;
            }
            for(std::pair<const std::string, SubUnit *> &e : Ally_unit[i]->Sub_Unit_ptr[0]->buffSubUnitTarget){
                e.second = nullptr;
            }
            for(std::pair<const std::string, Ally *> &e : Ally_unit[i]->Sub_Unit_ptr[0]->buffAllyTarget){
                e.second = nullptr;
            }
            for(std::pair<const std::string, double> &e :Ally_unit[i]->damageAvgNote){
                e.second = 0;
            }
            for(std::pair<const std::string, double> &e :Ally_unit[i]->damageRealTimeNote){
                e.second = 0;
            }
            Ally_unit[i]->totalRealTimeDamage = 0;
            for(double &e : Ally_unit[i]->totalAvgToughnessDamage){
                e = 0;
            }
            Ally_unit[i]->totalDamage = 0;
            Ally_unit[i]->Average_Damage = 0;
            Ally_unit[i]->averageDamageInstance.clear();
            Ally_unit[i]->Last_note = 0;
            
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type["Atk%"][AT_NONE] += 3.888*2;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type["Flat_Atk"][AT_NONE] += 352.8+38;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type["Hp%"][AT_NONE] += 3.888*2;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type["Flat_Hp"][AT_NONE] += 76+705.6;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type["Def%"][AT_NONE] += 4.86*2;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 5+2.9*2;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE] += 50+5.8*2;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE] += 5.8*2;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type["Effect_hit_rate"][AT_NONE] += 3.888*2;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type["True_Damage"][AT_NONE] += 0;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type[ST_HEALING_OUT][AT_NONE] += 0;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type[ST_RES][AT_NONE] += 4.32*2;
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type["Ehr"][AT_NONE] += 3.888*2;
            Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 2.3*2;


            Ally_unit[i]->Body(Ally_unit[i].get());
            Ally_unit[i]->Boot(Ally_unit[i].get());
            Ally_unit[i]->Orb(Ally_unit[i].get());
            Ally_unit[i]->Rope(Ally_unit[i].get());
            Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type["Ehr"][AT_NONE] += Ally_unit[i]->ExtraEhr;
            Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += Ally_unit[i]->ExtraSpeed;
    }



        //enemy edit
        for(int i=1;i<=Total_enemy;i++){
            for(auto &e1:Enemy_unit[i]->Stats_type){
                for(auto &e2:e1.second){
                    e2.second = 0;
                }

            }
            for(auto &e1:Enemy_unit[i]->Stats_each_element){
                for(auto &e2:e1.second){
                    for(auto &e3:e2.second){
                        e3.second = 0;
                    }
                
                }

        }
            Enemy_unit[i]->Atv_stats->Flat_Speed = 0;
            Enemy_unit[i]->Atv_stats->Speed_percent = 0;
            Enemy_unit[i]->Atv_stats->turn_cnt = 0;
            Enemy_unit[i]->Atv_stats->priority = 0;
            Enemy_unit[i]->Toughness_status=1;
            Enemy_unit[i]->Current_toughness=Enemy_unit[i]->Max_toughness;
            Enemy_unit[i]->Total_debuff=0;
            Enemy_unit[i]->target=nullptr;
            Enemy_unit[i]->atkPercent = 0;
            Enemy_unit[i]->dmgPercent = 0;
            Enemy_unit[i]->AoeCharge = 0;
            for(auto &e: Enemy_unit[i]->AttackCoolDown){
                e.second = 0;
            }
            Enemy_unit[i]->damageAvgNote.resize(Total_ally+1);
            Enemy_unit[i]->damageRealTimeNote.resize(Total_ally+1);
            Enemy_unit[i]->maxDamageAvgNote.resize(Total_ally+1);
            Enemy_unit[i]->maxDamageRealTimeNote.resize(Total_ally+1);
            
            
            for(auto &e: Enemy_unit[i]->Weakness_type){
                e.second = Enemy_unit[i]->Default_Weakness_type[e.first];
            }

            for(auto &e: Enemy_unit[i]->Debuff){
                e.second = 0;
            }
            for(auto &e: Enemy_unit[i]->DebuffNote){
                e.second = 0;
            }
            for(auto &e: Enemy_unit[i]->Stack){
                e.second = 0;
            }
            for(auto &e: Enemy_unit[i]->Debuff_time_count){
                e.second = 0;
            }
            for(unordered_map<string,double> &e :Enemy_unit[i]->damageAvgNote){
                for(std::pair<const std::string, double> &f : e){
                    f.second = 0;
                }
            }
            for(unordered_map<string,double> &e :Enemy_unit[i]->damageRealTimeNote){
                for(std::pair<const std::string, double> &f : e){
                    f.second = 0;
                }
            }

            Enemy_unit[i]->Bleed=0;
            Enemy_unit[i]->Bleeder=0;
            Enemy_unit[i]->Burn=0;
            Enemy_unit[i]->Burner=0;
            Enemy_unit[i]->Shock=0;
            Enemy_unit[i]->Shocker=0;
            Enemy_unit[i]->Wind_shear=0;
            Enemy_unit[i]->Wind_shear_stack=0;
            Enemy_unit[i]->Wind_shearer=0;
            Enemy_unit[i]->Freeze=0;
            Enemy_unit[i]->Entanglement=0;
            Enemy_unit[i]->Entanglement_stack=0;
            Enemy_unit[i]->Imprisonment=0;
            Enemy_unit[i]->Total_toughness_broken_time =0;
            Enemy_unit[i]->when_toughness_broken = 0;
            
            Enemy_unit[i]->Stats_each_element["Respen"]["Fire"][AT_NONE] = - Enemy_unit[i]->DefaultElementRes["Fire"];
            Enemy_unit[i]->Stats_each_element["Respen"]["Ice"][AT_NONE] = -Enemy_unit[i]->DefaultElementRes["Ice"];
            Enemy_unit[i]->Stats_each_element["Respen"]["Quantum"][AT_NONE] = -Enemy_unit[i]->DefaultElementRes["Quantum"];
            Enemy_unit[i]->Stats_each_element["Respen"]["Wind"][AT_NONE] = -Enemy_unit[i]->DefaultElementRes["Wind"];
            Enemy_unit[i]->Stats_each_element["Respen"]["Lightning"][AT_NONE] = -Enemy_unit[i]->DefaultElementRes["Lightning"];
            Enemy_unit[i]->Stats_each_element["Respen"]["Physical"][AT_NONE] = -Enemy_unit[i]->DefaultElementRes["Physical"];
            Enemy_unit[i]->Stats_each_element["Respen"]["Imaginary"][AT_NONE] = -Enemy_unit[i]->DefaultElementRes["Imaginary"];
        }

    

}
void Memosprite_reset(){
    for(int i=1;i<=Total_ally;i++){
        for(int j=1,sz = Ally_unit[i]->Sub_Unit_ptr.size();j<sz;j++){
            for(auto &e1:Ally_unit[i]->Sub_Unit_ptr[j]->Stats_type){
                for(auto &e2:e1.second){
                    e2.second = 0;
                }

            }
            for(auto &e1:Ally_unit[i]->Sub_Unit_ptr[j]->Stats_each_element){
                for(auto &e2:e1.second){
                    for(auto &e3:e2.second){
                        e3.second = 0;
                    }

                }

            }
            for(auto &e1:Ally_unit[i]->Sub_Unit_ptr[0]->Stats_type){
                for(auto &e2:e1.second){
                    Ally_unit[i]->Sub_Unit_ptr[j]->Stats_type[e1.first][e2.first] = e2.second;
                }

            }
            for(auto &e1:Ally_unit[i]->Sub_Unit_ptr[0]->Stats_each_element){
                for(auto &e2:e1.second){
                    for(auto &e3:e2.second){
                        Ally_unit[i]->Sub_Unit_ptr[j]->Stats_each_element[e1.first][e2.first][e3.first] = e3.second;
                    }

                }

            }
            for(auto &e :Ally_unit[i]->Sub_Unit_ptr[j]->Stats_type["Flat_Hp"]){    
                e.second *=(Ally_unit[i]->Sub_Unit_ptr[j]->Unit_Hp_Ratio/100);
            }
        //speed
        
            for(auto &e:Ally_unit[i]->Sub_Unit_ptr[j]->Stack){
                e.second = 0;
            }
            for(auto &e:Ally_unit[i]->Sub_Unit_ptr[j]->Buff_countdown){
                e.second = 0;
            }
            for(auto &e:Ally_unit[i]->Sub_Unit_ptr[j]->Buff_note){
                e.second = 0;
            }
            for(auto &e:Ally_unit[i]->Sub_Unit_ptr[j]->Buff_check){
                e.second = 0;
            }
            for(std::pair<const std::string, SubUnit *> &e : Ally_unit[i]->Sub_Unit_ptr[j]->buffSubUnitTarget){
                e.second = nullptr;
            }
            
        Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->turn_cnt = 0;
        Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->priority = 0;
        Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->Flat_Speed = Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed*(Ally_unit[i]->Sub_Unit_ptr[j]->Unit_Speed_Ratio/100);
        if(Ally_unit[i]->Sub_Unit_ptr[j]->Unit_Speed_Ratio!=0)Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->Speed_percent = Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Speed_percent;
        Ally_unit[i]->Sub_Unit_ptr[j]->currentAllyTargetNum = Ally_unit[i]->Sub_Unit_ptr[j]->defaultAllyTargetNum;
        Ally_unit[i]->Sub_Unit_ptr[j]->currentSubUnitTargetNum = Ally_unit[i]->Sub_Unit_ptr[j]->defaultSubUnitTargetNum;
        Ally_unit[i]->Sub_Unit_ptr[j]->currentSheild = 0;

        }
        
    }
}
void Summon_reset(){
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = Ally_unit[i]->Summon_ptr.size();j<sz;j++){  
        
        //speed
        Ally_unit[i]->Summon_ptr[j]->Atv_stats->Speed_percent=0;
        Ally_unit[i]->Summon_ptr[j]->Atv_stats->Flat_Speed=0;
        Ally_unit[i]->Summon_ptr[j]->Atv_stats->turn_cnt = 0;
        Ally_unit[i]->Summon_ptr[j]->Atv_stats->priority = 0;

        
        
        
        }
    }
}
void Countdown_reset(){
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = Ally_unit[i]->Countdown_ptr.size();j<sz;j++){  
        
        //speed
        Ally_unit[i]->Countdown_ptr[j]->Atv_stats->Speed_percent=0;
        Ally_unit[i]->Countdown_ptr[j]->Atv_stats->Flat_Speed=0;
        Ally_unit[i]->Countdown_ptr[j]->Atv_stats->turn_cnt = 0;
        Ally_unit[i]->Countdown_ptr[j]->Atv_stats->priority = 0;
        Ally_unit[i]->Countdown_ptr[j]->Atv_stats->Base_speed = -1;
        }
    }
}
#endif