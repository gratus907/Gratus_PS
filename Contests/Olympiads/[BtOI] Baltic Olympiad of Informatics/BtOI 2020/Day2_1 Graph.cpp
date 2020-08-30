#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
#define int ll
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
const int INF = 1e12;
const int UNDET = 2;
const int PLUS = 1;
const int MINUS = -1;
const int FIXED = 0;
struct edge
{
    int from, to;
    double w;
};
struct node
{
    int ind, var = UNDET;
    double con = 0;
    node(int _ind = 0, int _var = UNDET, double _con = 0.0)
    {ind = _ind; var = _var; con = _con;}
    void print()
    {
        printf("NODE %lld : ",ind);
        if (var == UNDET)
            printf("UNDETERMINED NODE\n");
        else if (var == FIXED)
            printf("%.3lf\n",con);
        else
            printf("%sx + %.3lf\n",(var==PLUS?"+":"-"),con);
    }
};
node ND[101010];
vector <edge> G[101010];
void report_fail()
{
    cout << "NO\n";
    exit(0);
}
bool visited[101010];
vector <int> topo;
map<int, int> topo_order;
void dfs_run(int rt, bool d = 0)
{
    topo.push_back(rt);
    visited[rt] = true;
    if (ND[rt].var == UNDET)
    {
        ND[rt].var = PLUS;
        ND[rt].con = 0.0;
    }
    for (edge E : G[rt])
    {
        int nxt = E.to;
        if (visited[nxt]) continue;
        if (ND[nxt].var == UNDET)
        {
            ND[nxt].con = E.w - ND[rt].con;
            ND[nxt].var = -ND[rt].var;
            dfs_run(nxt, d);
        }
        else
        {
            if (ND[nxt].var == ND[rt].var)
                continue;
            else
            {
                if (ND[nxt].con + ND[rt].con != E.w)
                {
                    if (d)
                    {
                        printf("MISMATCH %lld %lld\n",rt,nxt);
                        ND[rt].print();
                        ND[nxt].print();
                    }
                    report_fail();
                }
                else continue;
            }
        }
    }
    return;
}
double find_x()
{
    double x = INF;
    for (int i = topo.size()-1; i >= 0; i--)
    {
        int cur = topo[i];
        for (edge E : G[cur])
        {
            int nxt = E.to;
            if (topo_order[nxt] < i)
            {
                if (ND[nxt].var == ND[cur].var)
                {
                    double cons = ND[nxt].con + ND[cur].con;
                    double vars = ND[nxt].var + ND[cur].var;
                    return (E.w - cons) / vars;
                }
                else
                {
                    if (ND[nxt].var + ND[cur].var == 0)
                    {
                        if (ND[nxt].con + ND[cur].con != E.w)
                            report_fail();
                    }
                }
            }
            else continue;
        }
    }
    vector <double> convals;
    for (int i = 0; i<topo.size(); i++)
    {
        convals.push_back((-1)*(ND[topo[i]].var)*ND[topo[i]].con);
    }
    sort(all(convals));
    int sz = convals.size();
    return convals[sz/2];
}
void fix_dfs(int rt, double x)
{
    visited[rt] = true;
    ND[rt].con = ND[rt].var * x + ND[rt].con;
    ND[rt].var = FIXED;
    for (edge E : G[rt])
    {
        if (ND[E.to].var != FIXED)
            fix_dfs(E.to, x);
    }
    return;
}
void const_fix(int rt, double xconst)
{
    visited[rt] = true;
    ND[rt].con = xconst;
    ND[rt].var = FIXED;
    for (edge E : G[rt])
    {
        if (ND[E.to].var != FIXED)
            const_fix(E.to, E.w-xconst);
    }
    return;
}
vector <pair<int, double>> cf;
int32_t main()
{
    usecppio
    int n, m;
    cin >> n >> m;
    for (int i = 1; i<=n; i++) ND[i].ind = i;
    for (int i = 0; i<m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge e = {u, v, w*1.0};
        edge erev = {v, u, w*1.0};
        G[u].push_back(e);
        G[v].push_back(erev);
        if (u == v)
            cf.push_back({u, w*0.5});
    }
    for (auto [u, w] : cf)
    {
        if (!visited[u])
            const_fix(u, w);
    }
    for (int i = 1; i<=n; i++)
    {
        topo.clear();
        topo_order.clear();
        if (!visited[i])
        {
            dfs_run(i);
            for (int j = 0; j<topo.size(); j++)
            {
                topo_order[topo[j]] = j;
            }
            double xval = find_x();
            fix_dfs(i, xval);
        }
    }
    for (int i = 1; i<=n; i++)
    {
        for (edge E : G[i])
        {
            if (ND[E.from].con + ND[E.to].con != E.w)
                report_fail();
        }
    }
    cout << "YES\n";
    for (int i = 1; i<=n; i++)
        cout << fixed << setprecision(10) << ND[i].con << ' ';
}