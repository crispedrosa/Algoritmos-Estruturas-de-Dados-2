#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Implemente um algoritmo em C que ordene um vetor de n números inteiros gerados aleatoriamente,
 usando a lógica do Bubble Sort. Seu programa deve imprimir o vetor original e, em seguida, 
 o vetor já ordenado*/

/*Essa parte do código faz um algoritmo de geração aleatória de números que cria um vetor do 
tamanho da variável 'n' e aloca a memória para ele. Se essa alocação der erro e  o vetor for 
nulo, o programa é fechado. Se não, ele entra em um loop 'for' que se repete até a quantidade 
'n', e em cada repetição, um número aleatório é gerado usando 'rand() % (n + 1)', o que garante 
que o número gerado esteja no intervalo de 0 até 'n', incluindo ele mesmo. */

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

/*Sobre essa parte do código, ela recebe os números que foram gerados e entra em um laço 'for', onde 
 vai imprimir cada número que está dentro do vetor, de acordo com a sua posição.*/

 int imprimir_vetor(int *numeros, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numeros[i]);
    }
 }

/*Aqui é a parte mais complexa do código*/

 int* ordenar_vetor(int *numeros, int n){
    int temp;

    /*Esse primeiro laço é responsável por controlar as passagens pelo vetor, sendo que cada passagem completa,
    o elemento de maior valor é levado até o fim do vetor*/

    for (int i = 0; i < n; i++)
    {
        /*Esse segundo laço é responsável pela comparação e a troca dos elementos. Ele percorre o vetor desde o início até
        a parte não ordenada. Por exemplo, se o vetor for de 4 posições:
            quando i=0, então j = 4-0-1 (ele vai de j=0 até j=2)
            quando i=1, então j = n-1-1 (ele vai de j=0 até j=1)
            quando i=2, então j = n-2-1 (ele vai até o j=0, pois ja estaria ordenado)*/

        for (int j = 0; j < n-i-1; j++)
        {

            /*Aqui é literalmente a parte mais tranquila do código, ele compara se o número que está no indice j é maior que o 
            número que está no j+1 e se for maior, ele entra fazendo a troca, onde a variável temp recebe o valor que estava no
            indice j, o vetor na posição j recebe o j+1 e o vetor na posição j mais um recebe por fim a variável que estava no temp,
            realizando assim a troca*/

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