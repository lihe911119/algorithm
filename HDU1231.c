#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    int num, i, temp;
    int start,end,tempStart;
    int max;
    int sum;
    int relStart, relEnd;
    while(1)
    {
        scanf("%d", &num);
        if(num==0) break;
        i = num;
        max = -99999;
        sum = 0;
        while(num--)
        {
            scanf("%d", &temp);
            if(num+1==i)
                relStart = temp;
            if(num==0)
                relEnd = temp;
            sum += temp;
            if(sum <= temp)
            {
                sum = temp;
                tempStart = sum;
            }
            if(sum>max)
            {
                max = sum;
                end = temp;
                start = tempStart;
            }
        }
        if(max<0)
        {
            printf("%d %d %d\n", 0, relStart, relEnd);
        }else
            printf("%d %d %d\n", max, start, end);
    }
    return 0;
}
