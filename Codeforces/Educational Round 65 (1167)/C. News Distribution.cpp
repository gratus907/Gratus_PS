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

vector <int> tree[505050];
int ans[505050];
int visit[505050];
queue <int> q;
vector <int> currentvisit;
int n, m;
int main()
{
    scanf("%d %d",&n,&m);
    for (int i = 1; i<=n; i++)
    {
        tree[i].push_back(i);
    }
    for (int i = 0; i<m; i++)
    {
        int x;
        scanf("%d",&x);
        if (x>1)
        {
            int hub;
            scanf("%d",&hub);
            for (int j = 1; j<x; j++)
            {
                int tmp;
                scanf("%d",&tmp);
                tree[hub].PB(tmp);
                tree[tmp].PB(hub);
            }
        }
        if (x==1)
        {
            int hub;
            scanf("%d",&hub);
            continue;
        }
    }
    for (int i = 1; i<=n; i++)
    {
        currentvisit.clear();
        int nodes = 0;
        if (visit[i])
        {
            continue;
        }
        else
        {
            visit[i] = 1;
            nodes = 1;
            q.push(i);
            currentvisit.PB(i);
            while(!q.empty())
            {
                int x = q.front();
                q.pop();
                //printf("%d ",x);
                for (auto it:tree[x])
                {
                    if (!visit[it])
                    {
                        currentvisit.PB(it);
                        nodes++;
                        visit[it] = 1;
                        q.push(it);
                    }
                }
            }
            for (auto it:currentvisit)
                ans[it] = nodes;
            //printf("\n\n");
        }
    }

    for (int i = 1; i<=n; i++)
        printf("%d ",ans[i]);
}
