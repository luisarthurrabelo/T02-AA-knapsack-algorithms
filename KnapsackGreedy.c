# include<stdio.h>
#include <time.h>
 
float knapSack(int n, int wt[], int val[], int W) {

    float x[n], tp = 0;
    int i, u;
    u = W;
    
    for (i = 0; i < n; i++)
        x[i] = 0;
    
    for (i = 0; i < n; i++) {

        if (wt[i] > u)
            break;
        else {
            x[i] = 1.0;
            tp = tp + val[i];
            u = u - wt[i];
        }
    }
    
    if (i < n)
        x[i] = u / wt[i];
    
    tp = tp + (x[i] * val[i]);
    
    return tp;
}
 
int main() {

    clock_t start, end;

    int profit[] = {45, 90, 12, 67, 34, 78, 56, 23, 89, 43, 76, 98, 54, 32, 65, 87, 21, 46, 74, 58, 32, 64, 90, 87, 43, 19, 78, 36, 3, 34, 87, 58, 46, 21, 90, 36, 32, 65, 43, 78, 19, 45, 9, 45,45, 67, 98, 76, 54, 32, 12, 89, 54, 23, 34, 87, 58, 46, 21, 90, 36, 32, 65, 43, 78, 19, 45, 98, 67, 74, 32, 56, 34, 23, 90, 89, 65, 58, 54, 32, 76, 12, 46, 43, 67, 36, 78, 46, 43, 67};
    int weight[] = {56, 21, 76, 45, 23, 90, 54, 43, 32, 87, 12, 67, 78, 19, 36, 74, 58, 45, 32, 98, 76, 34, 89, 8, 6, 36, 32, 12, 67, 74, 54, 46, 32, 78, 43, 65, 87, 90, 21, 19, 46,  32, 165, 23, 56, 36, 32, 12, 67, 74, 54, 46, 32, 78, 43, 65, 87, 90, 21, 19, 46,  32, 12, 67, 74, 54, 46, 32, 78, 43, 65, 87, 90, 21, 19, 46, 32, 76, 56, 78, 54, 23, 12, 34, 36, 58, 89, 46, 43, 67};
    int W = 200;

    //Razão entre preço e peso
    
    int n = sizeof(profit) / sizeof(profit[0]);
    float ratio[n], temp;

    for (int i = 0; i < n; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;
    
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;
    
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    start = clock(); // Inicia a contagem de tempo
    printf("%f", knapSack(n, weight, profit, W));
    end = clock(); // Finaliza a contagem de tempo

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %.16f segundos\n", cpu_time_used);

    return(0);
}