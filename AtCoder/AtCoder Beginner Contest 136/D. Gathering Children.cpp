#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define ll long long
#define int ll
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair <int, int> pii;

int n;
int initposition[101010];
int position[101010][25];
int ct[101010];
string str;
int32_t main()
{
    cin >> str;
    n = str.length();
    for (int i = 0; i<n; i++)
    {
        initposition[i] = i;
    }
    for (int i = 0; i<n; i++)
    {
        if (str[i] == 'L')
            position[i][0] = initposition[i]-1;
        if (str[i] == 'R')
            position[i][0] = initposition[i]+1;
    }
    for (int t = 1; t<=20; t++)
    {
        for (int i = 0; i<n; i++)
        {
            position[i][t] = position[position[i][t-1]][t-1];
        }
    }
    for (int i = 0; i<n; i++)
    {
        ct[position[i][20]]++;
    }
    for (int i = 0; i<n; i++)
    {
        printf("%lld ",ct[i]);
    }
    printf("\n");
}
