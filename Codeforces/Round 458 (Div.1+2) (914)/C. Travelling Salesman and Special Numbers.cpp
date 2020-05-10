#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007

int c[1005][1005];
int way[1005];

int change(int k) {
    int ret = 0;
    while(k) {
        if ( k % 2 == 1) ++ret;
        k >>= 1;
    }
    return ret;
}

int getc (int a, int b){
    if ( c[a][b] == -1 ) {
        if ( a < b ) c[a][b] = 0;
        else if ( b == 0 ) c[a][b] = 1;
        else if ( b == 1 ) c[a][b] = a;
        else if ( b > a/2 ) c[a][b] = getc(a, a-b);
        else c[a][b] = (int) ( ( (long long int)getc(a-1, b) + getc(a-1, b-1) ) % mod );
    }
    return c[a][b];
}

char n[1005];
int length;
int k;

int smaller(int left, int numOfOne) {

    if ( left < numOfOne) return 0;
    if ( numOfOne == 0) return 1;
    if ( left == 0 ) return 0;
    int ret = getc(left - 1, numOfOne);
    int p = left - 1;
    for ( ; p >= 1 && n[length - p] == '0' ; --p ) {

    }
    ret = ( (long long int) ret + smaller(p, numOfOne - 1) ) % mod;
    return ret;
}

int main(){
    for ( int i = 0 ; i < 1005 ; ++i ) {
        for ( int j = 0 ; j < 1005 ; ++j ) {
            c[i][j] = -1;
        }
    }

    for ( int i = 2 ; i <= 1000 ; ++i ) {
        way[i] = way[ change(i) ] + 1;
    }

    scanf("%s", n);
    length = strlen(n);
    scanf("%d", &k);

    long long int ret = 0;

    if ( k == 0 ) {
        printf("1");
        return 0;
    }

    for (int li = 1 ; li <= length ; ++li ) {
        if ( way[li] == k-1 ) {
            if ( li == 1 ) {
                ret = ( ret + smaller(length, li) - 1) % mod;
            } else {
                ret = ( ret + smaller(length, li) ) % mod;
            }

        }
    }
    printf("%d", (int)ret);
}
