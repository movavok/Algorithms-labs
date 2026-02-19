#ifndef DATASET_H
#define DATASET_H

#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Dataset {
private:
    unordered_map<size_t, unordered_map<size_t, double>> m_userRatings;
    unordered_map<size_t, unordered_map<size_t, double>> m_movieRatings;

public:
    void load(const string& filename);

    const unordered_map<size_t, unordered_map<size_t, double>>& getUserRatings() const {
        return m_userRatings;
    }

    const unordered_map<size_t, unordered_map<size_t, double>>& getMovieRatings() const {
        return m_movieRatings;
    }
};

#endif // DATASET_H
