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
int parent[1010101];
int level[1010101];
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
    while(m--)
    {
        int op,a,b;
        scanf("%d",&op);
        scanf("%d %d",&a,&b);
        if (op==1)
            printf("%s",Find(a)==Find(b)?"YES\n":"NO\n");
        else
            Union(a,b);
    }
}