#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

/* A função recebe um vetor de inteiros n e o seu tamanho e faz a soma dos seus dígitos*/
int Somar_Digitos(int n[], int indice);

/* A função recebe o número em inteiro, converte para um vetor de inteiros utilizando o resto da divisão de inteiros*/
void Vetor_Digitos(int *n, int valor, int *vetor, int i);

int main()
{
    int n, m, array[10], i;

    srand(time(NULL));

    n = rand() % 10000;
    m = n;
    Vetor_Digitos(&m,  1,  array,  0);

    for(i = 0; array[i] != -1; i++);

    printf("A soma dos digitos para o numero %d eh: %d", n, Somar_Digitos(array, i-1));

    return 0;
}


int Somar_Digitos(int n[], int indice)
{
    if(indice == 0){
        return n[indice];
    }
    return n[indice] + Somar_Digitos(n, indice - 1);
}


void Vetor_Digitos(int *n, int valor, int *vetor, int i)
{
   if(valor*10 > n)
   {
        
        int resto = *n / valor;
        *(vetor + i) = resto;
        *n -= resto*valor;

        *(vetor + i + 1) = -1;
   }
   else
   {
        Vetor_Digitos(n, valor*10, vetor, i+1);
        int resto = *n / valor;
        
        *(vetor + i) = resto;
        *n -= resto*valor;

   }
}
