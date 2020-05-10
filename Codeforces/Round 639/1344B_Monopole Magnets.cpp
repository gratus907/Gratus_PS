#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;

vector <int> rows[1010], cols[1010];
int board[1010][1010];
int Smagnet[1010][1010];
bool visited[1010][1010];
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};
void dfs(int r, int c)
{
    visited[r][c] = true;
    for (int i = 0; i<4; i++)
    {
        int nr = r+dr[i], nc = c+dc[i];
        if (board[nr][nc]==1 && visited[nr][nc]==0)
        {
            dfs(nr, nc);
        }
    }
}
void printvector(vector <int> &v, string name)
{
    printf("%s : ",name.c_str());
    for (auto it:v)
    {
        cout << (it?'B':'W');
    }
    cout << '\n';
}
int32_t main()
{
    usecppio
    memset(board, -1, sizeof(board));
    int m, n;
    cin >> n >> m;
    for (int i = 1; i<=n; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j<=m; j++)
        {
            if (str[j-1] == '#')
                board[i][j] = 1;
            else board[i][j] = 0;
        }
    }
    bool ok = true;
    for (int i = 1; i<=n; i++)
    {
        vector <int> v;
        for (int j = 1; j<=m; j++)
            if (board[i][j] != board[i][j-1])
                v.push_back(board[i][j]);
        rows[i] = v;
        if (v.size()<=2) continue;
        for (int j = 1; j<v.size()-1; j++)
        {
            if (v[j]==0 && v[j-1]==1 && v[j+1]==1)
            {
                cout << -1 << '\n'; return 0;
            }
        }
    }
    for (int i = 1; i<=m; i++)
    {
        vector <int> v;
        for (int j = 1; j<=n; j++)
        {
            if (board[j][i] != board[j-1][i])
            {
                v.push_back(board[j][i]);
            }
        }
        cols[i] = v;
        if (v.size()<=2) continue;
        for (int j = 1; j<v.size()-1; j++)
        {
            if (v[j]==0 && v[j-1]==1 && v[j+1]==1)
            {
                cout << -1 << '\n'; return 0;
            }
        }
    }
    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j<=m; j++)
        {
            if (board[i][j]==1)
                Smagnet[i][j] = 1;
            if (rows[i].size()==1 && cols[j].size()==1)
            {
                if (rows[i][0] == 0 && cols[j][0] == 0)
                {
                    Smagnet[i][j] = 1;
                }
            }
        }
    }
    for (int i = 1; i<=n; i++)
    {
        bool sk = false;
        for (int j = 1; j<=m; j++)
        {
            if (Smagnet[i][j]) sk = true;
        }
        if (!sk)
        {
            cout << -1 << '\n'; return 0;
        }
    }
    for (int i = 1; i<=m; i++)
    {
        bool sk = false;
        for (int j = 1; j<=n; j++)
        {
            if (Smagnet[j][i]) sk = true;
        }
        if (!sk)
        {
            cout << -1 << '\n'; return 0;
        }
    }
    int cnt = 0;
    for (int i = 1; i<=n; i++)
    {
        for (int j = 1; j<=m; j++)
        {
            if (board[i][j]==1 && visited[i][j]==0)
            {
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}