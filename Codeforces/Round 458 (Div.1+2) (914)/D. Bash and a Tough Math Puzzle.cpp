#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#pragma GCC optimize("Ofast")
#define gcd(A,B) __gcd(A,B)
using namespace std;

int segtree[2002000];
int treesp = 1;
int ans = 0;
void query(int rt, int l, int r, int s, int e, int x)
{
    //printf("Query : %d %d %d %d %d %d\n",rt,l,r,s,e,x);
    if (ans>2)
        return;
    if (rt > treesp*2)
        return;
    if (e < s|| r < l || r < s || e < l)
        return;
    if ((l<=0) || (r >= treesp*2) || (r<l) )
        return;
    if (segtree[rt]%x == 0)
        return;
    if ((l <= s) && (e <= r))
    {
        while(rt < treesp)
        {
            if (segtree[rt*2]%x)
            {
                if (segtree[rt*2+1]%x)
                {
                    ans+=10000;
                    return;
                }
                else
                    rt *= 2;
            }
            else if (segtree[rt*2+1]%x)
                rt = rt*2+1;
        }
        ans++;
        return;
    }
    int m = (s+e)/2;
    query(rt*2,l,r,s,m,x);
    if (ans>=2)
        return;
    else
        query(rt*2+1,l,r,m+1,e,x);
}

void update(int pos, int val)
{
    segtree[treesp+pos-1] = val;
    int u = (treesp+pos-1)/2;
    while(u >= 1)
    {
        segtree[u] = gcd(segtree[u*2],segtree[u*2+1]);
        u/=2;
    }
}

int main()
{
    int n;
    int q;
    scanf("%d",&n);
    while (treesp<n)
        treesp*=2;
    for (int i = 0; i<n; i++)
        scanf("%d",segtree+(treesp+i));
    for (int i = treesp-1; i>=1; i--)
    {
        segtree[i] = gcd(segtree[2*i],segtree[2*i+1]);
    }

    scanf("%d",&q);
    for (int i = 0; i<q; i++)
    {
        ans = 0;
        int t,l,r,x;
        int pos,val;
        scanf("%d",&t);
        if (t==1)
        {
            scanf("%d %d %d",&l,&r,&x);
            query(1,l,r,1,treesp,x);
            if (ans >= 2)
                printf("NO\n");
            else
                printf("YES\n");
        }
        else if (t==2)
        {
            scanf("%d%d",&pos,&val);
            update(pos,val);
        }
    }
}
