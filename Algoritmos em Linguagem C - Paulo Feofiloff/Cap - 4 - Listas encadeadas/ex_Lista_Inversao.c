#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct lista_encadeada
{
    int conteudo;
    struct lista_encadeada *prox;
};

typedef struct lista_encadeada cedula;


cedula *ListaInverte(cedula *lista, cedula *head)
{
    if(lista == NULL) return head;
    if(lista->prox == NULL){
        head->prox = lista;
        return lista;
    }
    cedula *inv = ListaInverte(lista->prox, head);
    inv->prox = lista;
    lista->prox = NULL;

    return lista;
};


void Liberar(cedula *lista)
{
    if(lista == NULL) return;
    Liberar(lista->prox);
    free(lista);
};


int main()
{   
    int i;

    cedula *lista[6];
    lista[0] = malloc(sizeof(cedula));
    
    srand(time(NULL));

    printf("A lista encadeada tem os seguintes valores -> {");
    for(i = 1; i < 6; i++)
    {
        lista[i] = malloc(sizeof(cedula));
        lista[i]->conteudo = rand() % 10;
        lista[i-1]->prox = lista[i];
        printf(" %d ", lista[i]->conteudo);
    }
    lista[i-1]->prox = NULL;
    printf("}\n");

    ListaInverte(lista[0]->prox, lista[0]);

    printf("A lista encadeada invertida ficou com os seguintes valores -> {");
    cedula *temp = lista[0]->prox;
    while(temp != NULL)
    {
        printf(" %d ", temp->conteudo);
        temp = temp->prox;
    }
    printf("}\n");

    Liberar(lista[0]);
    return 0;
}