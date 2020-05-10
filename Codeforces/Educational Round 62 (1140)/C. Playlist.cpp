#include <bits/stdc++.h>
#define ll long long
#define int long long
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define MP make_pair
#define PB push_back
using namespace std;

typedef pair<int,int> pii;

vector <pii> songs;
int pl = 0;
priority_queue <int, vector<int>, greater<int>> songlen;
int32_t main()
{
    int n,k;
    scanf("%lld %lld",&n,&k);
    for (int i = 0; i<n; i++)
    {
        int b,t;
        scanf("%lld %lld",&t,&b);
        songs.PB(MP(b,t));
    }
    sort(songs.begin(), songs.end(), greater<pii>());
    int cur_time = 0;
    for (int i = 0; i<n; i++)
    {
        songlen.push(songs[i].second);
        cur_time += songs[i].second;
        if (i>=k)
        {
            int u = songlen.top();
            cur_time -= u;
            songlen.pop();
        }
        pl = MAX(pl, cur_time*songs[i].first);
    }
    printf("%lld",pl);
}
