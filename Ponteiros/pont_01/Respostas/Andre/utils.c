#include <stdio.h>
#include "utils.h"

int TrocaInterios(int *n1, int *n2)
{

    if (*n2 < *n1)
    {
        int temp = *n1;
        *n1 = *n2;
        *n2 = temp;

        return 1;
    }

    else
    {

        return 0;
    }
}