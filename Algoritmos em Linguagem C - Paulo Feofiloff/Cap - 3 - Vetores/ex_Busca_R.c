#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*  Função que recebe um vetor de números inteiros e busca dentro dele se existe um inteiro n
    tal qual: v[0] < n < v[k-1], de forma recursiva*/
int BuscaR(int vetor[], int n, int k);

/*  Função similar a antiga, porém é executada utilizando o laço for*/
int BuscaR_Interativa(int vetor[], int n, int k);


int main()
{

    int vetor[10], i, n;

    srand(time(NULL));

    printf("Entre com o numero que gostaria de buscar: ");
    scanf("%d", &n);

    printf("O vetor gerado aleatoriamente eh: { ");
    for(i = 0; i < 10; i++)
    {
        vetor[i] = rand() % 10;
        printf("%d ", vetor[i]);
    }
    printf("}\n");

    
    int indice = BuscaR(vetor, n, i-1);
    if(indice == -1) printf("Nao foi possivel continuar a busca.\nO elemento %d nao esta presente no vetor!", n);
    else printf("Busca efetivada!\nO elemento %d esta presente no vetor!", n);
    
    printf("\nOutra busca vai ser efetivada!\n");
    
    int indice_i = BuscaR_Interativa(vetor, n, i-1);
    if(indice_i == -1) printf("Nao foi possivel continuar a busca.\nO elemento %d nao esta presente no vetor!", n);
    else printf("Busca efetivada!\nO elemento %d esta presente no vetor!", n);
    return 0;
}


int BuscaR(int vetor[], int n, int k)
{
    if(n == 0) return -1;

    else
    {
        if(vetor[k] == n) return k;
        else
        {
            BuscaR(vetor, n, k-1);
        }
    }
}


int BuscaR_Interativa(int vetor[], int n, int k)
{
    for(k; k >= 0 && vetor[k] != n; k--);

    return k;
}