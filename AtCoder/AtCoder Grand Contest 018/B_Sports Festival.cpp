#include <bits/stdc++.h>
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
int n, m;
int pref[330][330];
int32_t main()
{
    usecppio
    cin >> n >> m;
    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j<=m; j++)
        {
            int x;
            cin >> x;
            pref[i][x] = m-j+1;
        }
    }
    int best = INT_MAX;
    vector <int> choose;
    for (int i = 1; i<=m; i++)
        choose.push_back(i);
    for (int i = 0; i<m; i++)
    {
        vector <int> vv;
        int best_sport = 0, best_score = 0;
        int choice[330]; memset(choice, 0, sizeof(choice));
        for (int j = 1; j<=n; j++)
        {
            int u = 0, b = 0;
            for (auto it:choose)
            {
                if (pref[j][it]>u)
                {
                    u = pref[j][it];
                    b = it;
                }
            }
            choice[b]++;
        }
        best_sport = (max_element(choice+1, choice+m+1)-choice);
        best_score = choice[best_sport];
        best = min(best, best_score);
        for (auto it:choose)
            if (it != best_sport) 
              vv.push_back(it);
        choose = vv;
    }
    cout << best << '\n';
}
