#include <bits/stdc++.h>
#define int ll
#define ll long long
using namespace std;
int n,m;
int bi[102000];
int gi[102000];
int change;
int ans = 0;
int32_t main()
{
    scanf("%lld %lld",&n,&m);
    for (int i = 0; i<n; i++)
        scanf("%lld",bi+i);
    sort(bi,bi+n);
    for (int i = 0; i<n; i++)
        ans += bi[i]*m;
    for (int i = 0; i<m; i++)
    {
        scanf("%lld",gi+i);
        if (gi[i]<bi[n-1])
        {
            printf("-1");
            return 0;
        }
    }
    sort(gi,gi+m);
    for (int i = 1; i<=m-1; i++)
        ans += (gi[i]-bi[n-1]);
    if (gi[0] > bi[n-1])
        ans += (gi[0]-bi[n-2]);
    printf("%lld",ans);
}
