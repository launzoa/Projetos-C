#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct lista_encadeada {

    int conteudo;

    struct lista_encadeada *prox;
};

typedef struct lista_encadeada cedula;

cedula *ListaInsere(cedula *lista, int n)
{
    cedula *novo = malloc(sizeof(cedula));
    novo->prox = lista->prox;
    lista->prox = novo;
    novo->conteudo = n;
    
};

cedula *Liberar(cedula *lista)
{
    if(lista == NULL) return NULL;
    else
    {
        Liberar(lista->prox);
        free(lista);
    }
};

int main()
{   
    int i, n, k;
    srand(time(NULL));

    cedula *lista[7];
    lista[0] = malloc(sizeof(cedula));

    printf("A lista encadeada tem os seguintes elementos -> {");
    for(i = 1; i < 6; i++)
    {   
        lista[i] = malloc(sizeof(cedula));
        lista[i]->conteudo = rand() % 100;
        lista[i-1]->prox = lista[i]; 
        printf(" %d ", lista[i]->conteudo);
    }
    printf("}\n");
    lista[i-1]->prox = NULL; 

    printf("Entre com o numero a ser adicionado na lista: ");
    scanf("%d", &n);
    printf("Entre com o indice para adicionar o numero (OBS: 1 a 6): ");
    scanf("%d", &k);

    ListaInsere(lista[k-1], n);

    printf("A lista apos a insercao ficou -> {");
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