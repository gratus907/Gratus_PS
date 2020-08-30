#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
#define int ll
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
using cd = int;
const bool debug = 0;

const int dimensions = 2;
const int INF = 9e18;
struct point
{
    cd coord[2] = {0, 0};
    point(){coord[0] = coord[1] = 0;}
    point(int *c){for (int i = 0; i<dimensions; i++) coord[i] = c[i];}
    cd get(int id) const {return coord[id];}
    cd dist(const point &o) const
    {
        cd d = 0;
        for (int i = 0; i<dimensions; i++)
            d += (coord[i]-o.coord[i]) * (coord[i]-o.coord[i]);
        return d;
    }
};

struct node
{
    node(const point& pt) : p(pt), left_(nullptr), right_(nullptr) {}
    cd get(int index) const { return p.get(index);}
    cd dist(const point& pt) const {return p.dist(pt);}
    point p;
    node* left_;
    node* right_;
};
struct node_cmp
{
    node_cmp(int k = 0){ id = k; }
    int id;
    bool operator()(const node &n1, const node &n2)
    {return n1.get(id) < n2.get(id);}
};
struct KDTree
{
    vector <node> nodes;
    node* root = nullptr;
    node* best = nullptr;
    cd best_dist = INF;
    node* build(int begin, int end, int id)
    {
        if (end <= begin) return nullptr;
        int n = (begin + end)/2;
        nth_element(&nodes[begin], &nodes[n], &nodes[0] + end, node_cmp(id));
        id = (id + 1) % dimensions;
        nodes[n].left_ = build(begin, n, id);
        nodes[n].right_ = build(n + 1, end, id);
        return &nodes[n];
    }
    KDTree(const KDTree&) = delete;
    KDTree& operator=(const KDTree&) = delete;
    KDTree(vector <node> v)
    {
        nodes = v;
        root = build(0, nodes.size(), 0);
    }
    void nearest(node* rt, const point p, int id)
    {
        if (rt == nullptr) return;
        cd d = rt->dist(p);
        if ((0 < d && d < best_dist))
        {
            best_dist = d;
            best = rt;
        }
        if (best_dist == 0)
            return;
        cd dx = rt->get(id) - p.get(id);
        id = (id + 1) % dimensions;
        nearest(dx > 0 ? rt->left_ : rt->right_, p, id);
        if (dx*dx >= best_dist)
            return;
        nearest(dx > 0 ? rt->right_ : rt->left_, p, id);
    }
    const point& nearest(const point& pt)
    {
        best = nullptr;
        best_dist = INF;
        nearest(root, pt, 0);
        return best->p;
    }
    const cd nearest_dist(const point& pt)
    {
        point p = nearest(pt);
        return pt.dist(p);
    }
};
vector <node> v;
vector <point> pp;
int32_t main()
{
    usecppio
    int T; cin >> T;
    while(T--)
    {
        v.clear();
        pp.clear();
        int N; cin >> N;
        for (int i = 0; i<N; i++)
        {
            cd a, b; cin >> a >> b;
            cd pc[2] = {a, b};
            point vd = point(pc);
            pp.push_back(vd);
            v.push_back(vd);
        }
        KDTree K = KDTree(v);
        for (auto it:pp)
            cout << K.nearest_dist(it) << '\n';
    }
}