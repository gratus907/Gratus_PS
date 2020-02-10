#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair <int, int>;
 
struct segment
{
    int left, right;
    double value;
    segment(int a = 0, int b = 0, double c = 0)
    {
        left = a, right = b, value = c;
    }
    bool operator<(const segment &other)
    {
        return value < other.value;
    }
    inline int length()
    {
        return right-left+1;
    }
    inline void print()
    {
        printf("Segment %d to %d : %lf\n", left, right, value);
    }
};
 
segment seg_merge(segment &a, segment &b)
{
    segment newseg;
    newseg.left = a.left;
    newseg.right = b.right;
    newseg.value = (b.value*b.length())+(a.value*a.length());
    newseg.value /= newseg.length();
    return newseg;
}
 
vector <segment> v;
vector <segment> tmp;
int n;
 
int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        int c; cin >> c;
        v.push_back({i,i,c*1.0});
    }
    while(true)
    {
        bool flag = 0;
        for (auto it:v)
        {
            if (tmp.empty())
            {
                tmp.push_back(it);
                continue;
            }
            segment u = tmp.back();
            tmp.pop_back();
            if (it < u)
            {
                flag = true;
                u = seg_merge(u,it);
                tmp.push_back(u);
            }
            else
            {
                tmp.push_back(u);
                tmp.push_back(it);
            }
        }
        v = tmp;
        tmp.clear();
        if (!flag)
            break;
    }
    for (auto it:v)
    {
        int u = it.length();
        for (int i = 0; i<u; i++)
        {
            cout << fixed << setprecision(10) << it.value << '\n';
        }
    }
}