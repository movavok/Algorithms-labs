#include "similarity.h"

double Similarity::computePearson(const vector<pair<double, double>>& commonRatings) {
    int n = commonRatings.size();
    if (n == 0) return 0.0;

    double sumX = 0.0;
    double sumY = 0.0;
    double sumXSq = 0.0;
    double sumYSq = 0.0;
    double sumXY = 0.0;

    for (const auto& [x, y] : commonRatings) {
        sumX += x;
        sumY += y;
        sumXSq += x * x;
        sumYSq += y * y;
        sumXY += x * y;
    }

    double numer = sumXY - (sumX * sumY / n);

    double denom = sqrt((sumXSq - (sumX * sumX / n)) *
                        (sumYSq - (sumY * sumY / n)));

    if (denom == 0.0) return 0.0;

    return numer / denom;
}

double Similarity::pearsonUsers(size_t firstUserId, size_t secondUserId, const Dataset& dataset) {
    const unordered_map<size_t, unordered_map<size_t, double>>& allUsers = dataset.getUserRatings();

    if (!allUsers.count(firstUserId) || !allUsers.count(secondUserId))
        return 0.0;

    const unordered_map<size_t, double>& firstRatings = allUsers.at(firstUserId);
    const unordered_map<size_t, double>& secondRatings = allUsers.at(secondUserId);

    vector<pair<double, double>> commonRatings;

    for (const auto& [movieId, rating] : firstRatings)
        if (secondRatings.count(movieId))
            commonRatings.emplace_back(rating, secondRatings.at(movieId));

    return computePearson(commonRatings);
}

double Similarity::pearsonMovies(size_t firstMovieId, size_t secondMovieId, const Dataset& dataset) {
    const unordered_map<size_t, unordered_map<size_t, double>>& allUsers = dataset.getUserRatings();

    vector<pair<double, double>> commonRatings;

    for (const auto& [userId, ratings] : allUsers)
        if (ratings.count(firstMovieId) && ratings.count(secondMovieId))
            commonRatings.emplace_back(ratings.at(firstMovieId), ratings.at(secondMovieId));

    return computePearson(commonRatings);
}
