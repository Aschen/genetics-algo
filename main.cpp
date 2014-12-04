#include "Chromosome.hh"
#include "Crossover.hh"
#include "Population.hh"
#include "Matingpool.hh"
#include <ctime>
#include "time.h"

int     main(int ac, char **av)
{
    if (ac == 2)
    {
        int     i;
        int     j = 0;
        clock_t t;
        float   moy;
        srand(time(NULL));

        while (j++ < 1)
        {
            i = 1;
            t = clock();
            Population      pop(1500, av[1]);

            while (!pop.solutionFound())
            {
                std::cout << "Generation : " << i << "  " << pop.best() << std::endl;
//                pop.dump();
                pop.nextGeneration();
                i++;
            }
            t = clock() - t;
            moy += static_cast<float>(t) / CLOCKS_PER_SEC;
            std::cout << "Generation : " << i << "  " << pop.best() << "\t\t => FOUND IN " << static_cast<float>(t) / CLOCKS_PER_SEC << std::endl;
        }
        std::cout << "Moyenne : " << moy / 1.0 << std::endl;
    }
    return 0;
}
