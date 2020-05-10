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

void pdeq(deque<int>&c)
{
    cout << "CANDY!\n";
    for (auto it:c)
    {
        cout << it << ' ';
    }
    cout << '\n';
}
void solve()
{
    int n, a = 0, b = 0;
    deque<int> candy;
    cin >> n;
    int turn = 0;
    for (int i = 0; i<n; i++)
    {
        int x; cin >> x;
        candy.push_back(x);
    }
    turn = 1;
    a = candy[0];
    int da = candy[0], db = 0;
    candy.pop_front();
    while(!candy.empty())
    {
        turn++;
        if (turn%2==0)
        {
            db = 0;
            while(!candy.empty() && db <= da)
            {
                b += candy.back();
                db += candy.back();
                candy.pop_back();
            }
        }
        else
        {
            da = 0;
            while(!candy.empty() && da <= db)
            {
                a += candy.front();
                da += candy.front();
                candy.pop_front();
            }
        }
    }
    cout << turn << " " << a << " " << b << '\n';
}

int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--)
        solve();
}