#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

/*  A função recebe o vetor e o seu tamanho e utilizando o pensamento recursivo segue a linha de raciocínio ->
    Caso-base: n == 0, onde é recebido o valor do primeiro número do vetor como sendo o maior;
    Caso recursivo: Comparar o atual maior valor com o atual valor do vetor
    Logo, a função percorre o nosso vetor do índice 10 até 0 e compara os valores de 0 até 10 para encontrar o maior!
*/
int Maximo_R(int vetor[], int indice);

/*  A função revisa e busca o maior valor, porém de forma interativa utilizando o laço for*/
int Revisar_Maior(int vetor[], int indice);


int main()
{
    int vetor[10], m_r, m_i;

    srand(time(NULL));

    for(int i = 0; i < 10; i++){
        vetor[i] = rand() % 100;
    }

    m_r = Maximo_R(vetor, 9);
    printf("Utilizando a recursividade vamos resolver o seguinte problema ->");
    printf("\nO maior numero dentro do vetor eh o %d\n", m_r);

    printf("\nTeste para revisar os elementos do vetor e ver se '%d' eh o maior valor\n\n", m_r);
    m_i = Revisar_Maior(vetor, 9);
    printf("\nO maior elemento apos a revisao eh: %d",  m_i);

    if(m_r == m_i) printf("\n\nResultado correto e esperado!");
    else printf("\n\nErro no codigo...");

    return 0;
}


int Maximo_R(int vetor[], int indice)
{
    if(indice == 0)
    {
        return vetor[0];
    }

    else
    {
        int maior = Maximo_R(vetor, indice - 1);

        if(maior > vetor[indice])
        {
            return maior;
        }
        else{
            return vetor[indice];
        }
    }
}


int Revisar_Maior(int vetor[], int indice){
    int i, maior = vetor[0];
    printf("O vetor -> {%d", vetor[0]);
    for(i = 1; i <= indice; i++){
        if(maior < vetor[i]) maior = vetor[i];
        printf(", %d", vetor[i]);
    }
    printf("}");
    return maior;
}