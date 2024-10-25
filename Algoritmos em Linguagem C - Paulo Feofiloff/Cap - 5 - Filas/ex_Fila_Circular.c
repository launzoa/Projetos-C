#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5

struct Estrutura_Fila_Circular
{
    int f[N];
    int s;
    int t;

};

typedef struct Estrutura_Fila_Circular Fila;

void Inicializar_Fila(Fila *fila);

void Inserir_Fila(Fila *fila, int valor);

bool Fila_Cheia(Fila *fila);

bool Fila_Vazia(Fila *fila);

void Remove_Fila(Fila *fila);

void Imprime_Fila(Fila *fila);

void Fila_Atual(Fila *fila);

int Ler_Fila();

int main()
{
    Fila Fila_Main;

    Inicializar_Fila(&Fila_Main);

    Imprime_Fila(&Fila_Main);

    return 0;
}


void Inicializar_Fila(Fila *fila)
{
    fila->t = 0;
    fila->s = 0;
}

void Inserir_Fila(Fila *fila, int valor)
{

    if(Fila_Cheia(fila))
    {
        printf("Sua fila esta atualmente cheia\n!nao eh possivel adicionar novos valores\nesvazie a fila ou remova valores");
    }

    else
    {
        fila->f[fila->t] = valor;
        fila->t = (fila->t + 1) % N;
    }

}


bool Fila_Cheia(Fila *fila)
{
    return ((fila->t + 1) % N == fila->s);
}


bool Fila_Vazia(Fila *fila)
{
    return (fila->t == fila->s);
}


void Remove_Fila(Fila *fila)
{
    if(Fila_Vazia(fila)) printf("Fila esta vazia\nnao eh possivel remover elementos");
    else
    {
        fila->s = (fila->s + 1) % N;
    }
}


int Ler_Fila()
{
    int valor;

    printf("Entre com o valor a ser adicionado na fila: ");
    scanf("%d", &valor);

    return valor;
}


void Fila_Atual(Fila *fila)
{
    if (Fila_Vazia(fila)) {
        printf("A fila esta vazia\n");
        return;
    }

    printf("Conteudo da fila: ");
    for (int i = fila->s; i != fila->t; i = (i + 1) % N) {
        printf("%d ", fila->f[i]);
    }
    printf("\n");
}


void Imprime_Fila(Fila *fila)
{
    int op, valor;

    while(1)
    {
        system("cls");
        printf("1 - Inserir valor na fila\n");
        printf("2 - Remover algum valor da fila\n");
        printf("0 - Sair\n");
        printf("Sua posicao atual na fila: %d\n", fila->t);
        Fila_Atual(fila);
        printf("Entre com a sua opcao: ");
        scanf("%d", &op);
        system("cls");

        switch(op)
        {
            case 1:
                valor = Ler_Fila();
                Inserir_Fila(fila, valor);
                break;

            case 2:
                valor = Ler_Fila();
                Remove_Fila(fila);
                break;

            default:
                printf("FIM");
                exit(1);
        }
        
    }
}

