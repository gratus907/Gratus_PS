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
#define int likely
#define MOD 1000000007
double twosolve();
inline double val_ypp(double &y, double &yp, double &x)
{
    double u = 2*x*yp-2*y;
    double uu = (x*x+y*y);
    uu *= (uu+1);
    double lu = (1+yp*yp);
    return u*lu/uu;
}
inline double recieve_dose(double &xpos, double &ypos, double &interlen)
{
    double dd = 1 + 1/(xpos*xpos+ypos*ypos);
    return dd*interlen;
}
pair <double, double> trial(double init_yp, double start_y)
{
    double yp = init_yp;
    double y = start_y;
    double x = -10;
    double xp = 0.00001;
    double dose = 0;
    while(x<10)
    {
        double ilen = sqrt(1+yp*yp)*xp;
        dose += recieve_dose(x,y,ilen);
        x += xp;
        double ypp = val_ypp(y, yp, x);
        y += yp*xp;
        yp += ypp*xp;
    }
    return {y, dose};
}

double solve()
{
    double a, b, c;
    int n;
    scanf("%lld",&n);
    if (n == 2)
    {
        return twosolve();
    }
    scanf("%lf %lf %lf",&a,&b,&c);
    a -= c;
    b -= c;
    double up_ans, down_ans;

    double lo = -100;
    double hi = -a/10.0;
    while(abs(lo-hi)>eps)
    {
        double mid = (lo+hi)/2;
        auto guess = trial(mid,a);
        double endpos = guess.first;

        if (endpos<b)
            lo = mid;
        else hi = mid;
    }
    down_ans = trial(lo,a).second;

    double lo2 = -a/10;
    double hi2 = 100;
    while(abs(lo2-hi2)>eps)
    {
        double mid = (lo2+hi2)/2;
        auto guess = trial(mid,a);
        double endpos = guess.first;
        if (endpos<b)
            lo2 = mid;
        else hi2 = mid;
    }
    up_ans = trial(lo2,a).second;

    return min(up_ans, down_ans);
}

int32_t main()
{
    int TC;
    cin >> TC;
    for (int tt = 1; tt<=TC; tt++)
    {
        printf("Case #%lld: ",tt);
        printf("%.10lf\n",solve());
    }
}




inline double val_ypp_2(double &y, double &yp, double &x, double &c0, double &c1)
{
    double lu = (1+yp*yp);
    double tmp_1 = (x*x+(y-c0)*(y-c0));
    double tmp_2 = (x*x+(y-c1)*(y-c1));
    double up1 = -2*(y-c0)/(tmp_1*tmp_1);
    double up2 = -2*(y-c1)/(tmp_2*tmp_2);
    double down1 = 1/tmp_1;
    double down2 = 1/tmp_2;

    return lu*(up1+up2)/(down1+down2+1);
}
inline double recieve_dose_2(double &xpos, double &ypos, double &interlen, double &c0, double &c1)
{
    double t = abs(ypos-c0), t2 = abs(ypos-c1);
    return (1/(xpos*xpos+t*t)+1/(xpos*xpos+t2*t2)+1)*interlen;
}
pair <double, double> trial_2(double init_yp, double start_y, double &c0, double &c1)
{
    double yp = init_yp;
    double y = start_y;
    double x = -10;
    double xp = 0.00001;
    double dose = 0;
    int cnt = 0;
    while(x<10)
    {
        cnt++;
        double ilen = sqrt(1+yp*yp)*xp;
        dose += recieve_dose_2(x,y,ilen,c0,c1);
        x += xp;
        double ypp = val_ypp_2(y, yp, x,c0,c1);
        y += yp*xp;
        yp += ypp*xp;
    }
    return {y, dose};
}


double twosolve()
{
    double a, b, c0, c1;
    scanf("%lf %lf %lf %lf",&a,&b,&c0,&c1);
    if (c0 > c1) swap(c0, c1);
    double up_ans, mid_ans, down_ans;

    double lo = -100;
    double hi = -(c0-a)/10.0;

    while(abs(lo-hi)>eps)
    {
        double mid = (lo+hi)/2;
        auto guess = trial_2(mid,a,c0,c1);
        double endpos = guess.first;

        if (abs(endpos-b)<=eps)
            break;
        if (endpos<b)
            lo = mid;
        else hi = mid;
    }
    double mid1 = (lo+hi)/2;
    down_ans = trial_2(mid1,a,c0,c1).second;

    double lo2 = -(c1-a)/10.0;
    double hi2 = 100;
    while(abs(lo2-hi2)>eps)
    {
        double mid = (lo2+hi2)/2;
        auto guess = trial_2(mid,a,c0,c1);
        double endpos = guess.first;
        if (abs(endpos-b)<=eps)
            break;
        if (endpos<b)
            lo2 = mid;
        else hi2 = mid;
    }
    double mid2 = (lo2+hi2)/2;
    up_ans = trial_2(mid2,a,c0,c1).second;

    double lo3 = -(c0-a)/10.0;
    double hi3 = -(c1-a)/10.0;
    while(abs(lo3-hi3)>eps)
    {
        double mid = (lo3+hi3)/2;
        auto guess = trial_2(mid,a,c0,c1);
        double endpos = guess.first;
        if (abs(endpos-b)<=eps)
            break;
        if (endpos<b)
            lo3 = mid;
        else hi3 = mid;
    }
    double mid3 = (lo3+hi3)/2;
    mid_ans = trial_2(mid3,a,c0,c1).second;
    return min(min(mid_ans,up_ans), down_ans);
}