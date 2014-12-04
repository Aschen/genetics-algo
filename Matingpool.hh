#ifndef MATINGPOOL_HH
#define MATINGPOOL_HH

#include <vector>
#include <cmath>
#include "Chromosome.hh"

class MatingPool
{
private:
    std::vector<Chromosome>        _pop;

public:
    MatingPool(const std::vector<Chromosome*> &pop);
    ~MatingPool(void);

public:
    void        dump(void) const;
    Chromosome  &getPerson(void);
};

#endif // MATINGPOOL_HH
