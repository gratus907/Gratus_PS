#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int k, n, m;
int A, B;
int dist[404050];
const int INF = 987654321987654321;
const int MX = 404040;
struct Edge
{
    int dest, w;
    bool operator<(const Edge &p) const
    {
        return w > p.w;
    }
};

vector <Edge> graph[404040];
bool inQ[MX];
void spfa(int start)
{
    fill(dist, dist + MX, INF);
    deque <int> q;
    dist[start] = 0;
    inQ[start] = true;
    q.push_back(start);
    while (!q.empty())
    {
        int here = q.front();
        q.pop_front();
        inQ[here] = false;
        for (int i = 0; i < graph[here].size(); i++)
        {
            int next = graph[here][i].dest;
            int cost = graph[here][i].w;
            if(dist[next] > dist[here] + cost)
            {
                dist[next] = dist[here] + cost;
                //printf("Update Dist %lld = %lld\n",next, dist[next]);
                if (!inQ[next])
                {
                    q.push_back(next);
                    inQ[next] = true;
                    if (dist[q.back()]<dist[q.front()])
                    {
                        q.push_front(q.back());
                        q.pop_back();
                    }
                }
            }
        }
    }
}


int32_t main()
{
    usecppio
    cin >> k >> n >> m;
    for (int i = 0; i<m; i++)
    {
        int a, b, t, h;
        cin >> a >> b >> t >> h;
        for (int j = 0; j<k; j++)
        {
            if (j + h >= k) break;
            graph[a*k+j].push_back({b*k+(j+h), t});
            graph[b*k+j].push_back({a*k+(j+h), t});
        }
    }
    cin >> A >> B;
    spfa(A*k);
    int min_dist = INF;
    for (int i = 0; i<k; i++)
    {
        //printf("Dist to %lld : %lld\n",B*k+i, dist[B*k+i]);
        min_dist = min(min_dist, dist[B*k+i]);
    }
    if (min_dist >=1e12)
        cout << -1 << '\n';
    else 
        cout << min_dist << '\n';
}