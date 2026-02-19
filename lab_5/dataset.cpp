#include "dataset.h"

void Dataset::load(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Не вдалося відкрити файл: " << filename << endl;
        return;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream steam(line);
        string user, movie, rating, timestamp;

        getline(steam, user, ',');
        getline(steam, movie, ',');
        getline(steam, rating, ',');
        getline(steam, timestamp, ',');

        size_t userId = stoul(user);
        size_t movieId = stoul(movie);
        double ratingValue = stod(rating);

        m_userRatings[userId][movieId] = ratingValue;
        m_movieRatings[movieId][userId] = ratingValue;
    }

    file.close();
    cout << "Завантажено " << m_userRatings.size() << " користувачів та " << m_movieRatings.size() << " фільмів.\n";
}
