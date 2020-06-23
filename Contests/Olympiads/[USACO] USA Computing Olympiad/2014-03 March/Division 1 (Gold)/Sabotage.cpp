#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define eps 1e-6
vector<double> cur;
double kadane(vector <double> &arr)
{
	int nn = arr.size();
	double lm = arr[1], gm = arr[1];
	for (int i = 1; i<nn-1; i++)
	{
		lm = max(arr[i], lm+arr[i]);
		gm = max(gm, lm);
	}
	return gm;
}
int32_t main()
{
    usecppio
    int n; cin >> n;
    for (int i = 0; i<n; i++)
    {
        double x; cin >> x;
        cur.push_back(x);
    }
    double lo = 1.0, hi = 1e4;
    while(abs(lo-hi)>1e-5)
    {
        double mid = (lo+hi)/2;
        vector <double> newv = cur;
        double tot = 0.0;
        for (auto &it:newv)
        {
            it -= mid;
            tot += it;
        }
        double msum = kadane(newv);
        //printf("%lf Try : tot %lf, Msum %lf\n",mid,tot,msum);
        if (msum > tot+eps)
            hi = mid;
        else lo = mid;
    }
    printf("%.3lf\n",lo);
}
