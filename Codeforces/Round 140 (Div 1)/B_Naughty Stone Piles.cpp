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
const bool debug = 0;

int n, q;
vector <int> arr;
int presum[101010];
int res[101010];
int32_t main()
{
    usecppio
    cin >> n;
    arr.resize(n);
    for (int i = 0; i<n; i++) cin >> arr[i];
    sort(all(arr), greater<int>());
    for (int i = 1; i<=n; i++)
        presum[i] = presum[i-1] + arr[i-1];
    for (int i = 1; i<=n; i++)
    {
        int ind = 1;
        int k = i;
        int u = 1;
        while(ind < n)
        {
            int nind = ind + k;
            res[i] += (presum[min(nind, n)]-presum[ind])*u;
            k *= i; u++;
            ind = nind;
        }
    }
    for (int i = n+1; i<=100000; i++) res[i] = res[n];
    cin >> q;
    while(q--)
    {
        int x; cin >> x;
        cout << res[x] << ' ';
    }
}