#include <stdio.h>
#include <limits.h>

int a[100][100];
int dp[100][100];

int main()
{
    int f,v,i,j,k,t;
    scanf ("%d%d", &f, &v);
    for (i = 0; i < f; i++)
        for (j = 0; j < v; j++)
        {
            scanf ("%d", &a[i][j]);
            dp[i][j] = INT_MIN;
        }
    for (i = 0; i < v; i++)
        dp[f-1][i] = a[f-1][i];
    for (i = f-2; i >= 0; i--)
        for (j = v-(f-i); j >=i; j--)
        {
            t = INT_MIN;
            for (k = j+1; k <= v-(f-i-1); k++)
                if (t < dp[i+1][k])
                    t = dp[i+1][k];
            dp[i][j] = a[i][j] +t;
        }
    t = INT_MIN;
    for (i = 0; i < v; i++)
        if (dp[0][i] > t)
            t = dp[0][i];
    printf ("%d", t);
    return 0;
}
