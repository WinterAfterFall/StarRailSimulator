#ifndef EnemyCmd_H
#define EnemyCmd_H

#include "../Class/ClassLibrary.h"
namespace EnemyCmd{
    void setEnemyWeakness(bool Physical,bool Fire,bool Ice,bool Wind,bool Lightning,bool Quantum,bool Imaginary){
        Enemy_weak = {
            {ET_FIRE, 1},
            {ET_ICE, 1},
            {ET_QT, 1},
            {ET_WIND, 1},
            {ET_LN, 1},
            {ET_PHY, 1},
            {ET_IMG, 1}
        };
        Enemy_weak[ET_PHY] = Physical;
        Enemy_weak[ET_FIRE] = Fire;
        Enemy_weak[ET_ICE] = Ice;
        Enemy_weak[ET_WIND] = Wind;
        Enemy_weak[ET_LN] = Lightning;
        Enemy_weak[ET_QT] = Quantum;
        Enemy_weak[ET_IMG] = Imaginary;
    }
}

#endif