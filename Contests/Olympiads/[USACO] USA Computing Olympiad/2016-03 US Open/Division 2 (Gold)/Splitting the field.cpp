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

vector <pii> pt, pt2;

int best_get(vector <pii> &points)
{
    multiset <int> left_y, right_y;
    int value = LLONG_MAX;
    for (auto it:points)
    {
        right_y.insert(it.second);
    }
    int left_end = points.front().first;
    int right_end = points.back().first;
    for (int i = 0; i<points.size()-1; i++)
    {
        left_y.insert(points[i].second);
        right_y.erase(right_y.lower_bound(points[i].second));
        int lyl = *left_y.begin();
        int lyh = *left_y.rbegin();
        int ryl = *right_y.begin();
        int ryh = *right_y.rbegin();
        int left_area = points[i].first-left_end;
        left_area *= (lyh-lyl);
        int right_area = right_end-points[i+1].first;
        right_area *= (ryh-ryl);
        value = min(value, left_area+right_area);
    }
    return value;
}

int32_t main()
{
    usecppio
    int n;
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        int a, b;
        cin >> a >> b;
        pt.push_back({a, b});
        pt2.push_back({b, a});
    }
    sort(all(pt));
    sort(all(pt2));
    int one = pt.back().first-pt.front().first;
    one *= (pt2.back().first-pt2.front().first);
    int two = min(best_get(pt), best_get(pt2));
    cout << one-two << '\n';
}