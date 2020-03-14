#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair <int, int>;
#define int ll
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = false;
int grid[120][120];
int a, b;
void print_grid()
{
    for (int i = 1; i<=100; i++)
    {
        for (int j = 1; j<=100; j++)
            printf("%c",grid[i][j]==1?'#':'.');
        printf("\n");
    }
}
int32_t main()
{
    for (int i = 1; i<=50; i++)
    {
        for (int j = 1; j<=100; j++)
        {
            grid[i][j] = 0;
            grid[i+50][j] = 1;
        }
    }
    cin >> a >> b;
    a--; b--;
    for (int i = 2; i<=49; i+=2)
    {
        for (int j = 2; j<=98; j+=2)
        {
            if (b)
            {
                grid[i][j] = 1;
                b--;
            }
        }
    }
    for (int i = 52; i<=99; i+=2)
    {
        for (int j = 2; j<=98; j+=2)
        {
            if (a)
            {
                grid[i][j] = 0;
                a--;
            }
        }
    }
    printf("100 100\n");
    print_grid();
}
