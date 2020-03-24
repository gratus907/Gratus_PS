#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define int ll
using pii = pair <int, int>;
const int INF = 987654321;
const int MX = 105050;

int inorder[MX];
int postorder[MX];
int pos[MX];
vector <int> v;
void run(int s1, int e1, int s2, int e2)
{
    if (s1 > e1 || s2 > e2) return;
    int t = postorder[e2];
    printf("%lld ",t);
    int ps = pos[t];
    run(s1, ps-1, s2, s2-s1+ps-1);
    run(ps+1, e1, s2-s1+ps,e2-1);
}
int32_t main()
{
    usecppio
    int n; cin >> n;
    for (int i = 0; i<n; i++) cin >> inorder[i];
    for (int i = 0; i<n; i++) pos[inorder[i]] = i;
    for (int i = 0; i<n; i++) cin >> postorder[i];

    run(0, n-1, 0, n-1);
}