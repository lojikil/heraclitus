#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* from my gist: https://gist.github.com/lojikil/5228011 */
uint64_t
fnv(char *key, uint32_t len)
{
    uint64_t hash = 14695981039346656037;
    uint32_t idx = 0;
    for(; idx < len; idx++)
    {
        hash *= 1099511628211;
        hash ^= key[idx];
    }
    return hash;
}

uint64_t
fnv1a(char *key, uint32_t len)
{
    uint64_t hash = 14695981039346656037;
    uint32_t idx = 0;
    for(; idx < len; idx++)
    {
        hash ^= key[idx];
        hash *= 1099511628211;
    }
    return hash;
}

uint32_t
ul_strlen(char *s)
{
    uint32_t i = 0;
    while(s[i] != '\0') i++;
    return i;
}

int
main(int ac, char **al)
{
    if(ac < 2)
    {
        printf("usage: fnv <key>\n");
        return 1;
    }
    for(int idx = 1; idx < ac; idx++) {
        printf("%llx\n", fnv(al[idx], ul_strlen(al[idx])));
        printf("%llx\n", fnv1a(al[idx], ul_strlen(al[idx])));
    }
    return 0;
}
