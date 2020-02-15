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

int n;
map <int, vector <int>> mp;
bool is_composite[50505];
vector <int> primes;
vector <int> ans;
inline void merge_vectors(vector <int> &a, vector <int> &b)
{
    a.insert(a.end(), b.begin(), b.end());
}
inline void uniquify(vector <int> &v, bool issorted)
{
    if (!issorted)
        sort(all(v));
    v.erase(unique(all(v)),v.end());
}
void prime_sieve()
{
    is_composite[1] = true;
    is_composite[2] = false;
    primes.push_back(2);
    for (int i = 4; i<50000; i+=2) is_composite[i] = true;
    for (int i = 3; i<50000; i+=2)
    {
        if (!is_composite[i])
        {
            primes.push_back(i);
            for (int j = 2*i; j<50000; j+=i)
                is_composite[j] = true;
        }
    }
}

bool check_prime(int x)
{
    if (x == 1) return true;
    if (x < 50000) return !is_composite[x];
    for (auto it:primes)
    {
        if (it>=x) return true;
        if (x%it==0) return false;
    }
    return true;
}
vector <int> start_check(int x)
{
    if (mp.find(x)!=mp.end())
        return mp[x];
    int orx = x;
    vector <int> result;
    vector <int> dvs;
    if (check_prime(x))
        return mp[x] = {x-1};
    for (int i = 2; i*i<=x; i++)
    {
        if (x%i==0)
        {
            dvs.push_back(i);
            dvs.push_back(x/i);
            if(x/i == i)
                dvs.pop_back();
        }
    }
    for (auto it:dvs)
    {
        vector <int> u = start_check(orx/it);
        for (auto it2:u)
            result.push_back(it2+it-1);
    }
    result.push_back(orx-1);
    uniquify(result, false);
    return mp[orx] = result;
}
int32_t main()
{
    cin >> n;
    prime_sieve();
    ans = start_check(n);
    printf("%d\n",(int)ans.size());
    for (auto it:ans)
        printf("%d ",it);
}