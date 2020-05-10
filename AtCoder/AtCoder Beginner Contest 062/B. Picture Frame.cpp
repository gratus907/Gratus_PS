#include <bits/stdc++.h>
#define ll long long
using namespace std;

char group[101][101];
int main()
{
    int h,w;
    scanf("%d%d",&h,&w);
    for (int i = 1; i<=h; i++)
    {
        scanf("%s",group[i]+1);
    }
    for (int i = 0; i<=(h+1); i++)
    {
        for (int j = 0; j<=(w+1); j++)
        {
            printf("%c",group[i][j]?group[i][j]:'#');
        }
        printf("\n");
    }
}
