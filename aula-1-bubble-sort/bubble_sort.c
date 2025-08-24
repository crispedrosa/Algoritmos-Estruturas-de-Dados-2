#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Implemente um algoritmo em C que ordene um vetor de n números inteiros gerados aleatoriamente,
 usando a lógica do Bubble Sort. Seu programa deve imprimir o vetor original e, em seguida, 
 o vetor já ordenado*/





 int* gerar_numeros_aleatorios(int n){
    int *vetor = (int*)malloc(n * sizeof(int));
    if (vetor == NULL)
    {
        printf("Erro ao alocar memória. \n");
        exit(1);
    }

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        vetor[i] = rand() % (n+1);
    }
    return vetor;
 }




 int imprimir_vetor(int *numeros, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numeros[i]);
    }
 }





 int* ordenar_vetor(int *numeros, int n){
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (numeros[j] > numeros[j+1])
            {
                temp = numeros[j];
                numeros[j]= numeros[j+1];
                numeros[j+1] = temp;
            }
            
        }
        
    }
    return numeros;
    
 }

 int main(){
    int n=10;
    int *numeros = gerar_numeros_aleatorios(n);
    printf("\nNumeros gerados: \n");
    imprimir_vetor(numeros, n);
    printf("\n\n");

    int *numeros_ordenados = ordenar_vetor(numeros, n);
    printf("Numeros ordenados: \n");
    imprimir_vetor(numeros_ordenados,n);
    printf("\n\n");
    return 0;
 }