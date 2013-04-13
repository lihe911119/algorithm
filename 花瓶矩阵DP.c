#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int max(int m, int n)
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
    int best[500][500];
    int aes[500][500];

    int vase, temp, i, j,types;

    scanf("%d", &vase);
    for(i = 0;; i++)
    {
        for(j = 0; j < vase; j++)
        {
            scanf("%d", &temp);
            if(temp==-1010) break;
            aes[i][j] = temp;
        }
        if(temp==-1010) break;
    }

    types = i;

    for(i = 0; i < types; i++)
    {
        best[i][vase] = -9999;
    }

    for(i = vase-1; i>=0; i--)
    {
        best[types-1][i] = max(aes[types-1][i], best[types-1][i+1]);
    }

    for(j = types-2; j >=0; j--)
    {
        for(i = vase-1; i >=0; i--)
        {
            best[j][i] = max(best[j][i+1], best[j+1][i+1]+aes[j][i]);
        }
    }

    for(i = 0; i < types; i++)
    {
        for(j = 0; j < vase; j++)
        {
            printf("%d ", best[i][j]);
        }
        printf("\n");
    }

    return 0;
}
