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
const int M = 1000000;
int n;
int dst[1010100];
pii min_val[101010];
vector <pii> divs[1010100];
vector <int> nums;
inline int dtcal(int a, int b, int g)
{
    return dst[a]+dst[b]-2*dst[g];
}
inline void try_minimize(int a, int b)
{
    a--; b--;
    int x = dtcal(nums[a], nums[b], __gcd(nums[a], nums[b]));
    min_val[a] = min(min_val[a], {x, b});
    min_val[b] = min(min_val[b], {x, a});
    return;
}
int32_t main()
{
    usecppio
    for (int i = 0; i<101010; i++) min_val[i] = {INF, INF};
    for (int i = 2; i<=M; i+=2)
    {
        if (dst[i] == 0)
        {
            int p = i;
            while(p<=M)
            {
                for (int j = p; j<=M; j+=p)
                    dst[j]++;    
                p *= i;
            }
        }
        if (i==2) i--;
    }
    cin >> n;
    for (int i = 0; i<n; i++) 
    {
        int x;
        cin >> x;
        nums.push_back(x);
        for (int j = 1; j*j<=x; j++)
        {
            if (x%j==0)
            {
                divs[j].push_back({x, i+1});
                if (x!=j*j)
                    divs[x/j].push_back({x, i+1});
            }
        }
    }
    for (int i = 1; i<=M; i++)
        sort(all(divs[i]),[](pii &a, pii &b)->
            bool 
            {
                if (dst[a.first]==dst[b.first]) return a.second < b.second;
                else return dst[a.first]<dst[b.first];
            });
    for (int i = 1; i<=M; i++)
    {
        if (divs[i].size()<2) continue;
        if (debug)
        {
            printf("%lld: ",i);
            for (auto it:divs[i])
                printf("%lld ",it);
            printf("\n");
        }
        
        try_minimize(divs[i][0].second, divs[i][1].second);
        for (int j = 1; j<divs[i].size(); j++)
            try_minimize(divs[i][0].second, divs[i][j].second);
    }
    for (int i = 0; i<n; i++)
    {
        cout << min_val[i].second+1 << '\n';
    }
}