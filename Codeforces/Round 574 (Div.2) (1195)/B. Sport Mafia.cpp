#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int main()
{
    ll n, k;
    cin >> n >> k;
    for (ll i = 0; i<=1010100; i++)
    {
        ll p = (i*(i+1))/2;
        if (p<k)
            continue;
        if (p-(n-i)==k)
        {
            cout << n-i;
            return 0;
        }
    }
    return 0;
}
