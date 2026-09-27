#ifndef ALL_LIGHTCONE_H
#define ALL_LIGHTCONE_H
#include".\Abundance\All_Abundance_LC.h"
#include".\Destruction\All_Destruction_LC.h"
#include".\Erudition\All_Erudition_LC.h"
#include".\Harmony\All_Harmony_LC.h"
#include".\Nihility\All_Nihility_LC.h"
#include".\Preservation\All_Preservation_LC.h"
#include".\Remembrance\All_Remembrance_LC.h"
#include".\Elation\All_Elation_LC.h"
function<void(CharUnit *ptr)> lightConeTemp(double hp,double atk,double def){
    return [=](CharUnit *ptr) {
        ptr->setAllyBaseStats( hp, atk, def);
    };
}
#endif
//ถ้าหาก summon มีอัลติ
// Multiplication DDD
