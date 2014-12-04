#ifndef POPULATION_HH
#define POPULATION_HH

#include <vector>
#include <algorithm>
#include "Chromosome.hh"
#include "Matingpool.hh"
#include "Crossover.hh"

class Population
{
private:
    std::string                     _searchValue;
    int                             _size;
    std::vector<Chromosome*>        _pop;

public:
    Population(int size, std::string searchValue);
    ~Population(void);

public:
    void                dump(void) const;
    void                evaluate(void);
    void                nextGeneration(void);
    bool                solutionFound(void) const;
    const std::string   &best(void) const;

public:
    const std::vector<Chromosome*>    &get(void) const;

private:
    void            deletePop(void);
};

bool                sortFunc(Chromosome *chr1, Chromosome *chr2);

#endif // POPULATION_HH
