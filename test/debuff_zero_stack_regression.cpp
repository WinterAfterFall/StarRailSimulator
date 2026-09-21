#include "../SettingFunction.h"
#include <cstdlib>

void checkStack(bool condition, const char* message) {
    if (!condition) {
        std::cerr << message << '\n';
        std::exit(1);
    }
}

int main() {
    AllyUnit source;
    Enemy enemy;

    auto unchanged = calDebuffStack(&source, &enemy, "Zero stack", 0, 5);
    checkStack(unchanged.first == 0 && unchanged.second == 0 &&
                   enemy.Total_debuff == 0,
               "A zero-stack request must not create a debuff");

    auto added = calDebuffStack(&source, &enemy, "Zero stack", 2, 5);
    checkStack(added.first == 2 && added.second == 2 &&
                   enemy.Total_debuff == 1,
               "Positive stack must count as one debuff");

    auto reduced = calDebuffStack(&source, &enemy, "Zero stack", -2, 5);
    checkStack(reduced.first == -2 && reduced.second == 0 &&
                   enemy.Total_debuff == 0,
               "Removing the final stack must remove the debuff count");

    auto stillZero = calDebuffStack(&source, &enemy, "Zero stack", -1, 5);
    checkStack(stillZero.first == 0 && stillZero.second == 0 &&
                   enemy.Total_debuff == 0,
               "Reducing an absent stack must leave the debuff count unchanged");
}
