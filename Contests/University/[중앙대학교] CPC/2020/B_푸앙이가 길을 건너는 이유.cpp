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

bool pos, neg;
struct point {int x, y;};
struct line {int a, b, c;};
line l;
void eval(point p)
{
    int u = p.x * l.a + p.y * l.b + l.c;
    if (u < 0) neg = true;
    if (u > 0) pos = true;
}
point p1, p2, p3, p4;
int32_t main()
{
    usecppio
    cin >> l.a >> l.b >> l.c;
    int x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
    p1 = {x1, y1}; p2 = {x1, y2};
    p3 = {x2, y1}; p4 = {x2, y2};
    eval(p1), eval(p2), eval(p3), eval(p4);
    cout << ((pos & neg)? "Poor" : "Lucky") << '\n';
}