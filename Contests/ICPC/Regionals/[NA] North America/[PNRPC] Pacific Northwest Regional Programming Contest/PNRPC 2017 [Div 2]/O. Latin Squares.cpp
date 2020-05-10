#include<bits/stdc++.h>
using namespace std;

int main(){
    bool islatin = true;

    int n;
    scanf("%d", &n);
    int number[n+5][n+5];
    memset(number, 0, sizeof(number));
    for ( int i = 0 ; i < n ; ++i ) {
        char poo[40];
        scanf("\n%s", poo);
        for ( int j = 0 ; j < n ; ++j ) {
            char temp = poo[j];
            if ( temp >= '0' && temp <= '9') number[i][j] = temp - '0';
            else number[i][j] = temp - 'A' + 10;
            if ( number[i][j] >= n ) islatin = false;
        }
    }

    for ( int i = 0 ; i < n ; ++i ) {
        int did[n];
        memset(did, 0, sizeof(did));
        for ( int j = 0 ; j < n ; ++j ) {
            ++did[ number[i][j] ];
        }
        for ( int j = 0 ; j < n ; ++j ) {
            if ( did[j] != 1 ) islatin = false;
        }
    }

    for ( int j = 0 ; j < n ; ++j ) {
        int did[n];
        memset(did, 0, sizeof(did));
        for ( int i = 0 ; i < n ; ++i ) {
            ++did[ number[i][j] ];
        }
        for ( int i = 0 ; i < n ; ++i ) {
            if ( did[i] != 1 ) islatin = false;
        }
    }


    bool isreduced = true;
    for ( int i = 0 ; i < n ; ++i ) {
        if ( number[i][0] != i ) isreduced = false;
    }
    for ( int j = 0 ; j < n ; ++j ) {
        if ( number[0][j] != j ) isreduced = false;
    }

    if ( islatin ) {
        if ( isreduced ) {
            printf("Reduced");
        } else {
            printf("Not Reduced");
        }
    } else {
        printf("No");
    }

}
