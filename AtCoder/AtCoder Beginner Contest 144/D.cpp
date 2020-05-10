#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const double rad = 180/3.14159265358979323846;
int main()
{
    double a, b, x;
    cin >> a >> b >> x;
    double v = x/a;
    if (2*v >= a*b)
    {
        double u = (2*a*b-2*v)/(a*a);
        cout << fixed << setprecision(10) << atan(u)*rad << '\n';
    }
    else 
    {
       cout << fixed << setprecision(10) << atan(b*b/(2*v))*rad << '\n';
    }
}