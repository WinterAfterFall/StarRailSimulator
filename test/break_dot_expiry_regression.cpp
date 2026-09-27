#include "../SettingFunction.h"
#include <cstdlib>

void checkExpiry(bool condition, const char* message) {
    if (!condition) {
        std::cerr << message << '\n';
        std::exit(1);
    }
}

int main() {
    AllyUnit source, otherSource;
    source.atvStats->name = "source";
    otherSource.atvStats->name = "other source";
    Enemy enemy;
    enemy.atvStats->side = Side::ENEMY;
    enemy.atvStats->charptr = &enemy;
    enemy.atvStats->turnCnt = 2;
    turn = enemy.atvStats.get();

    enemy.addBreakSEList({BreakSEType::BURN, &source, 2});
    enemy.addBreakSEList({BreakSEType::SHOCK, &otherSource, 3});
    enemy.totalDebuff = 2;
    allEventAfterTurn();

    checkExpiry(enemy.breakDotList.size() == 1 &&
                    enemy.breakDotList[0].type == BreakSEType::SHOCK,
                "Only the expired Burn should be removed");
    checkExpiry(enemy.burnCount == 0 && enemy.shockCount == 1 &&
                    enemy.dotCount == 1 && enemy.totalDebuff == 1,
                "Expiry must decrement the removed DoT type, not the next type");

    enemy.atvStats->turnCnt = 3;
    allEventAfterTurn();
    checkExpiry(enemy.breakDotList.empty() && enemy.burnCount == 0 &&
                    enemy.shockCount == 0 && enemy.dotCount == 0 &&
                    enemy.totalDebuff == 0,
                "Expiring the final DoT must clear its own counters");
}
