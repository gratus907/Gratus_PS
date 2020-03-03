#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
#define int ll
inline int eulertotient(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}
const int mod = 1000000007;
vector <int> divisors;
int32_t main()
{
    int p;
    cin >> p;
    auto start = chrono::steady_clock::now();
    p--;
    for (int i = 1; i*i <= p; i++)
    {
        if (p%i==0)
        {
            divisors.push_back(i);
            divisors.push_back(p/i);
        }
    }
    int u = divisors.size();
    if (divisors[u-2]==divisors[u-1])
        divisors.pop_back();
    int ans = 0;
    for (auto it:divisors)
    {
        int t = ((it%mod)*(it%mod))%mod;
        int pp = eulertotient(p/it)%mod;
        ans += ((t*pp)%mod);
        ans %= mod;
    }
    p%=mod;
    cout << (ans*p + p*p)%mod << '\n';
    auto end = chrono::steady_clock::now();auto diff = end - start;
    //cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
}