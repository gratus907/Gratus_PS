#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define int ll
using pii = pair <int, int>;
#define INF 0x7f7f7f7f7f7f7f7f
const bool debug = 0;
int n, T;
struct problem
{
    int M = 0, R = 0, P = 0;
    bool operator<(problem &other)
    {
        return R * other.P < P * other.R;
    }
};
vector <problem> problems;
int memo[55][101010];
int solve(int curtime, int curprob)
{
    if (curprob >= n) 
        return 0;
    if (curtime > T)
        return -INF;
    if (memo[curprob][curtime]!=-1) return memo[curprob][curtime];
    int x = solve(curtime, curprob+1);
    int y = 0;
    int take_time = curtime+problems[curprob].R;
    if (take_time <= T)
        y = problems[curprob].M-problems[curprob].P*take_time+solve(take_time, curprob+1);
    if (max(x, y)<0)
        return memo[curprob][curtime] = 0;
    else
        return memo[curprob][curtime] = max(x, y);
}
int32_t main()
{
    usecppio
    cin >> n >> T;
    problems.resize(n);
    for (int i = 0; i<n; i++)
        cin >> problems[i].M;
    for (int i = 0; i<n; i++)
        cin >> problems[i].P;
    for (int i = 0; i<n; i++)
        cin >> problems[i].R;
    sort(all(problems));
    memset(memo,-1,sizeof(memo));
    cout << solve(0, 0) << '\n';
}