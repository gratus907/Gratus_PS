#include <bits/stdc++.h>
#define ll long long
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

ll arr[101010];

int main()
{
    int n, m;
    scanf("%d %d",&n,&m);
    for (int i = 1; i<=n; i++)
    {
        ll x;
        scanf("%lld",&x);
        arr[i] = arr[i-1] + x;
    }
    for (int i = 0; i<m; i++)
    {
        int a, b;
        scanf("%d %d",&a,&b);
        printf("%lld\n",arr[b]-arr[a-1]);
    }
}