#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector <double> v;
int n, k;
int min_gap = 1e9;
double ang;

void solve(int start)
{
    int M = 0, m = 1e9;
    double st = v[start]-(1e-6);
    for (int i = 0; i<k; i++)
    {
        double MANG = st+(i+1)*ang; 
        double mang = st+i*ang;
        int t = upper_bound(all(v),MANG)-lower_bound(all(v),mang);
        //printf("[%.5lf, %.5lf) : %lld\n",mang, MANG,t);
        M = max(M, t); m = min(m, t);
    }
    //printf("Maximum %lld, mininum %lld\n",M, m);
    min_gap = min(min_gap,M-m);
}

int32_t main()
{
    cin >> n >> k;  
    ang = 360.0/k*1.0;
    for (int i = 0; i<n; i++)
    {
        double x; cin >> x; 
        v.push_back(x);
    }
    sort(all(v));
    for (int i = 0; i<n; i++) v.push_back(v[i]+360.0);
    for (int i = 0; i<n; i++)
        solve(i);
    cout << min_gap << '\n';
}