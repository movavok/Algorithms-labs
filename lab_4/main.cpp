#include <iostream>
#include <ctime>

#include "parkmiller.h"
#include "lecuyer.h"
#include "bbs.h"
#include "uniformitytest.h"

void printSequence(RandomGenerator& gen, int numbersAmount, const string& title) {
    cout << title;
    for (int count = 0; count < numbersAmount; ++count)
        cout << gen.next() << " ";
    cout << endl;
}

void runUniformity(RandomGenerator& gen, const string& title, int numbers = 10000, int intervals = 10) {
    UniformityTest test(numbers, intervals);
    double chi2 = test.runTest(gen);
    cout << title << "X^2 = " << chi2 << endl << endl;
}

int main() {
    long long seed = time(nullptr);

    ParkMiller pmGen(seed);
    printSequence(pmGen, 5, "Мінімальний генератор Парка-Міллера: ");
    runUniformity(pmGen, "Тест рівномірності Парка-Міллера: ");

    LEcuyer lecGen(seed, seed / 2);
    printSequence(lecGen, 5, "Алгоритм Л'Екюера: ");
    runUniformity(lecGen, "Тест рівномірності Л'Екюера: ");

    const long long firstPrime = 10007;
    const long long secondPrime = 10009;

    BBS bbsGen(seed % (firstPrime * secondPrime - 2) + 2, firstPrime, secondPrime);

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

    runUniformity(bbsGen, "Тест рівномірності Блюма-Блюма-Шуба: ");

    return 0;
}
