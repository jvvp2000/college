#include <stdlib.h>
#include <stdio.h>
#include "../TAD-pilha/pilhatad.h"

/*
Escreva um programa que converta um número decimal em hexadecimal, usando o
método de divisões sucessivas e uma pilha. Obs. Lembrar que caso o resto da divisão
for 10, 11, 12, 13, 14 ou 15, o digito correspondente deverá ser A, B, C, D, E ou F.
*/

void printVar(int d, int r)
{
    printf("Dec: %d\tRes: %d\n", d, r);
}

int popInt(STACK *stack)
{
    void *aux;
    aux = popStack(stack);
    int *intPtr = (int *)aux;
    return *intPtr;
}

void printStack(STACK *stack)
{
    int aux;
    // STACK *stackaux = createStack();
    while (!emptyStack(stack))
    {
        aux = popInt(stack);
        printf("%c ", aux);
    }
}

int casos(int r)
{
    switch (r)
    {
    case 10:
        return 'A';

    case 11:
        return 'B';

    case 12:
        return 'C';

    case 13:
        return 'D';

    case 14:
        return 'E';

    case 15:
        return 'F';

    default:
        return r + 48;
    }
    return 0;
}

int main()
{

    STACK *stack;
    stack = createStack();
    int decimal = 438;
    int resto = 0;
    int *restop;

    while (decimal > 0)
    {
        resto = decimal % 16;
        decimal = decimal / 16;
        resto = casos(resto);

        restop = (int *)malloc(sizeof(int));
        *restop = resto;

        pushStack(stack, restop);
        // printVar(decimal, resto);
    }
    printf("-----------------------------\n");
    printStack(stack);
}