#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

/*  A função recebe um vetor e reformula o vetor 'removendo' os zeros
    Através de ponteiros, manipula o vetor - Função feita de forma recursiva */
int RemoveZeros(int *ptr, int i);


int main()
{
    int vetor[TAM], i;

    srand(time(NULL));
    
    printf("Vetor atual: {");
    for(i = 0; i < TAM; i++) 
    {
        vetor[i] = rand() % 3;
        printf(" %d ", vetor[i]);
    }
    printf("}\n");

    int tam = RemoveZeros(&vetor[0], TAM-1);

    printf("Novo vetor: {");
    for(i = 0; i < tam; i++) printf(" %d ", vetor[i]);
    printf("}\n");

    return 0;
}


int RemoveZeros(int *ptr, int i)
{
    if(i == 0) return 0;
   
    int m = RemoveZeros(ptr, i-1);

    if(*(ptr + i) != 0)
    {
        *(ptr + m) = *(ptr + i);
        return m + 1;
    }
    else return m;
    
}