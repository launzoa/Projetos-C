#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Tam 10


void InsereR(int vetor[], int n, int k, int i);


int main()
{
    int vetor[Tam], n, k, i;

    srand(time(NULL));

    printf("Obs: indice de 1 a 10 e o vetor eh preenchido aleatoriamente com apenas 9 elementos para nao causar estouro ao inserir um novo elemento!\n");
    printf("Entre com o numero e o indice a ser adicionado respectivamente: ");
    scanf("%d%d", &n, &k);
    
    printf("Vetor atual: {");
    for(i = 0; i < Tam-1; i++){
        vetor[i] = rand() % 100;
        printf(" %d ", vetor[i]);
    }
    printf("}\n");

    InsereR(&vetor[0], n, k-1, Tam-1);

    printf("Novo vetor: {");
    for(i = 0; i < Tam; i++)printf(" %d ", vetor[i]);
    printf("}\n");


    return 0;
}


void InsereR(int *ptr, int n, int k, int i)
{
    if(k == i) *(ptr + i) = n;
    else
    {
        *(ptr + i) = *(ptr + i - 1);
        InsereR(ptr, n, k, i -= 1);
    }
}