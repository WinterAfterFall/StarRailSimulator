#include "../include.h"
void Set_Stats(CharUnit *ptr){
    for(int i=0,sz = ptr->Substats.size();i<sz;i++){
        if(ptr->Substats[i].first==Stats::FLAT_SPD){
            ptr->Atv_stats->flatSpeed+=2.3*ptr->Substats[i].second;
            for(auto &memo : ptr->memospriteList){
            memo->Atv_stats->flatSpeed+=(2.3*ptr->Substats[i].second)*(memo->Unit_Speed_Ratio/100);
            }
            
        }else if(ptr->Substats[i].first==Stats::HP_P){ 
            buffSingle(ptr,{{Stats::HP_P,AType::None,3.888*ptr->Substats[i].second}});
            for(auto &memo : ptr->memospriteList){ 
            buffSingle(memo.get(),{{Stats::HP_P,AType::None,3.888*ptr->Substats[i].second}});
            }
        }
        if(ptr->Substats[i].first==Stats::CR){
            buffSingle(ptr,{{Stats::CR,AType::None,2.9*ptr->Substats[i].second}});
            for(auto &memo : ptr->memospriteList){
            buffSingle(memo.get(),{{Stats::CR,AType::None,2.9*ptr->Substats[i].second}});
            }

        }else if(ptr->Substats[i].first==Stats::CD){
            buffSingle(ptr,{{Stats::CD,AType::None,5.8*ptr->Substats[i].second}});
            for(auto &memo : ptr->memospriteList){
            buffSingle(memo.get(),{{Stats::CD,AType::None,5.8*ptr->Substats[i].second}});
            }
            
        }else if(ptr->Substats[i].first==Stats::ATK_P){
            buffSingle(ptr,{{Stats::ATK_P,AType::None,3.888*ptr->Substats[i].second}});
            for(auto &memo : ptr->memospriteList){
            buffSingle(memo.get(),{{Stats::ATK_P,AType::None,3.888*ptr->Substats[i].second}});
            }
            
        }else if(ptr->Substats[i].first==Stats::DEF_P){
            buffSingle(ptr,{{Stats::DEF_P,AType::None,4.86*ptr->Substats[i].second}});
            for(auto &memo : ptr->memospriteList){
            buffSingle(memo.get(),{{Stats::DEF_P,AType::None,4.86*ptr->Substats[i].second}});
            }
            
        }else if(ptr->Substats[i].first==Stats::BE){
            buffSingle(ptr,{{Stats::BE,AType::None,5.8*ptr->Substats[i].second}});
            for(auto &memo : ptr->memospriteList){
            buffSingle(memo.get(),{{Stats::BE,AType::None,5.8*ptr->Substats[i].second}});
            }
        }
    }
}
bool Reroll_substats(){
    bool allDone = true;
    for(int i=1; i<= Total_ally; i++){
        if(rerollFunction(charUnit[i].get())) allDone = false;
    }
    return allDone;
}

// ------------------------------ Standard Reroll ------------------------------
// หา substats ที่ดาเมจสูงสุด ด้วยการย้าย roll ทีละ 1 เม็ด (โครงเดียวกับ rerollSubstats() ของ WuwaSimulator)
//
// จุดเริ่ม : setTotalSubstats() ยัด roll ทั้งหมดไว้ที่ Substats[0] — ช่อง 0 เป็นคลัง ช่องอื่นเริ่มที่ 0
// target  : Substats[rerollTargetIndex] ช่องที่กำลังเติม — เริ่ม 1 ไล่ไปจนช่องสุดท้าย
// source  : Substats[rerollSourceIndex] ช่องที่ดึงออก — ไล่ 0 → target-1
//
// 1 sweep = ลองทุก source ของ target ตัวเดียว
//   ชุดทดลอง = rerollSweepBase แล้ว source -1 / target +1 (ทุกชุดแตกจาก base เดียวกัน ไม่สะสม)
//   1 คอล = 1 ชุดทดลอง → คืน true ให้ caller รัน sim → คอลถัดไป changeMaxDamage วัดผลชุดนั้น
//   changeMaxDamage เก็บชุดที่ดาเมจสูงสุดไว้ใน bestSubstats → ครบ sweep แล้ว best = ชุดที่ชนะ
//
// ครบทุก source แล้ว
//   มีชุดที่ดาเมจดีขึ้น → sweep target เดิมซ้ำ เริ่มจาก best ใหม่
//   ไม่มีเลย          → target +1 แล้ว source กลับไปเริ่มที่ 0
// target เลยช่องสุดท้าย → คืน Substats เป็น bestSubstats แล้วจบ
bool StandardReroll(CharUnit *ptr){
    if(!ptr->rerollActive) return false;

    // วัดผลรอบ sim ที่เพิ่งจบ — นับ improvement เฉพาะชุดทดลอง (รอบแรกสุดคือ baseline ไม่นับ)
    if(changeMaxDamage(ptr) && ptr->rerollSourceIndex >= 0) ptr->rerollImproved = true;

    while(true){
        // bestSubstats ถูก resize ใน setTotalSubstats — ตัวที่ไม่ได้ตั้ง substats จะจบตรงนี้ทันที
        if(ptr->rerollTargetIndex >= (int)ptr->bestSubstats.size()){
            restoreBestSubstats(ptr);
            ptr->rerollActive = false;
            return false;
        }

        if(ptr->rerollSourceIndex == -1) ptr->rerollSweepBase = ptr->bestSubstats;

        int nextSource = ptr->rerollSourceIndex + 1;
        if(nextSource >= ptr->rerollTargetIndex){
            if(!ptr->rerollImproved) ptr->rerollTargetIndex++;
            ptr->rerollImproved = false;
            ptr->rerollSourceIndex = -1;
            continue;
        }

        ptr->rerollSourceIndex = nextSource;
        if(trySwapSubstat(ptr, nextSource)) return true;
    }
}
// Substats = rerollSweepBase แล้วย้าย 1 roll จาก source ไป target
// source ไม่มี roll ให้ดึง → คืน false ข้ามไปเลย ไม่เสียรอบ sim
bool trySwapSubstat(CharUnit *ptr, int sourceIndex){
    if(ptr->rerollSweepBase[sourceIndex] <= 0) return false;

    for(int i=0, sz = ptr->rerollSweepBase.size(); i<sz; i++){
        ptr->Substats[i].second = ptr->rerollSweepBase[i];
    }
    ptr->Substats[sourceIndex].second--;
    ptr->Substats[ptr->rerollTargetIndex].second++;
    return true;
}
void restoreBestSubstats(CharUnit *ptr){
    for(int i=0, sz = ptr->bestSubstats.size(); i<sz; i++){
        ptr->Substats[i].second = ptr->bestSubstats[i];
    }
}

