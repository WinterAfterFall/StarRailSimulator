#include "../SettingFunction.h"
#include <cstdlib>

void checkDot(bool condition, const char* message) {
    if (!condition) {
        std::cerr << message << '\n';
        std::exit(1);
    }
}

int main() {
    AllyUnit source;
    Enemy enemy;
    const std::vector<DotType> types = {DotType::Burn, DotType::Shock};

    dotSingleStack(&source, &enemy, types, 0, 5, "stacked DoT");
    checkDot(enemy.getStack("stacked DoT") == 0 && enemy.Total_debuff == 0 &&
                 enemy.DotCount == 0 && enemy.BurnCount == 0 && enemy.ShockCount == 0,
             "Zero-stack DoT must not change status or type counts");

    dotSingleStack(&source, &enemy, types, 2, 5, "stacked DoT", 2);
    checkDot(enemy.getStack("stacked DoT") == 2 && enemy.Total_debuff == 1 &&
                 enemy.DotCount == 2 && enemy.BurnCount == 1 && enemy.ShockCount == 1,
             "Positive stack must count each DoT type once");

    dotSingleStack(&source, &enemy, types, -2, 5, "stacked DoT");
    checkDot(enemy.getStack("stacked DoT") == 0 && enemy.Total_debuff == 0 &&
                 enemy.DotCount == 0 && enemy.BurnCount == 0 && enemy.ShockCount == 0,
             "Removing the last stack must remove all DoT type counts");

    dotSingleStack(&source, &enemy, types, -1, 5, "stacked DoT", 2);
    checkDot(enemy.getStack("stacked DoT") == 0 && enemy.Total_debuff == 0 &&
                 enemy.DotCount == 0 && enemy.BurnCount == 0 && enemy.ShockCount == 0,
             "Reducing an absent DoT must leave counts unchanged");
}
