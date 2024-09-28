#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define limite 1000

/*
A função abaixo imprime o piso de um numero seguindo a expressão (i <= n < i + 1), onde n é um inteiro
nesse caso para o piso, será utilizado a notação log2
*/
void piso(int *p_i, int *p_n)
{
    int i, j = 0, log_atual, log_prox;

    for(i = 1; i < limite; i+=2)
    {   
        log_atual = log2(i);
        log_prox = log2(i+1);
        if(log_atual != log_prox)
        {
            *(p_i + j) = i;
            *(p_i + j + 1) = i + 1;
            *(p_n + j) = log2(i);
            *(p_n + j + 1) = log2(i + 1);
            j += 2;
            
        }
    }
}   

int main()
{
    int vetor_i[18], vetor_n[18];
    int *ponteiro_i = &vetor_i[0];
    int *ponteiro_n = &vetor_n[0];

    piso(ponteiro_i, ponteiro_n);

    printf("i  <=  Log2(i) < i+1 < Log2(i+1)");
    printf("\n");

    for(int i = 0; i < 16; i+=2) printf("----");
    printf("\n");

    for(int i = 0; i < 18; i+=2){
        printf("%d  \t  %d  \t  %d  \t  %d\n", vetor_i[i], vetor_n[i], vetor_i[i+1], vetor_n[i+1]);
    }

    return 0;
}