/* ------------------------ ปิดไว้ก่อน (2026-09-13) — ใช้แค่ StandardReroll ------------------------
 * โค้ดข้างล่างคงไว้ตามเดิมก่อน refactor ยังอ้างชื่อเก่า: Reroll_check -> rerollActive,
 * Max_damage_Substats -> bestSubstats และ Damage_data / currentTotalSubstats (ลบ field ไปแล้ว)
 * เดิมพึ่ง goto again ใน Reroll_substats() ข้ามชุดที่ติดลบ ซึ่งเอาออกไปแล้ว
 * จะเปิดกลับ: แก้ชื่อ + ใส่ Damage_data คืน + กันค่าติดลบเอง + เปิด enum (StatusEnum.h) และ SetCombat.h

bool AllCombinationReroll(CharUnit *ptr){
    if(0 == ptr->Reroll_check&&ptr->AvgDmgRecord[0].maxDmgRecord>=0)return false;
    changeMaxDamage(ptr);
    if(ptr->Substats.size()<=1||ptr->Reroll_check==0){
        ptr->Reroll_check = 0;
        return false;
    }
    int index = 0;
    
        for(int i=0;i<ptr->Substats.size();i++){
            index+= ptr->Substats[i].second*pow(ptr->Total_substats+1,i);
        }
        ptr->Damage_data[index] = ptr->AvgDmgRecord[0].currentDmgRecord;
         
        if(ptr->Substats[ptr->Substats.size()-1].second==ptr->currentTotalSubstats){
        ptr->Reroll_check = 0;
        for(int i=0,sz = ptr->Max_damage_Substats.size();i<sz;i++)
        ptr->Substats[i].second = ptr->Max_damage_Substats[i];
        return false;
    }

    for(int i=0;i<ptr->Substats.size();i++){
        if(ptr->Substats[i].second!=0){
            ptr->Substats[0].second = ptr->Substats[i].second-1;
            if(i!=0){
              ptr->Substats[i].second = 0;  
            }
            ptr->Substats[i+1].second+=1;
            return true;
        }
    }
    return false;
}
bool AllPossibleReroll(CharUnit *ptr){
    if(0 == ptr->Reroll_check)return false;
    changeMaxDamage(ptr);
    if(ptr->Substats.size()<=1){
        ptr->Reroll_check = 0;
        return false;
    }
    int index = 0;
    
        for(int i=ptr->Substats.size();i>=1;i--){
            index+= ptr->Substats[i].second*pow(ptr->Total_substats+1,i);
        }
        ptr->Damage_data[index] = ptr->AvgDmgRecord[0].currentDmgRecord;
    
    // When Reroll with all Combination it will decrease total substats
    if(ptr->Substats[ptr->Substats.size()-1].second==ptr->currentTotalSubstats){
        
        ptr->currentTotalSubstats--;
        ptr->Substats[0].second = ptr->currentTotalSubstats; 
        for(int i=1;i<ptr->Substats.size();i++){
            ptr->Substats[i].second = 0; 
        }
        if(ptr->currentTotalSubstats>=0)return true;
        
        ptr->Reroll_check = 0;
        return false;
    }
    
    //Reroll
    for(int i=0;i<ptr->Substats.size();i++){
        if(ptr->Substats[i].second!=0){
            ptr->Substats[0].second = ptr->Substats[i].second-1;
            if(i!=0){
              ptr->Substats[i].second = 0;  
            }
            ptr->Substats[i+1].second+=1;
            return true;
        }
    }
    return false;
}
*/
