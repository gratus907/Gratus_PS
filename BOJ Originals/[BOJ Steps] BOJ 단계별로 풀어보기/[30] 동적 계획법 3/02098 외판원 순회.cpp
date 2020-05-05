#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int INF = 2e9;
int n;
int weight[20][20];
int dp[20][303030];
int tsp(int cur, int done) 
{
    if(done == (1<<n)-1)
    {
        if (weight[cur][0])
            return weight[cur][0];
        else return INF;
    }
    if(dp[cur][done] > 0)
        return dp[cur][done];
    dp[cur][done] = INF;
    for(int i = 0; i<n; i++) 
        if(!(done & (1<<i)) && weight[cur][i] > 0)
            dp[cur][done] = min(dp[cur][done], tsp(i, done|(1<<i)) + weight[cur][i]);
    return dp[cur][done];
}
 
int32_t main()
{
    usecppio
    cin >> n;
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            cin >> weight[i][j];
    cout << tsp(0, 1) << '\n';
}