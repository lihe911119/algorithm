#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double myMax(double m, double n)
{
    if(m>n)
    {
        return m;
    }
    else
    {
        return n;
    }
}

int main()
{
    double max;
    double maxMoney;
    int m;

    int n;
    int index;
    char temp;
    int flag;
    double item;
    double items[3];

    int j, i;
    double money[100];
    double dp[100];

    while(1)
    {
        scanf("%lf %d", &max, &m);
        if(m==0) break;
        index = 0;
        maxMoney = 0;
        while(m--)
        {
            scanf("%d", &n);
            items[0] = 0;
            items[1] = 0;
            items[2] = 0;
            flag = 0;
            while(n--)
            {
                getchar();
                scanf("%c:%lf", &temp, &item);
                if(temp=='A')
                {
                    items[0]+=item;
                }else if(temp=='B')
                {
                    items[1]+=item;
                }else if(temp=='C')
                {
                    items[2]+=item;
                }else
                {
                    flag = 1;
                }
            }
            if(items[0]>600||items[1]>600||items[2]>600||items[0]+items[1]+items[2]>1000)
            {
                flag = 1;
            }

            if(flag==0)
            {
                money[index] = items[0]+items[1]+items[2];
                index++;
            }
        }

        for(i = 0; i < 100; i++)
        {
            dp[i] = 0;
        }
        for(i = 0; i < index; i++)
        {
            for(j = index; j >= 1; j--)
            {
                if((j==1 || dp[j-1]>0) && dp[j-1]+money[i]<=max)
                    dp[j] = myMax(dp[j], dp[j-1]+money[i]);
                if(dp[j]>=maxMoney&&dp[j]<=max)
                {
                    maxMoney = dp[j];
                }
            }
        }
        printf("%.2lf\n", maxMoney);

    }

    return 0;
}
