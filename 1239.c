#include <stdio.h>
#include <string.h>
char buf[90];
long long dp[90];

int size (long long innum)
{
    int i = 0;
    if (innum == 0)
        return 1;
    while (innum != 0)
    {
        innum /= 10;
        i++;
    }
    return i;
}

int main()
{
    long long n,num,m,i,j,count;
    char *p,*pnum;
    while (1)
    {
        scanf ("%s", buf);
        if (strcmp (buf, "0") == 0)
            return 0;
        n = strlen (buf);
        dp[0] = buf[0]-'0';
        for (i = 1; i < n; i++)
        {
            m = 10;
            num = buf[i] - '0';
            j = 0;
            while (num <= dp[i-j-1])
            {
                num += (buf[i-j-1] - '0') * m;
                m *= 10;
                j++;
                if (i-j-1 < 0)
                    break;
            }
            dp[i] = num;
        }
        num = dp[n-1];
        p = buf + n - size(num);
        pnum = p;
        dp[0] = dp[n-1];
        count = 1;
        num = 0;
        m = 1;
        while (pnum != buf)
        {
            while (p != buf && num < dp[count-1])
            {
                p -= 1;
                num += (*p - '0') * m;
                m *= 10;
            }
            if (num < dp[count-1])
            {
                pnum = buf;
                if (num != 0)
                    dp[count++] = num;
            }
            else
            {
                num -= (*p - '0') * (m/10);
                pnum -= size(num);
                if (num != 0)
                    dp[count++] = num;
                p = pnum;
                num = 0;
                m = 1;
            }
        }
        num = 0;
        for (i = 0,j = count-1; i < n; i++)
        {
            printf ("%c", buf[i]);
            num = num * 10 + (buf[i]-'0');
            if (num == dp[j] && dp[j] != 0)
            {
                num = 0;
                j--;
                if (i != n-1)
                    printf (",");
            }
        }
        printf ("\n");
    }
    return 0;
}
