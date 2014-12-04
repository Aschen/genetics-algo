#ifndef CROSSOVER_HH
#define CROSSOVER_HH

#include "Chromosome.hh"

class Crossover
{
public:
    static std::string      doCrossover(const std::string &p1, const std::string &p2);
    static std::string      doUniformCrossover(const std::string &p1, const std::string &p2);
};

#endif // CROSSOVER_HH
