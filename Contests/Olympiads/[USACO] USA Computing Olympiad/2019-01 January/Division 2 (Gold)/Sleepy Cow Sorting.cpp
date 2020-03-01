#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair <int, int>;

ordered_set sorted;
int st;
int n;
int arr[101010];
int main()
{
    usecppio
    cin >> n;
    for (int i = 0; i<n; i++)
        cin >> arr[i];
    st = 1;
    sorted.insert(arr[n-1]);
    for (int i = n-2; i>=0; i--)
    {
        if (arr[i] < arr[i+1])
        {
            sorted.insert(arr[i]);
            st++;
        }
        else break;
    }
    int k = n-st;
    cout << k << '\n';
    for (int i = 0; i<k; i++)
    {
        int x = arr[i];
        int pos = n - st + sorted.order_of_key(x) - 1;
        st++;
        sorted.insert(x);
        cout << pos << ' ';
    }
    cout << '\n';
}