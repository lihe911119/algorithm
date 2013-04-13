#include <stdio.h>

int main()
{
    int n;
    double tp;
    int m,total;
    double per[10000];
    int value[10000];
    int index,j,i;
    double dp[10005];
    scanf("%d", &n);
    while(n--)
    {
        scanf("%lf %d", &tp, &m);
        index = 0;
        total = 0;
        while(m--)
        {
            scanf("%d %lf", &value[index], &per[index]);
            per[index] = 1-per[index];
            total += value[index];
            index++;
        }
        for(i = 0; i< 10005; i++)
        {
            dp[i] = 0;
        }
        dp[0] = 1;
        for(i = 0; i < index;i++)
        {
            for(j = total; j >= value[i]; j--)
            {
                if(dp[j] < dp[j-value[i]]*per[i])
                    dp[j] = dp[j-value[i]]*per[i];
            }
        }
        for(i = total; i >= 0; i--)
        {
            if(1-dp[i]<=tp)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
