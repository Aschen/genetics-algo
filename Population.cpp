#include "Population.hh"

Population::Population(int size, std::string searchValue) : _searchValue(searchValue), _size(size)
{
    for (int i = 0; i < size; i++)
    {
        _pop.push_back(new Chromosome(searchValue.length()));
    }
    evaluate();
}

Population::~Population(void)
{
    deletePop();
}

void Population::dump(void) const
{
    for (unsigned int i = 0; i < _pop.size(); i++)
    {
        std::cout << *_pop[i] << std::endl;
    }
}

void Population::evaluate(void)
{
    int     total = 0;
    int     score;

    for (unsigned int i = 0; i < _pop.size(); i++)
    {
        score = 0;
        for (int j = 0; j < _pop[i]->getLength(); j++)
        {
            if (_pop[i]->getGenes()[j] == _searchValue[j])
            {
                score++;
            }
        }
        total += score;
        _pop[i]->setScore(score);
    }
    for (unsigned int i = 0; i < _pop.size(); i++)
    {
        _pop[i]->setFitness(total, _size);
    }
    std::sort(_pop.begin(), _pop.end(), sortFunc);
}

void Population::nextGeneration(void)
{
    MatingPool                  pool(_pop);
    std::vector<Chromosome*>    new_pop;
    std::vector<Chromosome*>    elite;
    Chromosome                  *child;

    for (int i = 0; i < 4; i++)
    {
        elite.push_back(_pop.back());
        _pop.pop_back();
    }
    for (int i = 0; i < _size; i++)
    {
        child = new Chromosome(Crossover::doUniformCrossover(pool.getPerson().getGenes(), pool.getPerson().getGenes()));
        child->mutate(_size);
        new_pop.push_back(child);
    }
    deletePop();
    _pop = new_pop;
    _pop.insert(_pop.begin(), elite.begin(), elite.end());
    evaluate();
}

bool Population::solutionFound(void) const
{
    for (int i = 0; i < _size; i++)
    {
        if (_searchValue == _pop[i]->getGenes())
            return true;
    }
    return false;
}

const std::string &Population::best() const
{
    return _pop[_size - 1]->getGenes();
}

const std::vector<Chromosome*> &Population::get(void) const
{
    return _pop;
}

void Population::deletePop(void)
{
    for (unsigned int i = 0; i < _pop.size(); i++)
    {
        delete _pop[i];
    }
}

/*
 *
 */
bool                sortFunc(Chromosome *chr1, Chromosome *chr2)
{
    return chr1->getScore() < chr2->getScore();
}


