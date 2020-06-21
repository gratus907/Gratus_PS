#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define int ll
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
int n, m, large, eq;
double prob[505050];
vector <int> val;
string state[3] = {"DEAD", "SAME", "ALIVE"};
void calc()
{
    if (eq)
        val.push_back(0);
    else
        val.push_back(1*(large%2 ? 1:-1));
}
int32_t main()
{
    usecppio
    cin >> n >> m;
    for (int i = 1; i<=n; i++)
    {
        cin >> prob[i];
        if (prob[i]==0.5) eq++;
        if (prob[i]>0.5) large++;
    }
    calc();
    while(m--)
    {
        int idx; cin >> idx;
        if (prob[idx]>0.5) large--;
        else if (prob[idx]==0.5) eq--;
        cin >> prob[idx];
        if (prob[idx]>0.5) large++;
        else if (prob[idx]==0.5) eq++;
        calc();
    }
    for (auto it:val)
        cout << state[it+1] << '\n';
}