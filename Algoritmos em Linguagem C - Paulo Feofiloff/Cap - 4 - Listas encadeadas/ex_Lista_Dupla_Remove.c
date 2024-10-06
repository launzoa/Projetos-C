#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 5

struct lista_dupla_encadeada
{
    int conteudo;
    struct lista_dupla_encadeada *prox;
    struct lista_dupla_encadeada *anterior;

};

typedef struct lista_dupla_encadeada cedula;


void ListaRemove(cedula *lista, int i, int n)
{
    if(i == n)
    {
          if(i == TAMANHO)
        {
            lista->anterior->prox = NULL;
            free(lista); 
        }
        else
        {
            lista->anterior->prox = lista->prox;
            lista->prox->anterior = lista->anterior;
            free(lista);
        }        
    }
    else ListaRemove(lista->prox, i+1, n);
};


cedula *PreencheLista(cedula *head, int tam)
{
    if(tam == 0) return NULL;

    cedula *novo = malloc(sizeof(cedula));
    novo->conteudo = rand() % 10 + 1;
    novo->anterior = head;
    novo->prox = PreencheLista(novo, tam-1);

    return novo;
};

void LerLista(cedula *lista)
{
    printf("A lista encadeada dupla -> {");
    while(lista != NULL)
    {
        printf(" %d ", lista->conteudo);
        lista = lista->prox;
    }
    printf("}\n");
}

void Liberar(cedula *lista)
{
    if(lista == NULL) return;
    else
    {
        Liberar(lista->prox);
        free(lista);
    }
};


int main()
{
    int n;
    
    srand(time(NULL));

    cedula *head = malloc(sizeof(cedula));
    head->anterior = NULL;

    head->prox = PreencheLista(head, TAMANHO);
    LerLista(head->prox);

    printf("Entre com o indice que deseja remover da lista (OBS: 1 a 5): ");
    scanf("%d", &n);

    ListaRemove(head->prox, 1, n);

    LerLista(head->prox);

    Liberar(head);

    return 0;
}