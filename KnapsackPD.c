#include <stdio.h>
#include <time.h>

// Função que retorna o maior número
int max(int a, int b) { 
    return (a > b) ? a : b; 
}
 
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n + 1][W + 1];
 
    // Construindo a tabela
    for (i = 0; i <= n; i++) {

        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;

            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w - wt[i-1]], K[i-1][w]);                
            else
                K[i][w] = K[i-1][w];
        }
    }
 
    return K[n][W];
}
 
int main() {
    
    clock_t start, end;

    int profit[] = {45, 90, 12, 67, 34, 78, 56, 23, 89, 43, 76, 98, 54, 32, 65, 87, 21, 46, 74, 58, 32, 64, 90, 87, 43, 19, 78, 36, 3, 34, 87, 58, 46, 21, 90, 36, 32, 65, 43, 78, 19, 45, 9, 45,45, 67, 98, 76, 54, 32, 12, 89, 54, 23, 34, 87, 58, 46, 21, 90, 36, 32, 65, 43, 78, 19, 45, 98, 67, 74, 32, 56, 34, 23, 90, 89, 65, 58, 54, 32, 76, 12, 46, 43, 67, 36, 78, 46, 43, 67};
    int weight[] = {56, 21, 76, 45, 23, 90, 54, 43, 32, 87, 12, 67, 78, 19, 36, 74, 58, 45, 32, 98, 76, 34, 89, 8, 6, 36, 32, 12, 67, 74, 54, 46, 32, 78, 43, 65, 87, 90, 21, 19, 46,  32, 165, 23, 56, 36, 32, 12, 67, 74, 54, 46, 32, 78, 43, 65, 87, 90, 21, 19, 46,  32, 12, 67, 74, 54, 46, 32, 78, 43, 65, 87, 90, 21, 19, 46, 32, 76, 56, 78, 54, 23, 12, 34, 36, 58, 89, 46, 43, 67};
    int W = 1000;

    int n = sizeof(profit) / sizeof(profit[0]);

    start = clock(); // Inicia a contagem de tempo
    printf("%d", knapSack(W, weight, profit, n));
    end = clock(); // Finaliza a contagem de tempo

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %.16f segundos\n", cpu_time_used);
    return 0;
}