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
#define int ll
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = false;

vector <int> allgap;
int T[101010];
int n, k;
int32_t main()
{
    usecppio
    cin >> n >> k;
    for (int i = 1; i<=n; i++) cin >> T[i];
    for (int i = 2; i<=n; i++)
        allgap.push_back(T[i]-T[i-1]-1);
    sort(all(allgap),greater<int>());
    int off = 0;
    for (int i = 0; i<k-1; i++)
        off += allgap[i];
    cout << T[n]-T[1]+1-off << '\n';
}