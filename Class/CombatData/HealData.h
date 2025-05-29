#ifndef HealData_H
#define HealData_H
#include "../Unit/Library.h"
class HealSrc{
    public :
    double ATK = 0;
    double HP = 0;
    double DEF = 0;
    double constHeal = 0;
    double healFromTotalHP = 0;
    double healFromLostHP = 0;

    HealSrc() = default;
    HealSrc(double ATK = 0, double HP = 0, double DEF = 0, double constHeal = 0, double healFromTotalHP = 0, double healFromLostHP = 0)
        : ATK(ATK), HP(HP), DEF(DEF), constHeal(constHeal), healFromTotalHP(healFromTotalHP), healFromLostHP(healFromLostHP) {}

    // Main variadic constructor
    template<typename... Args>
    HealSrc(Args... args) {
        static_assert(sizeof...(args) % 2 == 0, "Arguments must be in (HealSrcType, double) pairs");
        setValues(args...);
    }

    // Recursive variadic function to unpack and set values
    void setValue(HealSrcType type, double value) {
        switch (type) {
            case HealSrcType::ATK:
                ATK = value;
                break;
            case HealSrcType::HP:
                HP = value;
                break;
            case HealSrcType::DEF:
                DEF = value;
                break;
            case HealSrcType::CONST:
                constHeal = value;
                break;
            case HealSrcType::TOTAL_HP:
                healFromTotalHP = value;
                break;
            case HealSrcType::LOST_HP:
                healFromLostHP = value;
                break;
            default:
                throw std::invalid_argument("Unknown HealSrcType");
        }
    }

    private:

    void setValues() {}


    template<typename... Rest>
    void setValues(HealSrcType type, double value, Rest... rest) {
        setValue(type, value);
        setValues(rest...); // recursive call
    }

};
#endif
