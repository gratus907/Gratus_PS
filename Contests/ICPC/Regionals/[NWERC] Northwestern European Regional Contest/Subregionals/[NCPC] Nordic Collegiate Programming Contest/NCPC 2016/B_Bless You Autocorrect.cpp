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
const int mod = 1000000007;

int node_cnt = 1;
vector<int> G[1010101];
struct node {
    int idx, aut;
    node *next[26];
    node () {
        idx = node_cnt;
        aut = 0;
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
} *trie_head;

node* np[1010101];
void trie_insert(string s) {
    node *cur = trie_head;
    vector <int> path_nodes;
    for (char _c : s) {
        int c = _c - 'a';
        if (cur->next[c] == NULL) {
            node *x = new node();
            np[node_cnt++] = x;
            cur->next[c] = x;
        }
        cur = cur->next[c];
        path_nodes.push_back(cur->idx);
    }
    int path_end = path_nodes.back();
    for (int i = 1; i < path_nodes.size(); i++) {
        G[path_nodes[i]].push_back(path_nodes[i-1]);
    }
    for (int i : path_nodes) {
        if (np[i]->aut == 0) {
            np[i]->aut = path_end;
        }
    }
}

int dep[1010101];
int gain(string s) {
    node *cur = trie_head;
    int got = 0;
    for (char _c : s) {
        int c = _c - 'a';
        if (cur->next[c] == NULL) {
            //printf("CUR idx = %lld (first %lld letters), dep = %lld\n",cur->idx,got,dep[cur->idx]);
            return got-dep[cur->idx];
        }
        cur = cur->next[c];
        got++;
    }
    //printf("CUR idx = %lld (first %lld letters), dep = %lld\n",cur->idx,got,dep[cur->idx]);
    return got-dep[cur->idx];
}
void build_graph() {
    for (int i = 0; i < node_cnt; i++) {
        for (int j = 0; j < 26; j++) {
            if (np[i]->next[j] != NULL) {
                G[np[i]->idx].push_back(np[i]->next[j]->idx);
            }
        }
        if (np[i]->aut != 0) {
            G[np[i]->idx].push_back(np[i]->aut);
        }
    }
    /*for (int i = 0; i < node_cnt; i++) {
        printf("%lld : ",i);
        for (int c : G[i]) {
            printf("%lld ",c);
        }
        printf("\n");
    }*/
}
int32_t main() {
    usecppio
    trie_head = new node(); trie_head->idx = 0;
    np[0] = trie_head;
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        trie_insert(s);
    }
    build_graph();
    memset(dep, 0x7f, sizeof(dep));
    dep[0] = 0;
    queue<int> q; q.push(0);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for (int c : G[x]) {
            if (dep[c] > 1e9) {
                q.push(c);
                dep[c] = dep[x] + 1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        cout << s.length() - gain(s) << '\n';
    }
}