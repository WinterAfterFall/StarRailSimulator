#include "../include.h"
namespace EnemyCmd{
    void setEnemyWeakness(bool physical,bool fire,bool ice,bool wind,bool lightning,bool quantum,bool imaginary){
        enemyWeak = {
            {ElementType::FIRE, 1},
            {ElementType::ICE, 1},
            {ElementType::QUANTUM, 1},
            {ElementType::WIND, 1},
            {ElementType::LIGHTNING, 1},
            {ElementType::PHYSICAL, 1},
            {ElementType::IMAGINARY, 1}
        };
        enemyWeak[ElementType::PHYSICAL] = physical;
        enemyWeak[ElementType::FIRE] = fire;
        enemyWeak[ElementType::ICE] = ice;
        enemyWeak[ElementType::WIND] = wind;
        enemyWeak[ElementType::LIGHTNING] = lightning;
        enemyWeak[ElementType::QUANTUM] = quantum;
        enemyWeak[ElementType::IMAGINARY] = imaginary;
    }
}

