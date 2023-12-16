#include "print_numbers.h"
void inBinary(long res)
{
    int bin[65];
    int i = 0;
    long temp = res;
    while (temp > 0)
    {  
        bin[i++] = temp % 2;
        temp /= 2;
    }
    if (res == 0)
    {
        printf("0");
    }
    else
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", bin[j]);
    }
}
void printNumbers(long res, int base)
{
    bool znak = false;
    if (res < 0)
    {
        printf("-");
        res *= -1;
        znak = true;
    }
    if (base == 16)
    {
        printf("0x%lx", res);
    }
    if (base == 8)
    {
        printf("0%lo", res);
    }
    if (base == 2)
    {
        inBinary(res);
    }
    if (znak)
    {
        res *= -1;
    }
    printf(" (%ld)\n", res);
}
