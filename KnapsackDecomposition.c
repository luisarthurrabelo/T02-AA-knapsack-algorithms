#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int knapsack(int profit[], int weight[], int W, int n) {
    int* dp = (int*)malloc((W + 1) * sizeof(int));
    for (int i = 0; i <= W; i++) {
        dp[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = W; j >= weight[i]; j--) {
            if (dp[j - weight[i]] + profit[i] > dp[j]) {
                dp[j] = dp[j - weight[i]] + profit[i];
            }
        }
    }

    int result = dp[W];
    free(dp);
    return result;
}

int main() {
        
    clock_t start, end;

    int profit[] = {45, 90, 12, 67, 34, 78, 56, 23, 89, 43, 76, 98, 54, 32, 65, 87, 21, 46, 74, 58, 32, 64, 90, 87, 43, 19, 78, 36, 3, 34, 87, 58, 46, 21, 90, 36, 32, 65, 43, 78, 19, 45, 9, 45,45, 67, 98, 76, 54, 32, 12, 89, 54, 23, 34, 87, 58, 46, 21, 90, 36, 32, 65, 43, 78, 19, 45, 98, 67, 74, 32, 56, 34, 23, 90, 89, 65, 58, 54, 32, 76, 12, 46, 43, 67, 36, 78, 46, 43, 67};
    int weight[] = {56, 21, 76, 45, 23, 90, 54, 43, 32, 87, 12, 67, 78, 19, 36, 74, 58, 45, 32, 98, 76, 34, 89, 8, 6, 36, 32, 12, 67, 74, 54, 46, 32, 78, 43, 65, 87, 90, 21, 19, 46,  32, 165, 23, 56, 36, 32, 12, 67, 74, 54, 46, 32, 78, 43, 65, 87, 90, 21, 19, 46,  32, 12, 67, 74, 54, 46, 32, 78, 43, 65, 87, 90, 21, 19, 46, 32, 76, 56, 78, 54, 23, 12, 34, 36, 58, 89, 46, 43, 67};
    int W = 1000;

    int n = sizeof(profit) / sizeof(profit[0]);

    clock_t start = clock();
    int maxProfit = knapsack(profit, weight, W, n);
    clock_t end = clock();
    
    double timeSpent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("%d\n", maxProfit);
    printf("Tempo gasto: %lf segundos\n", timeSpent);

    return 0;
}