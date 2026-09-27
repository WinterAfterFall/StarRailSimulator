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
    const std::vector<DotType> types = {DotType::BURN, DotType::SHOCK};

    dotSingleStack(&source, &enemy, types, 0, 5, "stacked DoT");
    checkDot(enemy.getStack("stacked DoT") == 0 && enemy.totalDebuff == 0 &&
                 enemy.dotCount == 0 && enemy.burnCount == 0 && enemy.shockCount == 0,
             "Zero-stack DoT must not change status or type counts");

    dotSingleStack(&source, &enemy, types, 2, 5, "stacked DoT", 2);
    checkDot(enemy.getStack("stacked DoT") == 2 && enemy.totalDebuff == 1 &&
                 enemy.dotCount == 2 && enemy.burnCount == 1 && enemy.shockCount == 1,
             "Positive stack must count each DoT type once");

    dotSingleStack(&source, &enemy, types, -2, 5, "stacked DoT");
    checkDot(enemy.getStack("stacked DoT") == 0 && enemy.totalDebuff == 0 &&
                 enemy.dotCount == 0 && enemy.burnCount == 0 && enemy.shockCount == 0,
             "Removing the last stack must remove all DoT type counts");

    dotSingleStack(&source, &enemy, types, -1, 5, "stacked DoT", 2);
    checkDot(enemy.getStack("stacked DoT") == 0 && enemy.totalDebuff == 0 &&
                 enemy.dotCount == 0 && enemy.burnCount == 0 && enemy.shockCount == 0,
             "Reducing an absent DoT must leave counts unchanged");
}
