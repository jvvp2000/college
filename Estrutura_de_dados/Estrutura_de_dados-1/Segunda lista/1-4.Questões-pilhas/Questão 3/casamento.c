#include <stdio.h>
#include <stdlib.h>

#include "../TAD-pilha/pilhaj.h"

int menu(void);
void opcao(node *PILHA, int op);
void exibe(node *PILHA);
void push(node *PILHA);
node *pop(node *PILHA);
void casamento(node *PILHA);
int casa(char x);

int main(void)
{
    node *PILHA = cria_pilha();
    if (!PILHA)
    {
        printf("Sem memoria disponivel!\n");
        exit(1);
    }
    else
    {
        inicia(PILHA);
        int opt;
        do
        {
            opt = menu();
            opcao(PILHA, opt);
        } while (opt);

        free(PILHA);
        return 0;
    }
}

int menu(void)
{
    int opt;

    printf("\nEscolha a opcao\n");
    printf("1. PUSH \n");
    printf("2. POP \n");
    printf("4. Verificar casamento\n");
    printf("Opcao: ");
    scanf("%d", &opt);

    return opt;
}

void opcao(node *PILHA, int op)
{
    node *tmp;
    switch (op)
    {
    case 1:
        push(PILHA);
        break;
    case 2:
        tmp = pop(PILHA);
        break;
    case 4:
        casamento(PILHA);
    default:
        printf("\n");
    }
}

void exibe(node *PILHA)
{
    if (vazia(PILHA))
    {
        printf("PILHA vazia!\n\n");
        return;
    }

    node *tmp;
    tmp = PILHA->prox;

    while (tmp != NULL)
    {
        printf("%4c", tmp->num);
        tmp = tmp->prox;
    }

    printf("\n");
}

void push(node *PILHA)
{

    node *novo = aloca();
    novo->prox = NULL;
    printf("%c", novo->num);
    if (vazia(PILHA))
    {
        PILHA->prox = novo;
    }
    else
    {
        node *tmp = PILHA->prox;

        while (tmp->prox != NULL)
            tmp = tmp->prox;

        tmp->prox = novo;
    }
}

void casamento(node *PILHA)
{
    exibe(PILHA);
    node *ultimo = PILHA->prox,
         *penultimo = PILHA;

    while (ultimo->prox != NULL)
    {
        penultimo = ultimo;
        ultimo = ultimo->prox;
    }

    if (ultimo->num == casa(penultimo->num))
    {
        pop(PILHA);
        pop(PILHA);
        casamento(PILHA);
    }
    
    printf("Casamento feito!");
}

int casa(char x)
{
    switch (x)
    {
    case '[':
        return ']';
        break;
    case '{':
        return '}';
        break;
    case '(':
        return ')';
        break;
    default:
        return 0;
    }
}
