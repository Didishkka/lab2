#include "read_numbers.h"

long readNum(char *num, int *base)
{
    int i = 0;
    bool znak = false;
    if (num[0] == '-')
    {
        znak = true;
        i++;
    }
    if (num[i] == '0')
    {
	if (strlen(num) == 1)
	{
		*base = 2;
	}
	else
        if (tolower(num[i + 1]) == 'x')
        {
            *base = 16;
            i += 2;
        }
        else
        {
            *base = 8;
            i++;

        }
    }
    else
    {
        *base = 2;
    }
    long res = 0;
    for (; num[i] != '\0'; i++)
    {
	res *= *base;
	if (num[i] != '1' && num[i] != '0' && *base == 2)
	{
		fprintf(stderr, "Ошибка! Недопустимое число.\n"); 
        	exit(EXIT_FAILURE);
	}
	if ((num[i] > '7' || num[i] < '0') && *base == 8)
	{
		fprintf(stderr, "Ошибка! Недопустимое число.\n"); 
        	exit(EXIT_FAILURE);
	}
        if (num[i] >= '0' && num[i] <= '9')
        {
            res += num[i] - '0';
        }
        else 
	if ((tolower(num[i]) >= 'a' && tolower(num[i]) <= 'f') && (*base == 16))
        {
            if (tolower(num[i]) >= 'a')
            {
                res += tolower(num[i]) - 'a' + 10;
            }
        }
        else
	{
            fprintf(stderr, "Ошибка! Недопустимое число.\n"); 
            exit(EXIT_FAILURE);
        }
    }
    if (znak)
    {
        return -res;
    }
    else
    {
        return res;
    }
}
