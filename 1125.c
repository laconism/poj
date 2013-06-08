#include <stdio.h>
#include <limits.h>

int min[100][100];
int num[100];
int flag[100];
struct {
    int num;
    int time;
}s[100][100];
int depth = 0;

int dp(int start, int end)
{
    int q = INT_MAX,i,t;
    depth++;
    flag[start] = 1;
    if (min[start][end] != -1)
    {
        depth--;
        flag[start] = 0;
        return min[start][end];
    }
    if (start == end)
    {
        min[start][end] = 0;
        depth--;
        flag[start] = 0;
        return 0;
    }
    for (i = 0; i < num[start]; i++)
    {
        if (flag[s[start][i].num-1] == 1)
            continue;
        if (s[start][i].num-1 == end)
            t = s[start][i].time;
        else
            t = dp(s[start][i].num-1,end);
        if (t != INT_MAX)
            t += s[start][i].time;
        if (t < q)
            q = t;
    }
    min[start][end] = q;
    printf ("start:%d, end:%d, time:%d\n",start+1,end+1,q);
    depth--;
    flag[start] = 0;
    return q;
}

int main()
{
    int n,i,j,row_r,max_r,max;
    while(1)
    {
        scanf ("%d", &n);
        if (!n)
            return 0;
        max = INT_MAX;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                min[i][j] = -1;
        for (i = 0; i < n; i++)
        {
            scanf ("%d", &num[i]);
            flag[i] = 0;
            for (j = 0; j < num[i]; j++)
                scanf ("%d%d", &s[i][j].num, &s[i][j].time);
        }
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                dp(i,j);
        for (i = 0; i < n; i++)
        {
            max_r = INT_MIN;
            for (j = 0; j < n; j++)
            {
                if (max_r < min[i][j])
                    max_r = min[i][j];
                printf ("%d ", min[i][j]);
            }
            if (max_r < max)
            {
                max = max_r;
                row_r = i;
            }
            printf ("\n");
        }
        printf ("%d %d\n", row_r+1, max);
    }
    return 0;
}
