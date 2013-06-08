#include <stdio.h>
#include <limits.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))

int label[100];
char letter[100];
struct 
{
    int min;
    int max;
}dp[50][100];
int op(int x,int y, char c)
{
    switch(c)
    {
        case 't': return x+y;
        case 'x': return x*y;
    }
}

int main()
{
    int n,i,j,k,n1,n2,n3,n4;
    scanf ("%d", &n);
    for (i = 0; i < n; i++)
    {
        getchar();
        scanf ("%c %d", &letter[i], &label[i]);
        letter[i+n] = letter[i];
        label[i+n] = label[i];
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n*2; j++)
        {
            dp[i][j].max = INT_MIN;
            dp[i][j].min = INT_MAX;
        }
    for (i = 0; i < n; i++)
        dp[0][i].max = dp[0][i].min = dp[0][i+n].max = dp[0][i+n].min= label[i];
    for (i = 1; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < i; k++)
            {
                n1 = op(dp[k][j].max,dp[i-k-1][j+k+1].max,letter[j+k+1]);
                n2 = op(dp[k][j].max,dp[i-k-1][j+k+1].min,letter[j+k+1]);
                n3 = op(dp[k][j].min,dp[i-k-1][j+k+1].max,letter[j+k+1]);
                n4 = op(dp[k][j].min,dp[i-k-1][j+k+1].min,letter[j+k+1]);
                if (dp[i][j].max < MAX(MAX(n1,n2),MAX(n3,n4)))
                    dp[i][j].max = dp[i][j+n].max = MAX(MAX(n1,n2),MAX(n3,n4));
                if (dp[i][j].min > MIN(MIN(n1,n2),MIN(n3,n4)))
                    dp[i][j].min = dp[i][j+n].min = MIN(MIN(n1,n2),MIN(n3,n4));
            }
    j = INT_MIN;
    for (i = 0; i < n; i++)
    {
        if (dp[n-1][i].max > j)
            j = dp[n-1][i].max;
    }
    printf ("%d\n", j);
    for (i = 0; i < n; i++)
    {
        if (dp[n-1][i].max == j)
            printf ("%d ", i+1);
    }
    return 0;
}
