#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
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

const int maxp = 10030303;
const int maxm = 10000000;
int info[maxp];
int par[maxp];
int a, b, c, d;
vector <int> v;
int32_t main()
{
    usecppio
    cin >> a >> b >> c >> d;
    for (int i = 0; i<maxp; i++) info[i] = 1;
    for (int i = 2; i*i<=maxm; i++)
    {
        if (info[i]==1)
        {
            for (int j = i; j<=maxm; j+=i)
            {
                info[j]*=i;
                par[j] = 1-par[j];
                if (j%(i*i)==0)
                    info[j] = 0;
            }
        }
    }
    for (int i = sqrt(maxm)+1; i<=maxm; i++)
        if (info[i]!=i)
            info[i] *= i, par[i] = 1-par[i];
    int total_pair = (b-a+1)*(d-c+1);
    for (int i = 2; i<=maxm; i++)
    {
        if (info[i])
        {
            int u = (b/i-(a-1)/i) * (d/i-(c-1)/i);
            if (par[i])
                total_pair -= u;
            else total_pair += u;
        }
    }
    cout << total_pair << '\n';
}