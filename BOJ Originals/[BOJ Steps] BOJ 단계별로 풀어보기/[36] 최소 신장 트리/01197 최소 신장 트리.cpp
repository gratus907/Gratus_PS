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
const int INF = INT_MAX;

vector <pii> Tree[101010];
int V, E;
bool visit[101010];
priority_queue <pii, vector<pii>, greater<pii>> pq;

void add(int i)
{
    visit[i] = true;
    for (auto it:Tree[i])
        pq.push(it);
}
int Prim(int start)
{
    int mstlen = 0;
    add(start);
    while(!pq.empty())
    {
        int cur = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        if (visit[cur])
            continue;
        else
        {
            mstlen+=weight;
            add(cur);
        }
    }
    return mstlen;
}

int main()
{
    scanf("%d %d",&V,&E);
    for (int i = 0; i<E; i++)
    {
        int s,e,w;
        scanf("%d %d %d",&s,&e,&w);
        Tree[s].push_back({w,e});
        Tree[e].push_back({w,s});
    }
    printf("%d",Prim(1));
}