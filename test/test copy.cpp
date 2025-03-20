#include <iostream>
#include <vector>
using namespace std;

void findPermutations(vector<int>& combination, int index, int remainingSum, int x, int y) {
    // Base case: if all units are filled and sum equals y
    if (index == x) {
        if (remainingSum == 0) {
            for (int i = 0; i < x; i++) {
                cout << combination[i] << (i == x - 1 ? "\n" : ", ");
            }
        }
        return;
    }

    // Try all possible values for the current unit
    for (int value = 0; value <= y && value <= remainingSum; value++) {
        combination[index] = value;
        findPermutations(combination, index + 1, remainingSum - value, x, y);
    }
}

int main() { 
    int x, y;
    cout << "c \t c";

    return 0;
}
