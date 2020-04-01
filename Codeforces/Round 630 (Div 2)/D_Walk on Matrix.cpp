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

int big = (1<<17);
int32_t main()
{
    int k; cin >> k;
    printf("3 3\n");
    printf("%lld %lld %lld\n%lld %lld %lld\n%lld %lld %lld\n",big+k,k,k,big,big,big+k,big,big,k);
}