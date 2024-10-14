#include <stdio.h>
#include <stdlib.h>

int **Matriz_cidades(int n);

void Imprime_matriz(int **matriz, int n);

void Liberar(int **matriz, int n);

int *Distancia_cidade(int **matriz, int cidade, int n);

void Imprime_cidade(int *distancia, int cidade, int n);

int main()
{
    int n, k;

    printf("Entre com o numero de cidades: ");
    scanf("%d", &n);
    system("cls");

    int **cidades = Matriz_cidades(n);

    printf("Entre com a cidade que voce gostaria de analisar a distancia (baseado em numeros de cidades percorridas): ");
    scanf("%d", &k);
    system("cls");

    int *distancia = Distancia_cidade(cidades, k-1, n);

    Imprime_cidade(distancia, k, n);

    Liberar(cidades, n);

    return 0;
}

int **Matriz_cidades(int n)
{
    int i, j, **matriz, c;
    matriz = malloc(n * sizeof(int*));

    for(i = 0; i < n; i++)
    {
        matriz[i] = malloc(n * sizeof(int));

        for(j = 0; j < n; j++) matriz[i][j] = 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("A cidade '%d' tem caminho para qual cidade: ", i+1);
        scanf("%d", &c);
        c-=1;
        matriz[i][c] = 1;
        matriz[c][c] = 1;
            
    }
    
    system("cls");

    Imprime_matriz(matriz, n);

    return matriz;
}


void Imprime_matriz(int **matriz, int n)
{
    int i, j;

    printf("Tabela de conexoes das cidades:\n");
    for(i = 0; i < n; i++) printf("\t     Cidade %d", i+1);
    printf("\n");
    for(i = 0; i < n; i++)
    {   
        printf("Cidade %d", i);
        for(j = 0; j < n; j++) printf("\t%d\t", matriz[i][j]);
        printf("\n");
    }
    system("pause");
    system("cls");
}


void Liberar(int **matriz, int n)
{
    int i;

    for(i = 0; i < n; i++) free(matriz[i]);
    
    free(matriz);
}


int *Distancia_cidade(int **matriz, int cidade, int n)
{
    int i, j;
    int *distancia = malloc(n * sizeof(int));;

    for(i = 0; i < n; i++) distancia[i] = -1;
    
    distancia[cidade] = 0;

    i = 1;
    int *fila = malloc((n+1) * sizeof(int));
    *fila = cidade;
    fila[n] = -1;
    int k = 0;

    while (fila[k] != -1)
    {
        for(j = 0; j < n; j++)
        {
            if(matriz[fila[k]][j] == 1 && distancia[j] == -1)
            {
                fila[i] = j;
                i++;
                distancia[j] = distancia[fila[k]] + 1;
            }
        }
        k++;
    }

    return distancia;
}   


void Imprime_cidade(int *distancia, int cidade, int n)
{
    printf("Tabela das cidades\nA distancia da cidade %d para as demais cidades\n", cidade);
    
    for(int i = 0; i < n; i++)
    {
        if(distancia[i] != -1)
        {
            printf("Cidade %d => Cidade %d, a distancia eh %d\n", cidade, i+1, distancia[i]);
        }
        else
        {
            printf("Não existe caminho da nossa Cidade %d para a Cidade %d", cidade, i+1);
        }
    } 
    printf("\n");
}
