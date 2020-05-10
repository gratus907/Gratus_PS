#include <bits/stdc++.h>
using namespace std;

char grid[520][520];
int check(int i, int j)
{
    int flag = 1;
    if (grid[i][j]!='X')
        flag = 0;
    if (grid[i-1][j-1]!='X')
        flag = 0;
    if (grid[i+1][j+1]!='X')
        flag = 0;
    if (grid[i+1][j-1]!='X')
        flag = 0;
    if (grid[i-1][j+1]!='X')
        flag = 0;
    return flag;
}

int main()
{
    int n,c=0;
    scanf("%d",&n);
    for (int i = 1; i<=n; i++)
        scanf("%s",grid[i]);
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=n; j++)
            c+=check(i,j);
    printf("%d",c);
}
