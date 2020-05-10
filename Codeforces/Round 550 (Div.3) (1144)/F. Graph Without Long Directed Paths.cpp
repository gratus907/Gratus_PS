#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;

typedef pair<int,int> pii;

int vertice_state[202020]; // 1 : give. -1 : receive. 0 : undetermined.
vector <pii> edges;
int edge_dir[202020]; // 1 : give. -1 : receive. 0 : undetermined.
vector <pii> graph[202020];
queue <int> q;
int vert_visit[202020];
int n, m;
int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i<m; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        graph[a].PB(MP(b,i));
        graph[b].PB(MP(a,i));
        edges.PB(MP(a,b));
    }
    vertice_state[1] = 1;
    q.push(1);
    vert_visit[1] = 1;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto it:graph[x])
        {
            if(vert_visit[it.first]==0)
            {
                vert_visit[it.first] = vert_visit[x]+1;
                q.push(it.first);
            }
        }
    }
    for (int i = 1; i<=n; i++)
    {
        if (vert_visit[i]%2)
            vertice_state[i] = 1;
        else
            vertice_state[i] = -1;
    }
    for (int i = 0; i<m; i++)
    {
        if(vertice_state[edges[i].first]==vertice_state[edges[i].second])
        {
            printf("NO");
            return 0;
        }
        else
        {
            if (vertice_state[edges[i].first]==1)
                edge_dir[i] = 0;
            else
                edge_dir[i] = 1;
        }
    }
    printf("YES\n");
    for (int i = 0; i<m; i++)
        printf("%d",edge_dir[i]);
}
