#include <iostream>
#include <ctime>

#include "parkmiller.h"
#include "lecuyer.h"
#include "bbs.h"

using namespace std;

void printSequence(RandomGenerator& gen, int numbersAmount, const string& title) {
    cout << title;
    for (int count = 0; count < numbersAmount; ++count)
        cout << gen.next() << " ";
    cout << endl;
}

int main() {
    long long seed = time(nullptr);

    ParkMiller pmGen(seed);
    printSequence(pmGen, 5, "Мінімальний генератор Парка-Міллера: ");

    LEcuyer lecGen(seed, seed / 2);
    printSequence(lecGen, 5, "Алгоритм Л'Екюера: ");

    BBS bbsGen(seed % 1000 + 3, 383, 503);

    cout << "Алгоритм Блюма-Блюма-Шуба (біти): ";
    for (int count = 0; count < 32; ++count) {
        cout << bbsGen.next();
        if ((count + 1) % 8 == 0) cout << " ";
    }
    cout << endl;

    cout << "                          (як байти): ";
    for (int count = 0; count < 4; ++count)
        cout << bbsGen.nextByte() << " ";
    cout << endl;

    return 0;
}



