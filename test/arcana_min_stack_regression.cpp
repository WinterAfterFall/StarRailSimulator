#include "../SettingFunction.h"
#include <cstdlib>

int main() {
    const std::pair<int, int> cases[] = {{1, 1}, {2, 1}, {3, 1}, {4, 2}, {5, 2}};
    for (const auto& [before, expected] : cases) {
        if (BS::arcanaStacksAfterTick(before) != expected) {
            std::cerr << "Arcana tick produced the wrong remaining stack count\n";
            return 1;
        }
    }
}
