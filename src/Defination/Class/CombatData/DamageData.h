#ifndef DamageData_H
#define DamageData_H
#include "../Unit/Library.h"

class DmgSrc{
    public:
    double ATK = 0;
    double HP = 0;
    double DEF = 0;
    double constDmg = 0;
    double Elation = 0;
    double toughnessReduce = 0;

    DmgSrc(){}
    
    DmgSrc(double ATK, double HP, double DEF, double constDmg,double Elation, double toughnessReduce)
        : ATK(ATK), HP(HP), DEF(DEF), constDmg(constDmg),Elation(Elation), toughnessReduce(toughnessReduce)
    {}
    DmgSrc(DmgSrcType type,double value)
    {
        switch(type) {
            case DmgSrcType::ATK:
                ATK = value;
                break;
            case DmgSrcType::HP:
                HP = value;
                break;
            case DmgSrcType::DEF:
                DEF = value;
                break;
            case DmgSrcType::CONST:
                constDmg = value;
                break;
            case DmgSrcType::Elation:
                Elation = value;
                break;    
        }
    }
    DmgSrc(DmgSrcType type, double value, double toughnessReduce)
        : toughnessReduce(toughnessReduce)
    {
        switch(type) {
            case DmgSrcType::ATK:
                ATK = value;
                break;
            case DmgSrcType::HP:
                HP = value;
                break;
            case DmgSrcType::DEF:
                DEF = value;
                break;
            case DmgSrcType::CONST:
                constDmg = value;
                break;
            case DmgSrcType::Elation:
                Elation = value;
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

    Damage(double ATK, double HP, double DEF, double constDmg,double Elation, double toughnessReduce,Enemy* target)
        : dmgSrc(ATK, HP, DEF, constDmg,Elation, toughnessReduce), target(nullptr) 
    {}
};

typedef vector<vector<Damage>> DamageSplit;
#endif
