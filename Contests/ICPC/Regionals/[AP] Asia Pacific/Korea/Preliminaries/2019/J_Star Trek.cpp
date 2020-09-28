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
const int INF = 2e18;
struct Line // Linear function ax + b
{
    int a, b;
    int eval(int x){return a*x + b;}
};
struct LiChao
{
    struct Node
    {
        int left, right, start, end;
        Line f;
    };
    Node new_node(int a, int b)
    {
        return {-1,-1,a,b,{0,INF}};
    }
    vector <Node> nodes;
    void init(int min_x, int max_x)
    {
        nodes.push_back(new_node(min_x, max_x));
    }
    void insert(int n, Line new_line)
    {
        int xl = nodes[n].start, xr = nodes[n].end;
        int xm = (xl + xr)/2;
        Line llo, lhi;
        llo = nodes[n].f, lhi = new_line;
        if (llo.eval(xl) >= lhi.eval(xl))
            swap(llo, lhi);
        if (llo.eval(xr) <= lhi.eval(xr))
        {
            nodes[n].f = llo;
            return;
        }
        else if (llo.eval(xm) > lhi.eval(xm))
        {
            nodes[n].f = lhi;
            if (nodes[n].left == -1)
            {
                nodes[n].left = nodes.size();
                nodes.push_back(new_node(xl,xm));
            }
            insert(nodes[n].left, llo);
        }
        else
        {
            nodes[n].f = llo;
            if (nodes[n].right == -1)
            {
                nodes[n].right = nodes.size();
                nodes.push_back(new_node(xm+1,xr));
            }
            insert(nodes[n].right,lhi);
        }
    }
    void insert(Line f)
    {
        insert(0, f);
    }
    int get (int n, int q)
    {
        if (n == -1) return INF;
        int xl = nodes[n].start, xr = nodes[n].end;
        int xm = (xl + xr)/2;
        if (q > xm) return min(nodes[n].f.eval(q), get(nodes[n].right, q));
        else return min(nodes[n].f.eval(q), get(nodes[n].left, q));
    }
    void print()
    {
        for (int i = 0; i<nodes.size(); i++)
        {
            printf("Node %lld : [%lld, %lld] %lldx + %lld, next is {%lld, %lld}\n",i, nodes[i].start, nodes[i].end, nodes[i].f.a, nodes[i].f.b, nodes[i].left, nodes[i].right);
        }
    }
};
LiChao CHT;
int dp[101010], L[101010], S[101010], P[101010];
int n;
int32_t main()
{
    usecppio
    cin >> n;
    CHT.init(-1e9, 1e9);
    dp[1] = 0;
    for (int i = 2; i<=n; i++)
        cin >> L[i], L[i] += L[i-1];
    for (int i = 1; i<=n-1; i++)
        cin >> P[i] >> S[i];
    CHT.insert({S[1], P[1]});
    for (int i = 2; i<=n; i++)
    {
        dp[i] = CHT.get(0, L[i]);
        CHT.insert({S[i], -L[i]*S[i]+P[i]+dp[i]});
    }
    cout << dp[n] << '\n';
}
