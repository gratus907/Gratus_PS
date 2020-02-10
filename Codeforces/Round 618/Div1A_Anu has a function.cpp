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
 
vector <int> v;
vector <pii> vv;
vector <int> numbers[32];
int save = -1;
set<int> st;
int32_t main()
{
    usecppio
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i<n; i++)
    {
        cin >> v[i];
        for (int j = 0; j<31; j++)
        {
            if ((1<<j) & v[i])
            {
                numbers[j].push_back(v[i]);
            }
        }
    }
    for (int i = 31; i>=0; i--)
    {
        if (numbers[i].size()==1)
        {
            if (st.find(numbers[i][0])==st.end())
            {
                vv.push_back({i,numbers[i][0]});
                st.insert(numbers[i][0]);
            }
 
        }
    }
    for (auto it:v)
    {
        if (st.find(it)==st.end())
        {
            vv.push_back({0,it});
        }
    }
    for (auto it:vv)
    {
        cout << it.second << ' ';
    }
    cout << '\n';
}