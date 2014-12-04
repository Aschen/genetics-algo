#include "Matingpool.hh"

MatingPool::MatingPool(const std::vector<Chromosome*> &pop)
{
    float       floPart;
    int         intPart;

    for (unsigned int i = 0; i < pop.size(); i++)
    {
        intPart = static_cast<int>(pop[i]->getFitness());
        floPart = pop[i]->getFitness() - intPart;
        for (int j = 0; j < intPart; j++)
        {
//            std::cout << "Push " << pop[i]->getGenes() << std::endl;
            _pop.push_back(Chromosome(pop[i]->getGenes()));
        }
        if (!(rand() % static_cast<int>((1/floPart))))
        {
  //          std::cout << "Extra : " << pop[i]->getGenes() << std::endl;
            _pop.push_back(Chromosome(pop[i]->getGenes()));
        }
    }
}

MatingPool::~MatingPool(void)
{
}

void MatingPool::dump(void) const
{
    for (unsigned int i = 0; i < _pop.size(); i++)
    {
        std::cout << _pop[i] << std::endl;
    }
}

Chromosome &MatingPool::getPerson()
{
    int     random = rand() % (_pop.size() - 1);

//    std::cout << "rand : " << random << " " << _pop.size() << std::endl;
    return _pop[random];
}
