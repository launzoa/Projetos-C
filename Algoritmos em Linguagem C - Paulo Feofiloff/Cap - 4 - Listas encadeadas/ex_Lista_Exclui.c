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

//  Estrutura-Função que busca o excluir a cedula de determinado indíce
cedula RemoveLista(cedula *lista)
{
    cedula *lixo = lista->prox;

    if(lixo->prox == NULL) lista->prox = NULL;
    else lista->prox = lixo->prox;

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
    int i,n;
    srand(time(NULL));
    
    cedula *HEAD[6];
    HEAD[0] = malloc(sizeof(cedula));

    for(i = 1; i < 6; i++)
    {
        HEAD[i] = malloc(sizeof(cedula));
        HEAD[i-1]->prox = HEAD[i];
    }
    HEAD[i-1]->prox = NULL;
     
    printf("A lista encadeada eh: {");
    cedula *temp = HEAD[0]->prox;
    while(temp != NULL)
    {   
        temp->conteudo = rand() % 100;
        printf(" %d ", temp->conteudo);
        temp = temp->prox;
    }
    printf("}\n");

    printf("Escolha um indice de 1 a 5 para ser excluido: ");
    scanf("%d", &n);
    
    printf("A nova lista encadeada eh: {");

    RemoveLista(HEAD[n-1]);
    temp = HEAD[0]->prox;
    while(temp != NULL)
    {   
        printf(" %d ", temp->conteudo);
        temp = temp->prox;
    }
    printf("}\n");

    Liberar(HEAD[0]);

    return 0;
}

