#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int NUM = 100200;
int n,m;
vector <int> graph[NUM];
int bfs_visit[NUM];
priority_queue <int, vector<int>, greater<int>> q;

void bfs(int i)
{
    q.push(i);
    bfs_visit[i] = 1;
    while (!q.empty())
    {
        int cur = q.top();
        printf("%d ", cur);
        q.pop();
        for (auto it:graph[cur])
        {
            if (!bfs_visit[it])
            {
                bfs_visit[it] = 1;
                q.push(it);
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i<m; i++)
    {
        int a, b;
        scanf("%d %d",&a,&b);
        graph[a].PB(b);
        graph[b].PB(a);
    }
    for (int i = 1; i<=n; i++)
        sort(graph[i].begin(),graph[i].end());
    bfs(1);
}
