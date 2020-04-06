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
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = 0;
#define int ll
const int mod = 1000000007;

int arr[505050];
ll cnt, n;

void merge(int l, int mid, int r)
{
    vector <int> sorted;
    int u = l, v = mid+1;
    int k = 0;
    while (u <= mid && v <= r)
    {
        if (arr[u] > arr[v])
        {
            cnt += (v-k-l);
            sorted.push_back(arr[v++]);
            k++;
        }
        else
        {
            sorted.push_back(arr[u++]);
            k++;
        }
    }
    while(u<=mid)
        sorted.push_back(arr[u++]);
    while(v<=r)
        sorted.push_back(arr[v++]);
    for (int i = l; i<=r; i++)
    {
        arr[i] = sorted[i-l];
    }
}
void merge_sort(int l, int r)
{
    if (l < r)
    {
        int mid = (l+r)/2;
        merge_sort(l, mid);
        merge_sort(mid+1, r);
        merge(l, mid, r);
    }
}

int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    merge_sort(0, n-1);

    cout << cnt << '\n';
}