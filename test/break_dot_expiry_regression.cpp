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
    source.Atv_stats->Name = "source";
    otherSource.Atv_stats->Name = "other source";
    Enemy enemy;
    enemy.Atv_stats->side = Side::Enemy;
    enemy.Atv_stats->charptr = &enemy;
    enemy.Atv_stats->turnCnt = 2;
    turn = enemy.Atv_stats.get();

    enemy.addBreakSEList({BreakSEType::Burn, &source, 2});
    enemy.addBreakSEList({BreakSEType::Shock, &otherSource, 3});
    enemy.Total_debuff = 2;
    allEventAfterTurn();

    checkExpiry(enemy.breakDotList.size() == 1 &&
                    enemy.breakDotList[0].type == BreakSEType::Shock,
                "Only the expired Burn should be removed");
    checkExpiry(enemy.BurnCount == 0 && enemy.ShockCount == 1 &&
                    enemy.DotCount == 1 && enemy.Total_debuff == 1,
                "Expiry must decrement the removed DoT type, not the next type");

    enemy.Atv_stats->turnCnt = 3;
    allEventAfterTurn();
    checkExpiry(enemy.breakDotList.empty() && enemy.BurnCount == 0 &&
                    enemy.ShockCount == 0 && enemy.DotCount == 0 &&
                    enemy.Total_debuff == 0,
                "Expiring the final DoT must clear its own counters");
}
