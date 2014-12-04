#include "Crossover.hh"

std::string Crossover::doCrossover(const std::string &p1, const std::string &p2)
{
    int             point1 = 1 + (rand() % (p1.length() - 1));
    int             point2 = 1 + (rand() % (p1.length() - 1));
    std::string     newGenes("");

    if (point1 > point2)
        std::swap(point1, point2);

    newGenes += p1.substr(0, point1 + 1);
    newGenes += p2.substr(point1 + 1, point2 - point1);
    newGenes += p1.substr(point2 + 1, p1.length() - 1);

    return newGenes;
}

std::string Crossover::doUniformCrossover(const std::string &p1, const std::string &p2)
{
    std::string     newGenes("");

    for (unsigned int i = 0; i < p1.length(); i++)
    {
        if (rand() % 2)
            newGenes += p1[i];
        else
            newGenes += p2[i];
    }

    return newGenes;
}
