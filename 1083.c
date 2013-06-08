#include <stdio.h>
#include <limits.h>

struct carry
{
    int s;
    int t;
};

struct carry array[200];

int main()
{
    int T,n,i,j,k,max,time,tmp;
    scanf ("%d", &T);

    for (i = 0; i < T; i++)
    {
        max = 0;
        scanf ("%d",&n);
        for (j = 0; j < n; j++)
        {
            scanf ("%d%d", &array[j].s,&array[j].t);
            if (array[j].s%2 != 0)
                array[j].s += 1;
            if (array[j].t%2 != 0)
                array[j].t += 1;
            array[j].s /= 2;
            array[j].t /= 2;
            if (array[j].s > array[j].t)
            {
                tmp = array[j].s;
                array[j].s = array[j].t;
                array[j].t = tmp;
            }
        }
        for (j = 1; j < 201; j++)
        {
            time = 0;
            for (k = 0; k < n; k++)
                if(j <= array[k].t && j >= array[k].s)
                    time++;
            if (max < time)
                max = time;
        }
        printf ("%d\n",max*10);
    }

    return 0;
}
