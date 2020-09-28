#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int a, b, c, d; 
int L;
int M;
int n0 = -1, n1 = -1; 
void panic()
{
    cout << "impossible\n"; exit(0);
}
void build(int p, int q, int r, int s, int t)
{
    if (p + r + t != n1) return;
    if (q + s != n0) return;
    if (p<0 || q<0 || r<0 || s<0 || t<0) return;
    if (p*(q + s) + r*s != c) return;
    if (q*(r + t) + s*t != b) return;
    for (int i = 1; i<=p; i++) printf("1");
    for (int i = 1; i<=q; i++) printf("0");
    for (int i = 1; i<=r; i++) printf("1");
    for (int i = 1; i<=s; i++) printf("0");
    for (int i = 1; i<=t; i++) printf("1");
    printf("\n");
    exit(0);
}
void solve(int zeros, int ones)
{
    n0 = zeros; n1 = ones;
    if (n0 == -1 || n1 == -1) return;
    if (n0 == 0 || n1 == 0)
    {
        if (b != 0 || c != 0) return;
    }
    L = n0 + n1;
    M = L * (L-1)/2 - a - d;
    // Check r == 0
    if (n0 != 0)
    {
        if (c % n0 == 0 && b % n0 == 0)
        {
            int x, y, z;
            y = n0; x = c / n0; z = b / n0;
            if (x + z == n1)
            {
                build(x,y,z,0,0);
            }
        } 
    }
    
    // Check r == 1
    int p, q, r, s, t;
    p = q = r = s = t = -1;
    for (p = 0; p<n1; p++)
    {
        s = c - p*n0;
        t = n1 - p - 1;
        q = n0 - s;
        r = 1;
        build(p, q, r, s, t);
    }
    return;
}
int32_t main()
{
    cin >> a >> b >> c >> d;
    for (int i = 2; i<=50000; i++)
    {
        if (i*(i-1)==2*a) 
            n0 = i;
    }
    for (int i = 2; i<=50000; i++)
    {
        if (i*(i-1)==2*d)
            n1 = i;
    }
    if (a == 0 && d == 0)
    {
        solve(0, 0);
        solve(0, 1);
        solve(1, 0);
        solve(1, 1);
        panic();
    }
    else if (a == 0 && d > 0)
    {
        solve(0, n1);
        solve(1, n1);
        panic();
    }
    else if (a > 0 && d == 0)
    {
        solve(n0, 0);
        solve(n0, 1);
        panic();
    }
    else solve(n0, n1);
    panic();
}