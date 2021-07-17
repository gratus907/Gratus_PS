#include <bits/stdc++.h>
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int n, m, k;
vector <bitset<505>> reach;
vector <bitset<505>> invreach;
vector <vector <int>> G;
int indeg[505];

void bfs () {
    queue <int> q;
    for (int i = 1; i <= n; i++) {
        invreach[i][i] = true;
        if (indeg[i] == 0)
            q.push(i);
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nxt : G[x]) {
            indeg[nxt]--;
            invreach[nxt] |= invreach[x];
            if (indeg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            reach[i][j] = invreach[j][i];
        }
    }
}
void add_edge(int a, int b) {
    for (int i = 1; i <= n; i++) {
        if (reach[i][a]) {
            reach[i] |= reach[b];
        }
    }
}
string solve() {
    cin >> n >> m >> k;

    reach.clear();
    reach.resize(n + 5);
    invreach.clear();
    invreach.resize(n + 5);
    for (int i = 0; i < n + 5; i++) {
        reach[i].reset();
        invreach[i].reset();
    }
    G.clear();
    G.resize(n + 5, vector<int>());
    string ans;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        indeg[v]++;
    }
    bfs();
    for (int i = 0; i < k; i++) {
        int u, v; cin >> u >> v;
        if (reach[v][u]) {
            add_edge(v, u);
            ans.push_back('1');
        }
        else {
            add_edge(u, v);
            ans.push_back('0');
        }
    }
    return ans;
}
int32_t main()
{
    usecppio
    int T, test_case;
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        cout << "Case #" << test_case+1 << endl;
        cout << solve() << endl;
    }
    return 0;
}