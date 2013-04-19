#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int value[1000];
int sum[1000];

int findMax(int v,int index)
{
    int temp;
    int max = 0;
    int i;
    for(i = index-1; i >= 1; i--)
    {
        if(value[index]>value[i])
        {
            temp = sum[i];
            if(temp>max)
                max = temp;
        }
    }
    return max;
}


int main()
{
    int n,max;
    int i;
    while(1)
    {
        scanf("%d", &n);
        if(n==0) break;
        for(i = 1; i <= n; i++)
        {
            scanf("%d", &value[i]);
            sum[i] = 0;
        }

        value[0] = 9999;
        value[n+1] = -9999;

        for(i = 1; i <= n; i++)
        {
            sum[i] = value[i]+findMax(value[i], i);
        }
        max = 0;
        for(i = 1; i <= n; i++)
        {
            if(sum[i]>max)
                max = sum[i];
        }
        printf("%d\n", max);
    }

    return 0;
}
