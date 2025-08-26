#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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


/* Eis aqui o Selection Sort owo*/

void Selection_Sort(int* A, int n){
    int min, temp; 
    
    /*O primeiro laço percorre da primeira posição "i" até a penúltima posição*/
    for (int i = 0; i < n - 1; i++)
    {
        min = i; 

        /*O laço externo percorre da primeira posição "i" até a penúltima posição*/

        for (int j = i + 1; j < n; j++)
        {

            /*Aqui no if, ele procura o menor valor na parte não ordenada, guardando
            o índice desse elemento*/

            if (A[j] < A[min])
            {
                min = j;
            }
        }

        /*Aqui é parecido com o bubble sort praticamente, quando acaba o laço interno
        o algoritmo verifica se precisa trocar o menor elemento encontrado com o 
        elemento da posição i*/

        if (min != i)
        {
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}

/*Fazendo uma exemplificação de como o selection sort funciona...

Imaginemos um vetor A que está preenchido assim: [4, 1, 3, 2]

/* Lembrando matrizes pros meus abigos, ela funciona começando no zero, então basicamente ela tá assim:

         0         1         2         3
    _________________________________________
    |         |         |         |          |
    |    4    |    1    |    3    |    2     |
    |_________|_________|_________|__________|
         i         j
        min

1. Na primeira passada, i = 0
    - A variável 'i' começa em 0.
    - A variável 'min' é inicializada com o valor de 'i', ou seja, 0.
    - O loop 'j' começa em 1 e procura o menor elemento.

- Comparação (j=1): A[1] (1) < A[0] (4)? Sim. 'min' se torna 1.

         0         1         2         3
    _________________________________________
    |         |         |         |          |
    |    4    |    1    |    3    |    2     |
    |_________|_________|_________|__________|
         i         j
                  min

- Comparação (j=2): A[2] (3) < A[1] (1)? Não.
- Comparação (j=3): A[3] (2) < A[1] (1)? Não.

- O menor elemento é encontrado no índice 1.

- O código troca A[0] e A[1].

         0         1         2         3
    _________________________________________
    |         |         |         |          |
    |    1    |    4    |    3    |    2     |
    |_________|_________|_________|__________|
         i         j
        min

Vetor ao final da 1ª passada: [1, 4, 3, 2]

2. Na segunda passada, i = 1
    - A variável 'i' agora é 1.
    
         0         1         2         3
    _________________________________________
    |         |         |         |          |
    |    1    |    4    |    3    |    2     |
    |_________|_________|_________|__________|
                   i         j
                  min

    - A variável 'min' é inicializada com o valor de 'i', ou seja, 1.
    - O loop 'j' começa em 2 e procura o menor elemento no restante do vetor.

- Comparação (j=2): A[2] (3) < A[1] (4)? Sim. 'min' se torna 2.

         0         1         2         3
    _________________________________________
    |         |         |         |          |
    |    1    |    4    |    3    |    2     |
    |_________|_________|_________|__________|
                   i         j
                            min

- Comparação (j=3): A[3] (2) < A[2] (3)? Sim. 'min' se torna 3.

         0         1         2         3
    _________________________________________
    |         |         |         |          |
    |    1    |    4    |    3    |    2     |
    |_________|_________|_________|__________|
                   i                   j
                                      min

- O menor elemento é encontrado no índice 3.
- O código troca A[1] e A[3].

         0         1         2         3
    _________________________________________
    |         |         |         |          |
    |    1    |    2    |    3    |    4     |
    |_________|_________|_________|__________|
                   i                   j
                                      min

Vetor ao final da 2ª passada: [1, 2, 3, 4]

3. Na terceira passada, i = 2

         0         1         2         3
    _________________________________________
    |         |         |         |          |
    |    1    |    2    |    3    |    4     |
    |_________|_________|_________|__________|
                             i         j
                            min

    - A variável 'i' agora é 2.
    - A variável 'min' é inicializada com o valor de 'i', ou seja, 2.
    - O loop 'j' começa em 3.

- Comparação (j=3): A[3] (4) < A[2] (3)? Não.

- O menor elemento já está no índice 2, então não há troca.
- Vetor ao final da 3ª passada: [1, 2, 3, 4]
- O vetor está totalmente ordenado. O loop principal termina.
*/


/*Sobre essa parte do código, ela recebe os números que foram gerados e entra em um laço 'for', onde 
 vai imprimir cada número que está dentro do vetor, de acordo com a sua posição.*/

void imprimir_vetor(int* vetor, int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

int main() {
    int tamanho = 10;
    int* meu_vetor = gerar_numeros_aleatorios(tamanho);

    printf("Vetor original (nao ordenado):\n");
    imprimir_vetor(meu_vetor, tamanho);

    Selection_Sort(meu_vetor, tamanho);

    printf("\nVetor ordenado com Selection Sort:\n");
    imprimir_vetor(meu_vetor, tamanho);

    free(meu_vetor);

    return 0;
}