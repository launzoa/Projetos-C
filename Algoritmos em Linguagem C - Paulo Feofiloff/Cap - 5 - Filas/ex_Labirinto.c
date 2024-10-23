#include <stdio.h>
#include <stdlib.h>

int **Matriz(int n);

void Imprime_Matriz(int **matriz, int n);

void Labirinto(int **matriz, int n);

void Liberar(int **matriz, int n);

int main()
{
    int n = 5;

    int **matriz = Matriz(n);

    Imprime_Matriz(matriz, n); 
    
    Labirinto(matriz, n);

    Liberar(matriz, n);
}

int **Matriz(int n)
{
    int i, j;

    int labirinto[5][6] = {
    { 0,-1, 0, 0, 0, -1},
    { 0,-1, 0,-1, 0, -1},
    { 0, 0, 0,-1, 0, -1},
    { 0,-1,-1,-1, 0, -1},
    { 0, 0, 0, 0, 1, -1}
    };

    int **matriz = malloc(n * sizeof(int*));
    matriz[0] = malloc((n * n + n) * sizeof(int));

    for(i = 0; i < n; i++) 
    {
        matriz[i] = matriz[0] + i * (n+1);
        for(j = 0; j < n+1; j++)
        {
            matriz[i][j] = labirinto[i][j];
        }
    }


    return matriz;
}


void Labirinto(int **matriz, int n)
{
    int cima, baixo, direita, esquerda, k = 0, i = 0, primeiro = 1, distancia = 0;
    
    int *fila = malloc(n * n * sizeof(int));
    int *formiga;
    formiga = fila[0] = &matriz[0][0];
    
    while(i <= k)
    {   
        cima = *(formiga - n - 1);
        if(cima == 0)
        {
            fila[++k] = &*(formiga - n - 1);
        }

        baixo = *(formiga + n + 1);
        if(baixo == 1 && primeiro == 1)
        {
            distancia = i; 
            primeiro++;
        } 
        if(baixo == 0 )
        {
            fila[++k] = &*(formiga + n + 1);
        }

        direita = *(formiga + 1);
        if(direita == 1 && primeiro == 1)
        {
            distancia = i; 
            primeiro++;
        } 
        if(direita == 0)
        {
            fila[++k] = &*(formiga + 1);
        }

        esquerda = *(formiga - 1);
        if(esquerda == 0)
        {
            fila[++k] = &*(formiga - 1);
        }

        
        *formiga = 2;

        formiga = fila[++i];

        Imprime_Matriz(matriz, n);
        
    }

    free(fila);
    printf("O labirinto foi percorrido!\nA distancia mais rapida do inicio ate o fim foi de %d passos", i-distancia);
}


void Imprime_Matriz(int **matriz, int n)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {            
            if(matriz[i][j] == 0 || matriz[i][j] == 1 || matriz[i][j] == 2) printf(" %d ", matriz[i][j]);
            else printf("%d ", matriz[i][j]);
        }
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
