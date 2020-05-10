#include<bits/stdc++.h>
using namespace std;

struct door
{
    int to, left, right;
    door (int a, int b, int c)
    {
        to = a, left = b, right = c;
    }
};
int n, m, k, s, t;
vector <int> changer;
vector <door> graph[1010];
vector <pair <int, int>> group;

bool canpass(int x)
{
    bool visit[1010];
    memset(visit,0,sizeof(visit));
    visit[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto it:graph[u])
        {
            if (!visit[it.to])
            {
                if (it.left <= x && x <= it.right)
                {
                    q.push(it.to);
                    visit[it.to] = 1;
                }
            }
        }
    }
    return visit[t];
}
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    scanf("%d %d",&s,&t);
    changer.push_back(1);
    changer.push_back(k+1);
    for (int i = 0; i<m; i++)
    {
        int u, v, c, d;
        scanf("%d %d %d %d",&u,&v,&c,&d);
        graph[u].push_back(door(v,c,d));
        changer.push_back(c);
        changer.push_back(d+1);
    }
    sort(changer.begin(),changer.end());
    changer.erase(unique(changer.begin(),changer.end()),changer.end());
    int s = changer.size();
    for (int i = 0; i < s-1; i++)
    {
        group.push_back({changer[i],changer[i+1]-1});
    }
    int ss = group.size();
    int ans = 0;
    for (int i = 0; i<ss; i++)
    {
        if (canpass(group[i].first))
        {
            ans += (group[i].second-group[i].first+1);
        }
    }
    printf("%d",ans);
}
