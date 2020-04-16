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
const bool debug = 0;
bool is_composite[505050];
bool vst[505050];
vector <int> primes = {2};
int n;
vector <int> val;
int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 4; i<= n; i+=2)
    {
        is_composite[i] = true;
    }
    for (int i = 3; i <= n; i+=2)
    {
        if (!is_composite[i])
        {
            primes.push_back(i);
            for (int j = i * 2; j <=n; j += i)
                is_composite[j] = true;
        }
    }
    val.push_back(1);
    vst[1] = true;
    for (auto it:primes)
    {
        vst[it] = true;
        val.push_back(1);
    }
    for (int i = 4; i<=n; i+=2)
    {
        vst[i] = true;
        val.push_back(i/2);
    }
    for (int i = 3; i<=n; i+=2)
    {
        if (vst[i]) continue;
        for (auto it:primes)
        {
            if (i%it==0)
            {
                vst[i] = true;
                val.push_back(i/it);
                break;
            }
        }
    }
    sort(all(val));
    for (int i = 1; i<n; i++)
    {
        cout << val[i] << ' ';
    }
}