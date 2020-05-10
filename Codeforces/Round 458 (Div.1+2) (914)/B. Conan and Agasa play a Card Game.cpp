#include <bits/stdc++.h>
#define ll long long
using namespace std;

int num[100005];

int main(){
    int n;
    scanf("%d", &n);
    int temp;
    while(n--) {
        scanf("%d", &temp);
        ++num[temp];
    }
    for ( int i = 100000 ; i >= 1 ; --i ) {
        if ( num[i] % 2 == 1 ) {
            printf("Conan");
            return 0;
        }
    }
    printf("Agasa");
}
