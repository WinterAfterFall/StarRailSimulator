#ifndef EnemyCmd_H
#define EnemyCmd_H

#include "../Class/ClassLibrary.h"
namespace EnemyCmd{
    void setEnemyWeakness(bool Physical,bool Fire,bool Ice,bool Wind,bool Lightning,bool Quantum,bool Imaginary){
        Enemy_weak = {
            {ElementType::Fire, 1},
            {ElementType::Ice, 1},
            {ElementType::Quantum, 1},
            {ElementType::Wind, 1},
            {ElementType::Lightning, 1},
            {ElementType::Physical, 1},
            {ElementType::Imaginary, 1}
        };
        Enemy_weak[ElementType::Physical] = Physical;
        Enemy_weak[ElementType::Fire] = Fire;
        Enemy_weak[ElementType::Ice] = Ice;
        Enemy_weak[ElementType::Wind] = Wind;
        Enemy_weak[ElementType::Lightning] = Lightning;
        Enemy_weak[ElementType::Quantum] = Quantum;
        Enemy_weak[ElementType::Imaginary] = Imaginary;
    }
}

#endif