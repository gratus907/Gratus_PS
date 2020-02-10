#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
#define int ll
map <vector <int>, int> mp[5];
int n;
int pc;
vector <int> flav[50505];
int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        flav[i].resize(5);
        cin >> flav[i][0] >> flav[i][1] >> flav[i][2] >> flav[i][3] >> flav[i][4];
        sort(all(flav[i]));
        for (int choose = 1; choose<32; choose++)
        {
            vector <int> tmp;
            for (int j = 0; j<5; j++)
                if (choose & (1<<j))
                    tmp.push_back(flav[i][j]);
            mp[tmp.size()-1][tmp]++;
        }
    }
    int ind = 1;
    for (int i = 0; i<5; i++)
    {
        int tp = 0;
        for (auto it:mp[i])
            tp += (it.second)*(it.second-1)/2;
        pc += tp*ind;
        ind *= (-1);
    }
    cout << n*(n-1)/2-pc;
}