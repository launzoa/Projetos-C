#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct lista_encadeada
{
    int conteudo;
    struct lista_encadeada *prox;
};

typedef struct lista_encadeada cedula;

//  Estrutura-Função que recebe um vetor de inteiros e cria uma lista encadeada para esses inteiros de modo recursivo
cedula *VetorparaLista(int vetor[], int tam, int i)
{
    if(i > tam) return NULL;

    cedula *novo = malloc(sizeof(cedula));
    novo->conteudo = vetor[i];
    novo->prox = VetorparaLista(vetor, tam, i+1);

    return novo;
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
    int i, vetor[5];

    srand(time(NULL));

    cedula *head;
    head = malloc(sizeof(cedula));

    printf("O vetor tem os seguintes elementos -> {");
    for(i = 0; i < 5; i++)
    {   
        vetor[i] = rand() % 10;
        printf(" %d ", vetor[i]);
    }
    printf("}\n");

    head->prox = VetorparaLista(vetor, i-1, 0);

    printf("A lista encadeada assume os valores do vetor e tem os seguintes elementos -> {");
    cedula *temp = head->prox;
    while(temp != NULL)
    {   
        
        printf(" %d ", temp->conteudo);
        temp = temp->prox;
    }
    printf("}\n");

    Liberar(head);
    return 0;   
}