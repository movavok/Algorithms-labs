#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class GeneticAlgorithm
{
public:
    GeneticAlgorithm(double xmin, double xmax,
                     int popSize = 50, int gens = 100,
                     double mutRate = 0.01, int chromLen = 16);

    double getXmin() { return m_Xmin; }
    double getXmax() { return m_Xmax; }

    double function(double x);

    double findMin();
    double findMax();

private:
    double m_Xmin, m_Xmax;
    int m_populationSize;
    int m_generations;
    double m_mutationRate;
    int m_chromosomeLength;

    double findExtreme(bool isMax);

    double random(double min, double max);
    string encodeChromosome(double value);
    double decodeChromosome(const string& binChromosome);
    pair<string, string> crossoverChromosomes(const string& parent1, const string& parent2);
    void mutateChromosome(string& chromosome);
};

#endif // GENETICALGORITHM_H
