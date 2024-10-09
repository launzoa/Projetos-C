#include <stdlib.h>
#include <stdio.h>


struct lista_encadeada_dupla
{   
    int estado;
    struct lista_encadeada_dupla *proximo;
    struct lista_encadeada_dupla *anterior;
};
typedef struct lista_encadeada_dupla cedula;

cedula *Inserir_lista(cedula *lista, int tamanho, int i);

void Liberar(cedula *lista);

void Ler_circulo(cedula *lista, int tamanho);

cedula *Concatenar_circulo(cedula *lista);

void Josephus(cedula *lista, int k);


int main()
{
    int n, k;

    printf("Entre com o numero de pessoas na roda circular: ");
    scanf("%d", &n);

    printf("Entre com o fator do problema de Josephus: ");
    scanf("%d", &k);

    cedula *circulo  = Inserir_lista(NULL, n, 1);
    circulo->anterior = Concatenar_circulo(circulo);
    Concatenar_circulo(circulo)->proximo = circulo;

    Josephus(circulo, k);
    
    Liberar(circulo);

   return 0; 
}


cedula *Inserir_lista(cedula *lista, int tamanho, int i)
{
    if(tamanho == 0) return NULL;

    cedula *novo = malloc(sizeof(cedula));
    novo->estado = i;
    novo->anterior = lista;
    novo->proximo = Inserir_lista(novo, tamanho-1, i+1);

    return novo;
};


void Liberar(cedula *lista)
{ 
    if(lista == NULL) return;

    Liberar(lista->proximo);
    free(lista);
}


void Ler_circulo(cedula *lista, int tamanho)
{
    if(tamanho == 0) printf("\n");
    else
    {
        printf(" %c ", lista->estado);
        Ler_circulo(lista->proximo, tamanho-1);
    }
}


cedula *Concatenar_circulo(cedula *lista)
{
    if(lista->proximo == NULL) return lista;

    return Concatenar_circulo(lista->proximo);
}


void Josephus(cedula *lista, int k)
{   
    int i = 1;
    while(lista != lista->proximo)
    {
        if(i == k)
        {
            i = 1;
            cedula *prox = lista->proximo;
            cedula *antes = lista->anterior;
            prox->anterior = antes;
            antes->proximo = prox;
            
        }
        else i++;

        lista = lista->proximo;
    }
    printf("O ultimo elemento foi: %d", lista->estado);
}