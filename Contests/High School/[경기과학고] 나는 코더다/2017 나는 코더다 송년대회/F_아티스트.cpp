#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
using pii = pair<int, int>;
using D = long double;
int n, m;
vector <pii> art;
const bool debug = true;
inline D run_with_config(D r, bool print = false)
{
    int sw = 0, sh = 0;
    auto cmp = [r](pii &a, pii &b)
    {
        return a.first*r+a.second < b.first*r+b.second;
    };
    sort(all(art),cmp);
    for (int i = 0; i<m; i++)
    {
        sw += art[i].first;
        sh += art[i].second;
    }
    return (sw*sh);
}
int32_t main()
{
    clock_t start = clock();
    const D magic = 1.05;
    const D magic2 = magic*10;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(1/magic, magic);
    std::uniform_real_distribution<> disfar(1/magic2, magic2);
    std::uniform_real_distribution<> dis2(0, 1);
    cin >> n >> m;
    for (int i = 0; i<n; i++)
    {
        int w, h;
        cin >> w >> h;
        art.push_back({w, h});
    }
    D ratio = 1;
    D iT = 1;
    D k = 0.99;
    D e1 = run_with_config(1);
    D e2 = 0;
    int iter = 0;
    while(true)
    {
        D u = (clock()-start)*1.0/CLOCKS_PER_SEC;
        if (u > 0.95) break;
        iter++;
        D newratio = ratio * dis(gen);
        if (iter%5==0)
            newratio = ratio * disfar(gen);
        if (iter%1000==0 && u > 0.7)
        {
            newratio = 1/ratio;
        }    
        e2 = run_with_config(newratio);
        D p = exp((e1-e2)/(iT));
        if (p > dis2(gen))
        {
            ratio = newratio;
            e1 = e2;
        }
        iT *= k;
    }
    int sacand = (int)run_with_config(ratio);
    int cand1 = (int)run_with_config(0);
    int cand2 = (int)run_with_config(1e18);
    int ans = min(cand1, cand2);
    ans = min(ans, sacand);
    cout << ans << '\n';
}