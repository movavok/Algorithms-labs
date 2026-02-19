#ifndef RECOMMENDER_H
#define RECOMMENDER_H

#include "similarity.h"

class Recommender {
public:
    Recommender(Dataset& data) : m_data(data) {}

    vector<pair<size_t, double>> recommendUserBased(size_t userId, size_t amount) {
        return recommend(userId, amount, Similarity::pearsonUsers);
    }

    vector<pair<size_t, double>> recommendItemBased(size_t userId, size_t amount) {
        return recommend(userId, amount, Similarity::pearsonMovies);
    }

private:
    Dataset& m_data;

    static bool compareDesc(const pair<size_t, double>& a, const pair<size_t, double>& b) {
        return a.second > b.second;
    }

    template<typename SimilarityFunc>
    vector<pair<size_t, double>> recommend(size_t userId, size_t recommendedAmount, SimilarityFunc similarity) {
        const unordered_map<size_t, unordered_map<size_t, double>>& allUsers = m_data.getUserRatings();
        if (!allUsers.count(userId)) return {};

        const unordered_map<size_t, double>& userRated = allUsers.at(userId);
        unordered_map<size_t, double> scores;
        unordered_map<size_t, double> similarSums;

        for (const auto& [candidateId, _] : allUsers) {
            if (candidateId == userId) continue;

            double sim = similarity(userId, candidateId, m_data);
            if (sim <= 0.0) continue;

            for (const auto& [movieId, rating] : userRated) {
                scores[movieId] += rating * sim;
                similarSums[movieId] += sim;
            }
        }

        vector<pair<size_t, double>> recommendations;
        for (const auto& [id, total] : scores)
            recommendations.emplace_back(id, total / similarSums[id]);

        sort(recommendations.begin(), recommendations.end(), compareDesc);

        if (recommendations.size() > recommendedAmount)
            recommendations.resize(recommendedAmount);

        return recommendations;
    }
};

#endif // RECOMMENDER_H
