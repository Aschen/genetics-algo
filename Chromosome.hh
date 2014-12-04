#ifndef CHROMOSOME_HH
#define CHROMOSOME_HH

#include "Genetics.hh"

class Chromosome
{
public:
    static const std::string   _nucls;

private:
    std::string             _genes;
    float                   _fitness;
    int                     _score;
    int                     _mutateRate;

public:
    Chromosome(int length);
    Chromosome(const std::string &genes);
    ~Chromosome(void);

public:
    void                    mutate(int popSize);

public:
    const std::string       &getGenes(void) const;
    float                   getFitness(void) const;
    int                     getScore(void) const;
    int                     getLength(void) const;
    void                    setScore(int score);
    void                    setFitness(int total, int popSize);

private:
    char                    getRandomGene(void) const;

};

std::ostream            &operator<<(std::ostream &os, const Chromosome &chr);

#endif // CHROMOSOME_HH
