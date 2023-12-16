#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "operations.h"
#include "read_numbers.h"
#include "print_numbers.h"

int main()
{
    printf("Введите выражение: ");
    char *line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    char oper;
    char num1[50], num2[50];
    long result1, result2, result;
    int base1 = 0;
    int base2 = 0;
    if (strchr(line, '~') == NULL)
    {
        sscanf(line, "%s %c %s", &num1, &oper, &num2);
         result1 = readNum(num1, &base1);
         result2 = readNum(num2, &base2);
         if (base1 != base2)
         {
            fprintf(stderr, "Ошибка! Системы счисления не совпадают.\n"); 
            exit(EXIT_FAILURE);
         }
         result = operations(result1, oper, result2);
         printNumbers(result, base1);
    }
    else
    {
        sscanf(line, "%c%s", &oper, &num1);
        result1 = readNum(num1, &base1);
        result = operations(result1, oper, 0);
        printNumbers(result, base1);
    }
    free(line);
    return 0;
}
