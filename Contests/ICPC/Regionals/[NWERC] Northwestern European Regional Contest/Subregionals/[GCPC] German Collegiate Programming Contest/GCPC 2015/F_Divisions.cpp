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
#define ull unsigned ll
vector<ull> alist ={2,3,5,7,11,13,17,19,23,29,31,37};

inline ull mulmod(ull x, ull y, ull m)
{
    return ((__int128)x * y % m);
}

ull powmod(ull x, ull y, ull m)
{
    x %= m;
    ull r = 1LL;
    while (y > 0)
    {
        if (y % 2 == 1)
            r = mulmod(r, x, m);
        x = mulmod(x, x, m);
        y /= 2;
    }
    return r;
}

inline bool miller_rabin(ull n, ull a)
{
    ull d = n - 1;
    while (d % 2 == 0)
    {
        if (powmod(a, d, n) == n-1)
            return true;
        d /= 2;
    }
    ull tmp = powmod(a, d, n);
    return tmp == n-1 || tmp == 1;
}

bool is_prime(ull n)
{
    if (n <= 1)
        return false;
    if (n <= 10000000000ULL) {
        for (ull i = 2; i*i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
    for (ull a : alist)
        if (!miller_rabin(n, a))
            return false;
    return true;
}

int PollardRho(int n)
{

    if (n==1) return n;

    if (n % 2 == 0) return 2;

    int x = (rand()%(n-2))+2;
    int y = x;

    int c = (rand()%(n-1))+1;

    int d = 1;

    while (1)
    {
        x = (mulmod(x, x, n) + c + n)%n;

        y = (mulmod(y, y, n) + c + n)%n;
        y = (mulmod(y, y, n) + c + n)%n;

        d = __gcd(abs(x-y), n);
        if (d == 1) continue;
        if (is_prime(d))
            return d;
        else return PollardRho(d);
    }

}
vector <int> v;
map <int, int> mp;
int32_t main()
{
    srand (time(NULL));
    int n;
    cin >> n;
    while(!(n&1))
    {
        n >>= 1;
        v.push_back(2);
    }
    if (n == 1) goto end;
    while(!is_prime(n))
    {
        ll d = PollardRho(n);
        while(n%d == 0)
        {
            v.push_back(d);
            n /= d;
        }
        if(n==1) break;
    }
    if(n != 1) v.push_back(n);
end:
    int ans = 1;
    sort(all(v));
    for (auto it:v)
    {
        mp[it]++;
    }
    for (auto it:mp)
    {
        ans *= (it.second+1);
    }
    cout << ans << '\n';
}