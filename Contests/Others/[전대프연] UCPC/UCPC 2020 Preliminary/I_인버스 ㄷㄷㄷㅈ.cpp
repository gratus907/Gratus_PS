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

vector<pii> edges;
void cross_build(int cross)
{
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({3, 4});
    edges.push_back({4, 5});
    edges.push_back({3, 6});
    edges.push_back({6, 7});
    edges.push_back({3, 8});
    edges.push_back({8, 9});
    for (int i = 1; i<cross; i++)
    {
        int center = i*6+3;
        edges.push_back({center, center+1});
        edges.push_back({center+1, center+2});
        edges.push_back({center, center+3});
        edges.push_back({center+3, center+4});
        edges.push_back({center, center+5});
        edges.push_back({center+5, center+6});
    }
}
void print_ans()
{
    for (auto it:edges)
        cout << it.first << " " << it.second << '\n';
}
int32_t main()
{
    usecppio
    int n; cin >> n;
    if (n <= 8)
    {
        string ans;
        if (n == 6)
            ans = "1 2\n2 3\n2 4\n4 5\n5 6\n";
        else if (n == 7)
            ans = "1 2\n2 3\n2 4\n4 5\n5 6\n4 7\n";
        else if (n == 8)
            ans = "1 2\n2 3\n2 4\n4 5\n5 6\n3 7\n5 8\n";
        cout << ans;
        return 0;
    }
    int cross = (n-3)/6;
    cross_build(cross);
    int more = n-(cross*6+3);
    int lvt = cross*6+4;
    int last_center = cross*6-3;
    if (more == 1)
        edges.push_back({2, lvt++});
    else if (more == 2)
    {
        edges.push_back({2, lvt++});
        edges.push_back({4, lvt++});
    }
    else if (more == 3)
    {
        edges.push_back({2, lvt++});
        edges.push_back({4, lvt++});
        edges.push_back({6, lvt++});
    }
    else if (more == 4)
    {
        edges.push_back({2, lvt++});
        edges.push_back({4, lvt++});
        edges.push_back({6, lvt++});
        edges.push_back({last_center+5, lvt++});
    }
    else if (more == 5)
    {
        edges.push_back({1, lvt});
        edges.push_back({1, lvt+1});
        edges.push_back({lvt+1, lvt+2});
        edges.push_back({lvt+2, lvt+3});
        edges.push_back({lvt+2, lvt+4});
    }
    print_ans();
}