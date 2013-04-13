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
    int m,n,nt,i,j;
    int w[100];
    int v[100];
    int f[1000];
    f[0] = 0;
    scanf("%d %d", &m, &n);

    nt = 0;

    while(nt < n)
    {
        scanf("%d", &w[nt]);
        nt++;
    }
    nt = 0;
    while(nt < n)
    {
        scanf("%d", &v[nt]);
        nt++;
    }

    for(j = 1; j <= m; j++)
    {
        for(i = 0; i < n; i++)
        {
            if(j - w[i] >= 0)
            {
                f[j] = max(f[j-w[i]]+v[i],f[j]);
            }
        }
    }

    printf("Max: %d\n", f[m]);
    return 0;
}
