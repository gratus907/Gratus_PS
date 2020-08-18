#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
#define int ll
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
const bool debug = 0;

const int INF = 2e9;
struct Line // Linear function ax + b
{
    int a, b;
    int eval(int x)
    {
        return a*x + b;
    }
};

struct LiChao
{
    LiChao(){init(-INF,INF);}
    struct Node // [start, end] has line f
    {
        int left, right;
        int start, end;
        Line f;
    };

    Node new_node(int a, int b)
    {
        return {-1,-1,a,b,{0,-INF}};
        // for min, change -INF to INF
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
            nodes[n].f = lhi;
            // for min, lhi -> llo
            return;
        }
        else if (llo.eval(xm) > lhi.eval(xm))
        {
            nodes[n].f = llo;
            // for min, llo -> lhi
            if (nodes[n].left == -1)
            {
                nodes[n].left = nodes.size();
                nodes.push_back(new_node(xl,xm));
            }
            insert(nodes[n].left, lhi);
            // for min, lhi -> llo
        }
        else
        {
            nodes[n].f = lhi;
            // for min, lhi -> llo
            if (nodes[n].right == -1)
            {
                nodes[n].right = nodes.size();
                nodes.push_back(new_node(xm+1,xr));
            }
            insert(nodes[n].right,llo);
            // for min, llo -> lhi
        }
    }
    void insert(Line f)
    {
        insert(0, f);
    }
    int get(int n, int q)
    {
        // for min, max -> min, -INF -> INF
        if (n == -1) return -INF;
        int xl = nodes[n].start, xr = nodes[n].end;
        int xm = (xl + xr)/2;
        if (q > xm) return max(nodes[n].f.eval(q), get(nodes[n].right, q));
        else return max(nodes[n].f.eval(q), get(nodes[n].left, q));
    }
    int get(int pt)
    {
        return get(0, pt);
    }
};

LiChao CHT;

struct box
{
    int w, h;
};
int n;
int tW = 0, tV = 0;
int maxval = 0;
vector <box> boxs;
Line toLine(box b)
{
    return {-b.w, b.w*(tW-b.w+b.h)};
}
int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        int wi, hi; cin >> wi >> hi;
        if (wi < hi) swap(wi, hi);
        boxs.push_back({wi, hi});
    }
    sort(all(boxs), [](auto &p, auto &q){
        if (p.w == q.w)
            return p.h > q.h;
        return p.w > q.w;
    });
    for (auto it:boxs)
    {
        tW += it.w;
        tV += (it.w * it.h);
    }
    CHT.insert(toLine(boxs[n-1]));
    for (int i = n-2; i>=0; i--)
    {
        maxval = max(maxval, CHT.get(boxs[i].w)+boxs[i].w*boxs[i].h-tV);
        CHT.insert(toLine(boxs[i]));
    }
    cout << maxval << '\n';
}