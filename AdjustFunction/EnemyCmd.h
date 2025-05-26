#ifndef EnemyCmd_H
#define EnemyCmd_H

#include "../Class/ClassLibrary.h"
namespace EnemyCmd{
    void setEnemyWeakness(bool Physical,bool Fire,bool Ice,bool Wind,bool Lightning,bool Quantum,bool Imaginary){
        Enemy_weak = {
            {"Fire", 1},
            {"Ice", 1},
            {"Quantum", 1},
            {"Wind", 1},
            {"Lightning", 1},
            {"Physical", 1},
            {"Imaginary", 1}
        };
        Enemy_weak["Physical"] = Physical;
        Enemy_weak["Fire"] = Fire;
        Enemy_weak["Ice"] = Ice;
        Enemy_weak["Wind"] = Wind;
        Enemy_weak["Lightning"] = Lightning;
        Enemy_weak["Quantum"] = Quantum;
        Enemy_weak["Imaginary"] = Imaginary;
    }
}

#endif