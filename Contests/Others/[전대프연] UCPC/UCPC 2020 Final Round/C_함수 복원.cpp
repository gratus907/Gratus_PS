#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int n;
int reach[505][505];
vector<int> cycle[505];

int main() {
    scanf("%d", &n);
    for ( int i = 0 ; i < n ; ++i ) {
        for ( int j = 0 ; j < n ; ++j ) {
            scanf("%d", &reach[i][j]);
        }
    }

    int new_cycle_index = 0;
    int cycle_ptr[505];     //이 인덱스의 
    memset(cycle_ptr, -1, sizeof(cycle_ptr));

    for ( int i = 0 ; i < n ; ++i ) {
        for ( int j = 0 ; j < n ; ++j ) {
            if ( i == j ) continue;
            if ( reach[i][j] == 1 && reach[j][i] == 1 ) {
                //이번엔 이거다
                if ( cycle_ptr[i] == -1 && cycle_ptr[j] == -1) {    //둘다 처음 보는거
                    cycle[new_cycle_index].push_back(i);
                    cycle[new_cycle_index].push_back(j);
                    
                    cycle_ptr[i] = new_cycle_index;
                    cycle_ptr[j] = new_cycle_index;

                    ++new_cycle_index;
                } else if ( cycle_ptr[i] == -1 ) {
                    int index = cycle_ptr[j];
                    cycle[index].push_back(i);
                    cycle_ptr[i] = index;

                } else if ( cycle_ptr[j] == -1 ) {
                    int index = cycle_ptr[i];
                    cycle[index].push_back(j);
                    cycle_ptr[j] = index;
                }
            }
        }
    }
    long long ret = 1;

    int cycle_count = new_cycle_index;
    for ( int i = 0 ; i < cycle_count ; ++i ) {
        bool in_cycle[505];
        memset(in_cycle, 0, sizeof(in_cycle));
        for ( int p : cycle[i] ) {
            in_cycle[p] = true;
        }

        int end = cycle[i].front();
        vector<int> going_list;
        for ( int start = 0 ; start < n ; ++start ) {
            if ( reach[start][end] == 1 && !in_cycle[start] ) {
                going_list.push_back(start);
            }
        }

        bool valid[505];
        memset(valid, 0, sizeof(valid));

        for ( int p : going_list ) {
            //printf("%d ", p);
            valid[p] = true;
        }

        for ( int p : going_list ) {
            for ( int q : going_list ) {
                if ( p == q ) continue;
                if ( reach[p][q] == 1 ) {
                    valid[p] = false;
                }
            }
        }

        ll count = 0;
        for ( int p : going_list ) {
            if ( valid[p] ) ++count;
        }

        int cycle_size = cycle[i].size();
        while(count--) {
            ret = (ret * cycle_size) % mod;
        }

        int fac = cycle_size - 1;
        while(fac) {
            ret = (ret * fac) % mod;
            --fac;
        }
    }

    printf("%lld", ret);
}