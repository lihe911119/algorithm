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
    int array[500];
    short rows[500];
    int f[500];
    int temp;
    int index = 0;
    int row = 1, rowCount = row;
    int i,j;
    for(i = index; i < index+row; i++)
    {
        f[i] = 0;
    }
    while(scanf("%d", &temp) && temp != -1010)
    {
        array[index] = temp;
        if(rowCount==0)
        {
            rowCount = ++row;
        }
        rows[index] = row;
        index++;
        rowCount--;
    }

    for(j = index-1; j >= 0; j--)
    {
        f[j] = max(f[rows[j]+j],f[rows[j]+j+1])+array[j];
    }

    printf("%d\n", f[0]);

    return 0;
}
