#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "simplerandom.h"

int main(int argc, char *argv[])
{
    time_t seed = time(NULL);

    int runs = 1;
    int sameCount;

    for(int c = 1; c <= runs; c++)
    {
        int *abunch = SimpleRandomRange(&seed, 0, 20, 100);
    
        int previous;

        for(int i = 0; i < 100; i++)
        {   
            if(i == 0) 
            {  
                previous = abunch[i];
                continue; 
            }

            if(abunch[i] == previous)
            {
                sameCount++;
            }

            previous = abunch[i];
        }
    }

    printf("%d\n", sameCount);

    return 0;
}
