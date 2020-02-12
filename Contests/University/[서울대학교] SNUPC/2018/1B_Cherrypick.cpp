#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int cake[1210][1210];
int ans[1210][1210];
int rmax[1210][1210][35];
int dx[9] = {1,1,1,-1,-1,-1,0,0,0};
int dy[9] = {1,0,-1,1,0,-1,1,0,-1};
int n;

void printk(int k)
{
    printf("Best answer considering %d\n",k);
    for (int i = 101; i<=n+100; i++)
    {
        for (int j = 101; j<=n+100; j++)
            printf("%d ",rmax[i][j][k]-k*k);
        printf("\n");    
    }printf("\n"); 
}


int main()
{
    scanf("%d",&n);
    for (int i = 1; i<=n; i++)
        for (int j = 1; j<=n; j++)
            scanf("%d",&cake[i+100][j+100]);
    
    for (int i = 101; i<=n+100; i++)
        for (int j = 101; j<=n+100; j++)
            rmax[i][j][1] = cake[i][j];

    for (int i = 101; i<=n+100; i++)
        for (int j = 101; j<=n+100; j++)
            for (int d = 0; d<9; d++)
                rmax[i][j][2] = max(rmax[i][j][2],cake[i+dx[d]][j+dy[d]]);
    
    for (int k = 3; k<35; k++)
        for (int i = 101; i<=n+100; i++)
            for (int j = 101; j<=n+100; j++)
                rmax[i][j][k] = max({rmax[i-1][j-1][k-1],rmax[i+1][j-1][k-1],rmax[i+1][j+1][k-1],rmax[i-1][j+1][k-1]});
            
    for (int k = 1; k<=32; k++)
        for (int i = 101; i<=n+100; i++)
            for (int j = 101; j<=n+100; j++)
                ans[i][j] = max(ans[i][j],rmax[i][j][k]-k*k);

    /*printk(3);
    printf("Print Answer\n");*/
    for (int i = 101; i<=n+100; i++)
    {
        for (int j = 101; j<=n+100; j++)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
}