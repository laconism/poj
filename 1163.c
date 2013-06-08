#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

int tri[100][100];
int dp [100][100];

int main()
{
    int n,i,j;

    scanf ("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < i+1; j++)
            scanf ("%d", &tri[i][j]);
    if (n == 1)
    {
        printf ("%d", tri[0][0]);
        return 0;
    }
    for (i = 0;i < n; i++)
        dp[n-1][i] = tri[n-1][i];
    for (i = n-2; i >=0; i--)
        for (j = 0; j < i+1; j++)
            dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + tri[i][j];
    printf ("%d",dp[0][0]);
    return 0;
}
