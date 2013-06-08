#include <stdio.h>

int broad[26];
int vector[][2] = {
    {-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}
};
char answer[60];
char *pc;
int p,q;
int flag = 0;


void dfs(int x, int y, int depth)
{
    int i,t1,t2;

    if (flag != 0)
        return;
    broad[x*q+y] = 1;
    *(pc+depth*2) = 'A'+y;
    *(pc+depth*2+1) = '0'+x+1;
    *(pc+depth*2+2) = 0;

    if (depth+1 == p*q)
    {
        flag = 1;
        return;
    }
    
    for (i = 0; i < 8; i++)
    {
        t1 = x+vector[i][0];
        t2 = y+vector[i][1];
        if (t1 >= 0 && t1 < p && t2 >= 0 && t2 < q)
            if (broad[t1*q+t2] == 0)
                dfs(t1,t2,depth+1);
    }
    broad[x*q+y] = 0;
};

int main()
{
    int n,t,i,j;
    char step[60];
    scanf ("%d", &n);

    for (t = 0; t < n; t++)
    {
        scanf ("%d%d", &p, &q);
        for (i = 0; i < p; i++)
            for (j = 0; j < q; j++)
                broad[i*q+j] = 0;
        pc = answer;
        dfs(0,0,0);

        printf ("Scenario #%d:\n", t+1);
        if (flag != 0)
            printf ("%s\n\n", answer);
        else
            printf ("impossible\n\n");
        flag = 0;
    }

    return 0;
}
