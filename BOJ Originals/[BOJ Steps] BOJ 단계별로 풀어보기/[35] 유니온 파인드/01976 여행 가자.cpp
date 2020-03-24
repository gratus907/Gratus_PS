#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define ll long long
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define gcd(A,B) (__gcd(A,B))
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
#define mod 1000000007LL
#define all(x) x.begin(), x.end()
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int n;
int m;
int parent[205];
int level[205];
int Find(int x) // Finding root node of x
{
    if (x==parent[x])
        return x;
    else
        return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    int u = Find(x);
    int v = Find(y);
    if (u == v)
        return;
    if (level[u] > level[v])
    {
        Union(v,u);
        return;
    }
    parent[u] = v;
    if (level[u]==level[v])
        level[v]++;
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for (int i = 1; i<=n; i++)
    {
        parent[i] = i;
        level[i] = 1;
    }
    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j<=n; j++)
        {
            int x;
            scanf("%d",&x);
            if (x)
                Union(i,j);
        }
    }
    bool flag = 1;
    int first;
    scanf("%d",&first);
    int u = Find(first);
    for (int i = 2; i<=m; i++)
    {
        int x;
        scanf("%d",&x);
        flag &= (Find(x)==u);
    }
    printf("%s",flag?"YES":"NO");
}