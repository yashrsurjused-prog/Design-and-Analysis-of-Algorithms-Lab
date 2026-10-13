#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int values[1005];
    for (int i = 0; i < N; i++) {
        scanf("%d", &values[i]);
    }

    int weights[1005];
    for (int i = 0; i < N; i++) {
        scanf("%d", &weights[i]);
    }

    int W;
    if (scanf("%d", &W) != 1) return 0;

    // dp[w] stores the maximum value achievable with capacity w
    int dp[1005] = {0};

    // 0/1 Knapsack DP transition
    for (int i = 0; i < N; i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    printf("%d\n", dp[W]);

    return 0;
}
