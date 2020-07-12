#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int max_stat[32];
int stat[10101][5];
int solve()
{
    int n, k; cin >> n >> k;
    memset(stat, 0, sizeof(stat));
    for (int i = 0; i<n; i++)
        cin >> stat[i][0] >> stat[i][1] >> stat[i][2] >> stat[i][3] >> stat[i][4];
    memset(max_stat, 0, sizeof(max_stat));
    int res = -1e9;
    for (int i = 1; i<32; i++)
    {
        for (int j = 0; j<n; j++)
        {
            int cur = 0;
            for (int k = 0; k<5; k++)
                if ((1<<k) & i)
                    cur += stat[j][k];
            max_stat[i] = max(max_stat[i], cur);
        }
    }
    if (k == 1)
    {
        return max_stat[31];
    }
    else if (k == 2)
    {
        for (int i = 1; i<32; i++)
            res = max(res, max_stat[i]+max_stat[31-i]);
        return res;
    }
    else if (k == 3)
    {
        for (int i = 1; i<32; i++)
        {
            for (int j = 1; j<32; j++)
            {
                if (i + j > 31) continue;
                if (i & j) continue;
                res = max(res, max_stat[i]+max_stat[j]+max_stat[31-i-j]);
            }
        }
        return res;
    }
    else if (k == 4)
    {
        for (int i = 1; i<32; i++)
        {
            for (int j = 1; j<32; j++)
            {
                if (i & j) continue;
                for (int k = 1; k<32; k++)
                {
                    if (i & k) continue;
                    if (j & k) continue;
                    if (i+j+k > 31) continue;
                    res = max(res, max_stat[i]+max_stat[j]+max_stat[k]+max_stat[31-i-j-k]);
                }
            }
        }
        return res;
    }
    else
        return max_stat[1]+max_stat[2]+max_stat[4]+max_stat[8]+max_stat[16];
}
int32_t main()
{
    usecppio
    int T; cin >> T;
    while(T--)
        cout << solve() << '\n';
}