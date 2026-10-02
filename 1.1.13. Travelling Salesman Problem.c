#include <stdio.h>
#include <limits.h>

#define INF 999999

int n;
int cost[20][20];
int dp[20][1 << 20];

int tsp(int city, int mask)
{
    // All cities visited
    if (mask == (1 << n) - 1)
    {
        if (cost[city][0] == -1)
            return INF;

        return cost[city][0];
    }

    // Already calculated
    if (dp[city][mask] != -1)
        return dp[city][mask];

    int ans = INF;

    for (int next = 0; next < n; next++)
    {
        // If city is not visited and connection exists
        if (!(mask & (1 << next)) && cost[city][next] != -1)
        {
            int newCost = cost[city][next] +
                          tsp(next, mask | (1 << next));

            if (newCost < ans)
                ans = newCost;
        }
    }

    return dp[city][mask] = ans;
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    // Initialize DP table
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            dp[i][j] = -1;
        }
    }

    int answer = tsp(0, 1);

    if (answer >= INF)
        printf("-1");
    else
        printf("%d", answer);

    return 0;
}
