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

bool palindrome(int x)
{
    string s = to_string(x);
    string t = s;
    reverse(all(t));
    return s == t;
}

bool isprime(int x)
{
    if (x == 1) return false;
    for (int i = 2; i*i<=x; i++)
        if (x%i == 0)
            return false;
    return true;
}
int32_t main()
{
    int n; cin >> n;
    for (int i = n; i<=1010101; i++)
    {
        if (palindrome(i))
        {
            if (isprime(i))
            {
                cout << i << '\n';
                return 0;
            }
        }
    }
}