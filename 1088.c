#include <stdio.h>

int matrix[100][100];
int max[100][100];
int row,col;
int vector[][2] =
{
    {-1, 0},
    { 0,-1},
    { 0, 1},
    { 1, 0},
};

int dp(int r,int c)
{
    int i,t,max_r = -1,count = 0;
    int rt,ct;
    if (max[r][c] == -1)
    {
        for (i = 0; i < 4; i++)
        {
            rt = r+vector[i][0];
            ct = c+vector[i][1];
            if (rt >= 0 && rt < row && ct >= 0 && ct < col)
            {
                if (matrix[rt][ct] < matrix[r][c])
                {
                    t = dp(rt,ct)+1;
                    count++;
                    if (t > max_r)
                        max_r = t;
                }
            }
        }

        if (!count)
        {
            max[r][c] = 1;
            return 1;
        }
        else
        {
            max[r][c] = max_r;
            return max_r;
        }
    }
    else
    {
        return max[r][c];
    }
}

int main()
{
    int i,j,max_r = -1;
    scanf ("%d%d",&row,&col);
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            scanf ("%d", &matrix[i][j]);
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            max[i][j] = -1;
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            dp(i,j);
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            if (max[i][j] > max_r)
                max_r = max[i][j];

    printf ("%d", max_r);
    return 0;
}
