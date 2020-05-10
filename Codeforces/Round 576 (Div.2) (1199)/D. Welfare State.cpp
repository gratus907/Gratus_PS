#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define ll long long
#define int ll
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair <int, int> pii;

int n, m;
int balance[202020];
pii query[202020];
int tquery[202020];
bool touched[202020];

void pval()
{
    for (int i = 1; i<=n; i++)
    {
        printf("%lld ",balance[i]);
    }
    printf("\n");
}
int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 1; i<=n; i++)
        cin >> balance[i];
    cin >> m;
    for (int i = 1; i<=m; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int b, c;
            cin >> b >> c;
            query[i] = {b,c};
        }
        else
        {
            int x;
            cin >> x;
            query[i] = {0, x};
            tquery[i] = x;
        }
    }
    for (int i = m; i>=1; i--)
    {
        tquery[i] = max(tquery[i], tquery[i+1]);
    }
    for (int i = 1; i<=m; i++)
    {
        if (query[i].second < tquery[i])
        {
            query[i].second = tquery[i];
        }
        else
            continue;
    }
    for (int i = 1; i<=m; i++)
    {
        pii u = query[i];
        balance[u.first] = u.second;
        touched[u.first] = 1;
    }
    for (int i = 1; i<=n; i++)
    {
        if (touched[i])
        {
            cout << balance[i] << ' ';
        }
        else
        {
            cout << max(balance[i], tquery[1]) << ' ';
        }
    }
    cout << '\n';
}
