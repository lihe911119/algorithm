#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ENTER printf("\n");

int main()
{
    int k;
    int m,n,i,j,l,temp,max;
    int t[21][1010];
    int p[21][1010];
    scanf("%d", &k);
    while(k--)
    {
        scanf("%d %d", &m, &n);
        for(i = 1; i <= m; i++)
        {
            for(j = 1; j <= n; j++)
            {
                scanf("%d", &p[i][j]);
                t[i][j] = 0;
            }
        }

        for(i = 1; i <= m; i++)
        {
            t[i][n+1] = -9999;
        }

        t[m][n] = p[m][n];


        for(i = n-1; i > 0; i--)
        {
            max = t[m][i+1];
            temp = -9999;
            for(j = 2; j * i <= n; j++)
            {
               temp = t[m][j*i];
               if(temp>max) max = temp;
            }
            t[m][i] = max+p[m][i];
        }

        for(i = m-1; i > 0; i--)
        {
            for(j = n; j >= 1; j--)
            {
                max = t[i][j+1];
                temp = -9999;
                for(l = 2; l * j <= n; l++)
                {
                    temp = t[i][l*j];
                    if(temp>max) max = temp;
                }
                max = (t[i+1][j]>max)? t[i+1][j]:max;
                t[i][j] = max+p[i][j];
            }
        }

        printf("%d\n", t[1][1]);
    }

    return 0;
}
