#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define MOD 1000000007
using pii = pair <int, int>;

int n, k;
vector <string> strls;
vector <vector <string>> v;
int32_t main()
{
    ifstream fin("word.in");
    ofstream fout("word.out");
    fin >> n >> k;
    strls.resize(n);
    v.resize(n);
    for (int i = 0; i<n; i++)
        fin >> strls[i];
    int cur = 0, ptr = 0;
    for (int i = 0; i<n; i++)
    {
        int nxt = strls[i].size();
        if (cur+nxt > k)
        {
            ptr++;
            cur = nxt;
        }
        else
            cur += nxt;
        v[ptr].push_back(strls[i]);
    }
    for (int i = 0; i<n; i++)
    {
        if (v[i].empty()) continue;
        else
        {
            int sz = v[i].size();
            for (int j = 0; j<sz; j++)
                fout << v[i][j] << " \n"[j==(sz-1)];
        }
    }
    fout.close();
    return 0;
}