# S I M P L E  R A N D O M 
## What is?
an easy to import randome number generator that I made for practice
## Dependencies 
just gcc 
## Building 
``` bash 
./build.sh
```
## Usage 
``` c 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "simplerandom.h"

int main(int argc, char *argv[])
{
    // We use the monotonically incrementing time from the standard library
    // as the inital seed.
    // Note, if I use 2 as my seed the value I'll get back will always be the same
    long int seed = time(NULL);

    // how to get a number from 0 to 10 using the seed
    seed = simplerandom(seed);
    int number_between_zero_and_ten = seed % 10;
    printf("number between zero and ten: %d\n", number_between_zero_and_ten);

    // how to get a number that's between two numbers
    int start = 10;
    int end   = 20;
    int number_between_two_numbers  = SimpleRandomBetween(&seed, start, end);
    printf("number between two numbers: %d\n", number_between_two_numbers);

    // how to get a range of numbers that are between two numbers
    int howmany = 10;
    int *range_of_numbers = SimpleRandomRange(&seed, start, end, howmany);
    printf("range of numbers: ");
    for(int i = 0; i < howmany; i++)
    {
        printf("%d ", range_of_numbers[i]);
    }
    printf("\n");

    return 0;
}
```

