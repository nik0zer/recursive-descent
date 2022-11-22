#include <stdio.h>
#include "calc.h"
#include <stdlib.h>


int main()
{
    char* str;
    scanf("%ms", &str);
    
    int val = get_G(str);

    printf("%d", val);

    free(str);
}