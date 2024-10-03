#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//  Estrutura de uma lista encadeada com um inteiro para o conteúdo e um ponteiro para o endereço do próximo elemento
struct BuscaSemCabeca
{
    int conteudo;
    struct BuscaSemCabeca *prox;

};

typedef struct BuscaSemCabeca cedula;

//  Estrutura-Função que recebe uma lista encadeada e percorre por ela. Caso encontre o elemento x ela retorna seu endereco, caso contrario retornara null
cedula *Busca(cedula *lista, int x)
{
    if(lista == NULL) return NULL;

    if(lista->conteudo == x) return lista;

    return Busca(lista->prox, x);
};

//  Estrutura-Função para liberar a memoria armazenada por malloc 
cedula *Liberar(cedula *lista)
{
    if(lista == NULL) return NULL;

    cedula *proximo = lista->prox;
    free(lista);
    return Liberar(proximo);
};


int main()
{
    int n;

    srand(time(NULL));
    printf("Obs(1 <= n <= 10)\nEntre com o elemento que gostaria de procurar na lista: ");
    scanf("%d", &n);
    
    cedula *A = malloc(sizeof(cedula));
    cedula *B = malloc(sizeof(cedula));
    cedula *C = malloc(sizeof(cedula));
    cedula *D = malloc(sizeof(cedula));
    cedula *E = malloc(sizeof(cedula));
    A->prox = B;
    B->prox = C;
    C->prox = D;
    D->prox = E;
    E->prox = NULL;

    printf("A lista encadeada eh: {");
    cedula *temp = A;
    while(temp != NULL)
    {
        temp->conteudo = (rand() % 10) + 1;
        printf(" %d ", temp->conteudo);
        temp = temp->prox;
    }
    printf("}\n");

    cedula *resultado = Busca(A, n);
    if(resultado != NULL) printf("O numero esta contido na lista!");
    else printf("ERROR! o numero nao esta contido na lista");

    Liberar(A);

    return 0;
}