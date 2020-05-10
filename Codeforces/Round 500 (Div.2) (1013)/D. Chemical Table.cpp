#include<bits/stdc++.h>
using namespace std;

vector<int> road[400005];
bool done[400005];

void dfs(int s) {
    int size = road[s].size();
    for ( int i = 0 ; i < size ; ++i ) {
        int temp = road[s][i];
        if ( !done[temp] ) {
            done[temp] = true;
            dfs(temp);
        }
    }
}

int main() {
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    while(p--) {
        int a, b;
        scanf("%d %d", &a, &b);
        road[a].push_back(n + b);
        road[n+b].push_back(a);
    }
    int soo = 0;
    for ( int i = 1 ; i <= n+m ; ++i ) {
        if ( !done[i] ) {
            ++soo;
            done[i] = true;
            dfs(i);
        }
    }
    printf("%d", soo - 1);
}
