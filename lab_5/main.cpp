#include <iostream>

#include "recommender.h"

using namespace std;

int main() {
    Dataset dataset;
    dataset.load("../../data/ratings.csv");

    Recommender rec(dataset);

    size_t userId = 1;
    size_t recommendedAmount = 10;

    cout << "Введіть номер користувача: ";
    cin >> userId;
    cout << "Введіть кількість рекомендацій: ";
    cin >> recommendedAmount;

    vector<pair<size_t, double>> userRecs = rec.recommendUserBased(userId, recommendedAmount);
    cout << "Рекомендації на основі схожих користувачів для користувача №" << userId << ":" << endl;
    for (const auto& [movieId, score] : userRecs)
        cout << "Фільм №" << movieId << " -> передбачувана оцінка: " << score << endl;

    cout << endl;

    vector<pair<size_t, double>> itemRecs = rec.recommendItemBased(userId, recommendedAmount);
    cout << "Рекомендації на основі схожих фільмів для користувача №" << userId << ":" << endl;
    for (const auto& [movieId, score] : itemRecs)
        cout << "Фільм №" << movieId << " -> передбачувана оцінка: " << score << endl;

    return 0;
}
