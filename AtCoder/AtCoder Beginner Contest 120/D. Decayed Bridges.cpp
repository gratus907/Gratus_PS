#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define ll long long
#define int ll
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

const int V = 101010;

vector <pii> edge_list;
vector <ll> answer_list;
ll ans;
struct Disjoint_Set_Union
{
    int connected;
    int parent[V], size[V];

    void init(int n)
    {
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
        connected=n;
    }
    int Find(int k)
    {
        while(k!=parent[k])
        {
            parent[k]=parent[parent[k]];
            k=parent[k];
        }
        return k;
    }
    int getSize(int k)
    {
        return size[Find(k)];
    }
    void merge(int x, int y)
    {
        int u=Find(x), v=Find(y);
        connected--;
        if(u==v)
            return;
        if(size[u]>size[v])
            swap(u, v);
        ans -= (size[u]*size[v]);
        size[v]+=size[u];
        size[u] = 0;
        parent[u] = parent[v];
    }
} dsu;

int32_t main()
{
    int n, m;
    scanf("%lld %lld",&n,&m);
    dsu.init(101010);
    for (int i = 0; i<m; i++)
    {
        int a, b;
        scanf("%lld %lld",&a,&b);
        edge_list.push_back({a,b});
    }
    ans = n*(n-1)/2;
    answer_list.push_back(ans);
    for (int i = m-1; i>0; i--)
    {
        int a, b;
        tie(a, b) = edge_list[i];
        dsu.merge(a,b);
        answer_list.push_back(ans);
    }
    reverse(all(answer_list));
    for (auto it:answer_list)
        printf("%lld\n",it);
}
