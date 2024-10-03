#include <stdio.h>
#include <stdlib.h>

//  Estrutura de uma lista encadeada com um inteiro para o conteúdo e um ponteiro para o endereço do próximo elemento
struct lista_encadeada
{

    int conteudo;

    struct lista_encadeada *prox;
};

typedef struct lista_encadeada cedula;

int main()
{
    cedula *A = malloc(sizeof(cedula));
    A->conteudo = 1;
    A->prox = NULL;

    cedula *B = malloc(sizeof(cedula));
    B->conteudo = 2;
    B->prox = NULL;
    A->prox = B;

    cedula *C = malloc(sizeof(cedula));
    C->conteudo = 3;
    C->prox = NULL;
    B->prox = C;

    cedula *D = malloc(sizeof(cedula));
    D->conteudo = 4;
    D->prox = NULL;
    C->prox = D;

    cedula *temp = A;
    while(temp != NULL)
    {
        printf("%d -> ", temp->conteudo);
        temp = temp->prox;
    }

    temp = A;
    while(temp != NULL)
    {
        cedula *proximo = temp->prox;
        free(temp);
        temp = proximo;
    }

    return 0;
}

