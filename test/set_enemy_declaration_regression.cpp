#include "../src/Declaration/Function/Setup/SetEnemy.h"

int main() {
    using CreateEnemySignature = Enemy* (*)(double, double, EnemyType);
    using SetupEnemySignature = void (*)(double, double,
        pair<double, double>, pair<double, double>, pair<int, int>, int,
        EnemyType);

    CreateEnemySignature createEnemy = &createNewEnemy;
    SetupEnemySignature setupEnemy = &SetupEnemy;
    (void)createEnemy;
    (void)setupEnemy;
    return 0;
}
