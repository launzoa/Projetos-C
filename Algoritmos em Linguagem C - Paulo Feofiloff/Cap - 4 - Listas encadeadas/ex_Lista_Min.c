#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//  Estrutura de uma lista encadeada com um inteiro para o conteúdo e um ponteiro para o endereço do próximo elemento
struct lista_encadeada
{

    int conteudo;

    struct lista_encadeada *prox;
};

typedef struct lista_encadeada cedula;

//  Estrutura-Função que busca o menor número da lista encadeada de forma recursiva
cedula *BuscaMin(cedula *lista)
{
    
    if(lista->prox == NULL) return lista;

    cedula *min = BuscaMin(lista->prox);
    if(min->conteudo > lista->conteudo) return lista;
    else return min;
};

//  Estrutura-Função que busca o menor número da lista encadeada de forma interativa
cedula *BuscaMinInterativa(cedula *lista)
{
    cedula *menor = lista;
    while(lista != NULL)
    {
        if(menor->conteudo > lista->conteudo) menor = lista;
        lista = lista->prox;
    }
    return menor;
};

//  Estrutura-Função que libera a memoria que armazenamos
cedula *Liberar(cedula *lista)
{
    if(lista == NULL) return NULL;
    return Liberar(lista->prox);
    free(lista);
};

int main()
{
    srand(time(NULL));
    cedula *HEAD = malloc(sizeof(cedula));
    cedula *A = malloc(sizeof(cedula));
    cedula *B = malloc(sizeof(cedula));
    cedula *C = malloc(sizeof(cedula));
    cedula *D = malloc(sizeof(cedula));
    cedula *E = malloc(sizeof(cedula));
    HEAD->prox = A; 
    A->prox = B;
    B->prox = C;
    C->prox = D;
    D->prox = E;
    E->prox = NULL;

    printf("A lista encadeada eh: {");
    cedula *temp = HEAD->prox;
    while(temp != NULL)
    {   
        temp->conteudo = rand() % 100;
        printf(" %d ", temp->conteudo);
        temp = temp->prox;
    }
    printf("}\n");

    temp = BuscaMin(HEAD->prox);
    printf("O menor valor dessa lista eh: %d", temp->conteudo);

    printf("\nFazendo agora uma busca de forma interativa!\n");
    temp = BuscaMinInterativa(HEAD->prox);
    printf("O menor valor dessa lista eh: %d", temp->conteudo);

    Liberar(HEAD);

    return 0;
}

