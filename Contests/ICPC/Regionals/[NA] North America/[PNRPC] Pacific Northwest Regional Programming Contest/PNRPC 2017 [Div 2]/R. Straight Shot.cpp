#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    double x;
    double v;
    scanf("%d %lf %lf", &n, &x, &v);

    double up = 0, down = 0;

    for ( int i = 0 ; i < n ; ++i ) {
        double left, right, speed;
        scanf("%lf %lf %lf", &left, &right, &speed);
        up += (right-left) * speed;
        down += (right - left);
    }
    if ( down == 0 ) {
        printf("%lf", x / v);
    } else {
        double vy = abs(up/x);
        if ( vy >= v ) {
            printf("Too hard");
        } else {
            double upmost = 2 * x / v;
            double vx = sqrt( pow(v,2) - pow(vy,2) );
            if ( vx > upmost ) {
                printf("Too hard");
            } else {
                printf("%.3lf", x / vx);
            }
        }

    }
}
