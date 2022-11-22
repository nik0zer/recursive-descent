#include <string.h>
#include <assert.h>
#include "calc.h"
#include <stdio.h>

int get_N(char **smb_ptr)
{
    int val = 0;
    const char* smb_ptr_0 = *smb_ptr;

    while((**smb_ptr <= '9') && (**smb_ptr >= '0'))
    {
        val *= 10;
        val += **smb_ptr - '0';

        
        (*smb_ptr)++;
    }

    assert(*smb_ptr != smb_ptr_0);

    return val;

}

int get_P(char **smb_ptr)
{
    int val = 0;

    if((**smb_ptr) ==  '(')
    {
        (*smb_ptr)++;
        val = get_E(smb_ptr);
        assert((**smb_ptr) ==  ')');
        (*smb_ptr)++;
    }
    else
    {
        val = get_N(smb_ptr);
    }

    return val;
}

int get_T(char **smb_ptr)
{
    int val = 0;

    val = get_P(smb_ptr);

    while ((**smb_ptr) ==  '*' || (**smb_ptr) ==  '/')
    {
        int op = ((**smb_ptr) ==  '*') ? 1 : -1;
        (*smb_ptr)++;
        val = (op == 1) ? val * get_P(smb_ptr) : val / get_P(smb_ptr);
    }

    

    return val;
}

int get_E(char **smb_ptr)
{
    int val = 0;

    val += get_T(smb_ptr);

    while((**smb_ptr) ==  '+' || (**smb_ptr) ==  '-')
    {
        int op = ((**smb_ptr) ==  '+') ? 1 : -1;
        (*smb_ptr)++;
        val += op * get_T(smb_ptr);
    }
    
    return val;
}

int get_G(char* calc_str)
{
    int val = 0;
    char* smb_ptr = calc_str;

    val = get_E(&smb_ptr);
    assert(*smb_ptr == '\0');
    return val;

}