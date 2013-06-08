#include <stdio.h>
#include <limits.h>
#define MATRIX_SIZE 100

int matrix[MATRIX_SIZE][MATRIX_SIZE];
int sum[MATRIX_SIZE];
int n;

int dp()
{
    int t[MATRIX_SIZE],i,max = INT_MIN;
    t[0] = sum[0];
    for (i = 1; i < n; i++)
        t[i] = t[i-1]>0?sum[i]+t[i-1]:sum[i];
    for (i = 0; i < n; i++)
        if (max < t[i])
            max = t[i];
    return max;
}

int main()
{
    int i,j,k,l,max = INT_MIN;
    scanf ("%d",&n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf ("%d",&matrix[i][j]);
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
        {
            for (k = 0; k < n; k++)
                sum[k] = 0;
            for (k = 0; k < n; k++)
                for (l = i; l <= j; l++)
                    sum[k] += matrix[l][k];
            k = dp();
            if (max < k)
                max = k;
        }
    printf("%d",max);
    return 0;
}
