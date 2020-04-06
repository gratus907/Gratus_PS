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
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = 0;
const int mod = 1000000007;

auto gif = [](int a, int b){return a+b;};
class SEG2D
{
public:
    int n;
    int m;
    vector <vector <int>> tree;
    SEG2D(int n = 0, int m = 0)
    {
        tree.resize(2*n);
        for (int i = 0; i<2*n; i++) tree[i].resize(2*m);
        this->n = n;
        this->m = m;
    }
    SEG2D(int n, int m, vector<vector<int>> &data)
    {
        tree.resize(2*n);
        for (int i = 0; i<2*n; i++) tree[i].resize(2*m);
        this->n = n;
        this->m = m;
        init(data);
    }
    void init(vector <vector <int>> & data)
    {
        n = data.size();
        m = data.front().size();
        tree = vector<vector<int>>(2*n, vector<int>(2*m, 0));
        for (int i = 0; i<n; i++)
            for (int j = 0; j<m; j++)
                tree[i+n][j+m] = data[i][j];
        for (int i = n; i<2*n; i++)
            for (int j = m-1; j>0; j--)
                tree[i][j] = gif(tree[i][j*2], tree[i][j*2+1]);
        for (int i = n-1; i>0; i--)
            for (int j = 1; j<2*m; j++)
                tree[i][j] = gif(tree[i*2][j], tree[i*2+1][j]);
    }
    void update(int x, int y, int val)
    {
        tree[x+n][y+m] = val;
        for(int i = y+m; i > 1; i /= 2)
            tree[x+n][i/2] = gif(tree[x+n][i] , tree[x+n][i^1]);
        for (int i = x+n; i>1; i/=2)
        {
            for (int j = y+m; j>=1; j/=2)
            {
                tree[i/2][j] = gif(tree[i][j] , tree[i^1][j]);
            }
        }
    }
    int query_1D(int x, int yl, int yr)
    {
        int res = 0;
        int u = yl+m, v = yr+m+1;
        for(; u<v; u/=2, v/=2)
        {
            if (u & 1)
                res = gif(res, tree[x][u++]);
            if (v & 1)
                res = gif(res, tree[x][--v]);
        }
        return res;
    }
    int query_2D(int xl, int xr, int yl, int yr)
    {
        int res = 0;
        int u = xl+n, v = xr+n+1;
        for(; u<v; u/=2, v/=2)
        {
            if (u & 1)
            {
                int k = query_1D(u++, yl, yr);
                res = gif(res, k);
            }
            if (v & 1)
            {
                int k = query_1D(--v, yl, yr);
                res = gif(res, k);
            }
        }
        return res;
    }
    void print()
    {
        for (int i = 0; i<2*n; i++)
        {
            for (int j = 0; j< 2*m; j++)
            {
                printf("%lld ",tree[i][j]);
            }
            printf("\n");
        }
    }
};
int n, m;
SEG2D S(n, n);
int32_t main()
{
    usecppio
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    S.init(arr);
    while(m--)
    {
        int w;
        cin >> w;
        if(w == 0)
        {
            int x, y, c;
            cin >> x >> y >> c;
            x--; y--;
            S.update(x, y, c);
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--; y1--; x2--; y2--;
            cout << S.query_2D(x1,x2,y1,y2) << '\n';
        }
    }
}