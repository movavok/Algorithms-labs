#ifndef SIMILARITY_H
#define SIMILARITY_H

#include "dataset.h"
#include <vector>

class Similarity {
public:
    static double pearsonUsers(size_t firstUserId, size_t secondUserId, const Dataset&);
    static double pearsonMovies(size_t firstMovieId, size_t secondMovieId, const Dataset&);

private:
    static double computePearson(const vector<pair<double, double>>& commonRatings);
};


#endif // SIMILARITY_H
