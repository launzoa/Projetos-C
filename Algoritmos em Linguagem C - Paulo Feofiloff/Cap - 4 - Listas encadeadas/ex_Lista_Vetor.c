#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct lista_encadeada
{
    int conteudo;
    struct lista_encadeada *prox;
};

typedef struct lista_encadeada cedula;

//  Estrutura-Função que recebe uma lista encadeada de inteiros e repassa esses inteiros para um vetor
//  através de um ponteiro de modo recursivo
cedula *ListaparaVetor(int *ptr, cedula *lista, int i)
{
    if(lista == NULL) return;
    
    *(ptr + i) = lista->conteudo; 
    ListaparaVetor(ptr, lista->prox, i+1);
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
    int i, vetor[5], *ptr = &vetor[0];

    srand(time(NULL));

    cedula *lista[6];
    lista[0] = malloc(sizeof(cedula));
    
    printf("A lista encadeada tem os seguintes elementos -> {");
    for(i = 1; i < 6; i++)
    {   
        lista[i] = malloc(sizeof(cedula));
        lista[i]->conteudo = rand() % 10;
        lista[i-1]->prox = lista[i];
        printf(" %d ", lista[i]->conteudo);
    }
    printf("}\n");
    lista[i-1]->prox = NULL;
    
    ListaparaVetor(ptr, lista[1], 0);
    Liberar(lista[0]);

    printf("O vetor tem os seguintes elementos -> {");
    for(i = 0; i < 5; i++)
    {   
        printf(" %d ", vetor[i]);
    }
    printf("}\n");

    return 0;   
}