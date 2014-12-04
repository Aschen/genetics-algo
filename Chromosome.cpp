#include "Chromosome.hh"

const std::string    Chromosome::_nucls = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!?:;,()'\\/-_ ";

Chromosome::Chromosome(int length) : _genes(""), _fitness(0.0), _score(0)
{
    for (int i = 0; i < length; i++)
    {
        _genes += getRandomGene();
    }
}

Chromosome::Chromosome(const std::string &genes) : _genes(genes), _fitness(0.0), _score(0), _mutateRate(1 / 1 / genes.length())
{
}

Chromosome::~Chromosome(void)
{
}

void Chromosome::mutate(int popSize)
{
    for (unsigned int i = 0; i < _genes.length(); i++)
    {
        if (!(rand() % popSize))
        {
            _genes[i] = getRandomGene();
        }
    }
}

/*
 */

const std::string &Chromosome::getGenes(void) const
{
    return _genes;
}

float Chromosome::getFitness(void) const
{
    return _fitness;
}

int Chromosome::getScore(void) const
{
    return _score;
}

int Chromosome::getLength(void) const
{
    return _genes.length();
}

void Chromosome::setScore(int score)
{
    _score = score;
}

void Chromosome::setFitness(int total, int popSize)
{
    _fitness = static_cast<float>(_score) / static_cast<float>(total) * popSize;
    if (total == 0)
        _fitness = 0.0;
}

char Chromosome::getRandomGene(void) const
{
    return _nucls[rand() % _nucls.length()];
}


/*
 */

std::ostream            &operator<<(std::ostream &os, const Chromosome &chr)
{
    if (os == std::cout)
    {
        os << chr.getGenes() << "  Fit: " << chr.getFitness() << " Score : " << chr.getScore();
    }
    return os;
}
