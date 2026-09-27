#ifndef DAMAGE_DATA_H
#define DAMAGE_DATA_H
#include "../Unit/Library.h"

class DmgSrc{
    public:
    double atk = 0;
    double hp = 0;
    double def = 0;
    double constDmg = 0;
    double elation = 0;
    double toughnessReduce = 0;

    DmgSrc(){}
    
    DmgSrc(double atk, double hp, double def, double constDmg,double elation, double toughnessReduce)
        : atk(atk), hp(hp), def(def), constDmg(constDmg),elation(elation), toughnessReduce(toughnessReduce)
    {}
    DmgSrc(DmgSrcType type,double value)
    {
        switch(type) {
            case DmgSrcType::ATK:
                atk = value;
                break;
            case DmgSrcType::HP:
                hp = value;
                break;
            case DmgSrcType::DEF:
                def = value;
                break;
            case DmgSrcType::CONST:
                constDmg = value;
                break;
            case DmgSrcType::ELATION:
                elation = value;
                break;    
        }
    }
    DmgSrc(DmgSrcType type, double value, double toughnessReduce)
        : toughnessReduce(toughnessReduce)
    {
        switch(type) {
            case DmgSrcType::ATK:
                atk = value;
                break;
            case DmgSrcType::HP:
                hp = value;
                break;
            case DmgSrcType::DEF:
                def = value;
                break;
            case DmgSrcType::CONST:
                constDmg = value;
                break;
            case DmgSrcType::ELATION:
                elation = value;
                break;  
        }
        
    }

};
class Damage{
    public:
    DmgSrc dmgSrc;
    Enemy* target = nullptr;

    Damage(){}

    Damage(DmgSrcType type, double value, double toughnessReduce, Enemy* target)
    : dmgSrc(type, value, toughnessReduce), target(target) 
    {}
    Damage(DmgSrc dmgSrc,Enemy* target)
    : dmgSrc(dmgSrc), target(target) 
    {}

    Damage(double atk, double hp, double def, double constDmg,double elation, double toughnessReduce,Enemy* target)
        : dmgSrc(atk, hp, def, constDmg,elation, toughnessReduce), target(target)
    {}
};

typedef vector<vector<Damage>> DamageSplit;
#endif
