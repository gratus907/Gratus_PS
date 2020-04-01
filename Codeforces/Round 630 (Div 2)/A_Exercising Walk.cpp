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

int farleft, farright, farup, fardown;
bool solve()
{
    int a, b, c, d, x, y, x1, y1, x2, y2;
    cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
    int xmove = b-a;
    int ymove = d-c;
    farleft = farright = x;
    farup = fardown = y;
    if (x1 == x && x == x2)
        if (a > 0 || b > 0)
            return false;
    if (y1 == y && y == y2)
        if (c > 0 || d > 0)
            return false;
    if (x1 == x && (a > 0) && (b == 0))
        return false;
    if (x == x2 && a == 0 && b > 0)
        return false;
    if (y1 == y && (c > 0) && (d == 0))
        return false;
    if (y == y2 && c == 0 && d > 0)
        return false;
    int endx = x + (b-a);
    int endy = y + (d-c);
    if (endx < x1 || x2 < endx)
        return false;
    if (endy < y1 || y2 < endy)
        return false;
    return true;
}

int32_t main()
{
    usecppio
    int t;
    cin >> t;
    while(t--)
    {
        cout << (solve()?"Yes":"No") << '\n';
    }
}