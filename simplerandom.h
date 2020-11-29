#define NORMAL_TEXT  "\033[0m"
#define BOLD_TEXT    "\033[1m"
#define BLACK_TEXT   "\033[30;1m"
#define RED_TEXT     "\033[31;1m"
#define GREEN_TEXT   "\033[32;1m"
#define YELLOW_TEXT  "\033[33;1m"
#define BLUE_TEXT    "\033[34;1m"
#define MAGENTA_TEXT "\033[35;1m"
#define CYAN_TEXT    "\033[36;1m"
#define WHITE_TEXT   "\033[37;1m"

#if 1
long int simplerandom(long int seed)
{
    seed ^= seed << (seed % 15) + 15;
    seed ^= seed >> (seed % 5)  + 5;
    seed ^= seed << (seed % 3)  + 3;
    if(seed < 0) seed *= -1;
        
    return seed;
}
#else
long int simplerandom(long int seed)
{
    seed ^= seed << 45;
    seed ^= seed >> 15;
    seed ^= seed << 5;
    seed ^= seed >> 3;
    if(seed < 0) seed *= -1;
        
    return seed;
}
#endif

int SimpleRandomBetween(long int *seed, int start, int end)
{
    *seed = simplerandom(*seed);

    int range = end - start;
    
    return (*seed % range) + start;
}

int *SimpleRandomRange(long int *seed, int start, int end, int howmany)
{
    int *ret = (int *)malloc(howmany * sizeof(int));

    int range = end - start;

    for(int i = 0; i < howmany; i++)
    {
        *seed = simplerandom(*seed);
        ret[i] = (*seed % range) + start;
    }

    return ret;
}
