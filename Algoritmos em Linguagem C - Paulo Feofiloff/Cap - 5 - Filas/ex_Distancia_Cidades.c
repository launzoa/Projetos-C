#include <stdio.h>
#include <stdlib.h>

int **Matriz_Cidades(int n);

void Liberar(int **matriz, int n);

int *Distancia_cidade(int **matriz, int cidade, int n);


int main()
{
    int n, k;

    printf("Entre com o numero de cidades: ");
    scanf("%d", &n);
    system("cls");

    int **cidades = Matriz_Cidades(n);

    printf("Entre com a cidade que você gostaria de analisar a distancia (baseado em numeros de cidades percorridas): ");
    scanf("%d", &k);
    system("cls");

    int *distancia = Distancia_cidade(cidades, k-1, n);

    Liberar(cidades, n);

    return 0;
}

int **Matriz_Cidades(int n)
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

    printf("|-------------|\n");
    for(i = 0; i < n; i++)
    {
        
        for(j = 0; j < n; j++)
        {
            printf("| %d |", matriz[i][j]);
        }
        printf("\n");
    }
    printf("|-------------|\n");
    system("pause");
    system("cls");
    return matriz;
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

    i = 0;
    int *fila = cidade;

    while (fila != NULL)
    {
        for(j = 0; j < n; j++)
        {
            if(matriz[*fila][j] == 1 && distancia[j] == -1)
            {
                fila[i++] = j;
                distancia[j] = distancia[*fila] + 1;
            }
        }
    }
}   