#ifndef All_Lightcone_H
#define All_Lightcone_H
#include".\Abundance\All_Abundance_LC.h"
#include".\Destruction\All_Destruction_LC.h"
#include".\Erudition\All_Erudition_LC.h"
#include".\Harmony\All_Harmony_LC.h"
#include".\Nihility\All_Nihility_LC.h"
#include".\Preservation\All_Preservation_LC.h"
#include".\Remembrance\All_Remembrance_LC.h"

function<void(Ally *ptr)> LightCone_temp(double HP,double ATK,double DEF){
    return [=](Ally *ptr) {
        ptr->SetAllyBaseStats( HP, ATK, DEF);
    };
}
#endif
//ถ้าหาก summon มีอัลติ
// Multiplication DDD
