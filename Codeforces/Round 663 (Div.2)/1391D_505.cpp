#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
using pii = pair<int, int>;

int n, m;
int pat_dist[1010100][8];
vector<vector<int>> mat;
vector<string> strs;
int32_t main()
{
    cin >> n >> m;
    if (n >= 4 && m >= 4)
    {
        cout << -1 << '\n';
        return 0;
    }
    if (n == 1 || m == 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i<n; i++)
    {
        string str; cin >> str;
        strs.push_back(str);
    }
    if (n > m)
    {
        mat.resize(m+5, vector<int>(n+5, 0));
        swap(n, m);
        for (int i = 1; i<=n; i++)
            for (int j = 1; j<=m; j++)
                mat[i][j] = strs[j-1][i-1]-'0';
    }
    else
    {
        mat.resize(n+5, vector<int>(m+5, 0));
        for (int i = 1; i<=n; i++)
            for (int j = 1; j<=m; j++)
                mat[i][j] = strs[i-1][j-1]-'0';
    }
    if (n == 2)
    {
        vector <int> colVals;
        for (int i = 1; i<=m; i++)
            colVals.push_back(mat[1][i]+mat[2][i]);
        int cand1 = 0, cand2 = 0;
        for (int i = 0; i<m; i++)
        {
            if (i%2 == 0)
            {
                if (colVals[i]%2 == 0)
                    cand2++;
                else cand1++;
            }
            else
            {
                if (colVals[i]%2 == 0)
                    cand1++;
                else cand2++;
            }
        }
        cout << min(cand1, cand2) << '\n';
    }

    vector <int> patmatch[3][2];
    patmatch[0][0] = {0, 2, 4, 6};
    patmatch[0][1] = {1, 3, 5, 7};
    patmatch[1][0] = {0, 1, 4, 5};
    patmatch[1][1] = {2, 3, 6, 7};
    patmatch[2][0] = {0, 1, 2, 3};
    patmatch[2][1] = {4, 5, 6, 7};
    if (n == 3)
    {
        for (int i = 1; i<=m; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (mat[3-j][i] == 1)
                {
                    for (int it : patmatch[j][0])
                        pat_dist[i][it]++;
                }
                else
                {
                    for (int it : patmatch[j][1])
                        pat_dist[i][it]++;
                }
            }
        }

        // Case 1 : 010101.. and 010101..
        int cand1 = 0;
        for (int i = 1; i<=m; i++)
        {
            if (i%2 == 1)
                cand1 += min(pat_dist[i][0], pat_dist[i][7]);
            else
                cand1 += min(pat_dist[i][2], pat_dist[i][5]);
        }

        // Case 2 : 010101.. and 101010..
        int cand2 = 0;
        for (int i = 1; i<=m; i++)
        {
            if (i%2 == 1)
                cand2 += min(pat_dist[i][1],pat_dist[i][6]);
            else
                cand2 += min(pat_dist[i][3],pat_dist[i][4]);
        }

        // Case 3 : 101010.. and 010101..
        int cand3 = 0;
        for (int i = 1; i<=m; i++)
        {
            if (i%2 == 0)
                cand3 += min(pat_dist[i][1],pat_dist[i][6]);
            else
                cand3 += min(pat_dist[i][3],pat_dist[i][4]);
        }

        // Case 3 : 101010.. and 101010
        int cand4 = 0;
        for (int i = 1; i<=m; i++)
        {
            if (i%2 == 0)
                cand4 += min(pat_dist[i][0], pat_dist[i][7]);
            else
                cand4 += min(pat_dist[i][2], pat_dist[i][5]);
        }
        cout << min(min(cand1, cand2), min(cand3, cand4)) << '\n';
    }
}