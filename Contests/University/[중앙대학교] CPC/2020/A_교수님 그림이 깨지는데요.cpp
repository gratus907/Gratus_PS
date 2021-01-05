#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
using pii = pair<int, int>;

int large[105][105];
int small[11][11];

int32_t main()
{
    int n, k; cin >> n >> k;
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
        {
            cin >> small[i][j];
            for (int p = 0; p < k; p++)
            {
                for (int q = 0; q < k; q++)
                    large[i*k+p][j*k+q] = small[i][j];
            }
        }
    for (int i = 0; i<n*k; i++)
        for (int j = 0; j<n*k; j++)
            cout << large[i][j] << " \n"[j+1 == n*k];
}