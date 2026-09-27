#ifndef HEAL_DATA_H
#define HEAL_DATA_H
#include "../Unit/Library.h"
class HealSrc{
    public :
    double atk = 0;
    double hp = 0;
    double def = 0;
    double constHeal = 0;
    double healFromTotalHP = 0;
    double healFromLostHP = 0;

    HealSrc(double atk = 0, double hp = 0, double def = 0, double constHeal = 0, double healFromTotalHP = 0, double healFromLostHP = 0)
        : atk(atk), hp(hp), def(def), constHeal(constHeal), healFromTotalHP(healFromTotalHP), healFromLostHP(healFromLostHP) {}

    // Variadic constructor: (HealSrcType1, value1, HealSrcType2, value2, ...)
    template<typename... Args>
    HealSrc(Args... args) {
        static_assert(sizeof...(args) % 2 == 0, "Arguments must be in pairs of (HealSrcType, value)");
        setValues(args...);
    }

    private:
    void setValues() {}

    template<typename T, typename U, typename... Rest>
    void setValues(T type, U value, Rest... rest) {
        setValue(type, value);
        setValues(rest...);
    }
    public :
    void setValue(HealSrcType type, double value) {
        switch (type) {
            case HealSrcType::ATK:
                atk = value;
                break;
            case HealSrcType::HP:
                hp = value;
                break;
            case HealSrcType::DEF:
                def = value;
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

};
#endif
