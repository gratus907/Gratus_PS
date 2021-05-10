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

int where[101010];
struct Segtree
{
#define N 101010
    int n;
    int T[2*N];
    void build(vector<int> &v)
    {
        n = v.size();
        for (int i = 0; i<n; i++)
            T[n+i] = v[i];
        for (int i = n-1; i>0; i--)
            T[i] = T[i<<1] + T[(i<<1)|1];
    }
    void modify(int pos, int val)
    {
        for (T[pos += n] = val; pos > 1; pos >>= 1)
            T[pos >> 1] = T[pos] + T[pos^1];
    }
    // query is on [l, r)!!
    int query(int l, int r)
    {
        int res = 0;
        for (l += n, r += n; l < r; l >>=1, r>>=1)
        {
            if (l & 1) res += T[l++];
            if (r & 1) res += T[--r];
        }
        return res;
    }
} S;
int32_t main()
{
    usecppio
    int n; cin >> n;
    S.n = n;
    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        where[x] = i;
        S.modify(i, 1);
    }
    int l = 1, r = n;
    for (int i = 1; i <= n; i++){
        int target = (i%2 == 1)?l:r;
        int p = where[target];
        int lft = (i%2==1)?S.query(1, p):S.query(p+1,n+1);
        cout << lft << '\n';
        S.modify(p, 0);
        (i%2==1)?l++:r--;
    }
}