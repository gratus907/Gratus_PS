#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    scanf("%d", &n);
    int temp;
    int first = 0, second = 0;
    for ( int i = 0 ; i < n ; ++i ) {
        scanf("%d", &temp);
        first += temp;
    }
    for ( int i = 0 ; i < n ; ++i ) {
        scanf("%d", &temp);
        second += temp;
    }
    if (first >= second ) printf("Yes");
    else printf("No");
}
