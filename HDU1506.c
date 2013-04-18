#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    long left[100010];
    long right[100010];
    long wid[100010];
    long n,i,max,temp;
    while(1)
    {
        scanf("%ld", &n);
        if(n==0) break;
        for(i = 1; i <= n; i++)
        {
            scanf("%ld", &wid[i]);
            left[i] = i;
            right[i] = i;
        }
        wid[0]=wid[n+1]=-1;
        for(i = 1; i <= n; i++)
        {
            while(wid[left[i]-1]>=wid[i])
            {
                left[i] = left[left[i]-1];
            }
        }
        for(i = n; i >=1; i--)
        {
            while(wid[right[i]+1]>=wid[i])
            {
                right[i] = right[right[i]+1];
            }
        }
        max = -1;
        for(i = 1; i <= n; i++)
        {
            temp = (right[i]-left[i]+1)*wid[i];
            if(temp > max)
            {
                max = temp;
            }
        }
        printf("%ld\n", max);
    }
    return 0;
}
