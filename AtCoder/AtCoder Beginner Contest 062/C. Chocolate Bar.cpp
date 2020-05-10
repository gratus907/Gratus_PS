#include <bits/stdc++.h>
#define ll long long
using namespace std;

inline ll max_3(ll p, ll q, ll r)
{
    return max(max(p,q),r);
}
inline ll min_3(ll p, ll q, ll r)
{
    return min(min(p,q),r);
}
ll h, w;
ll case1()
{
    ll a = h*(w/3);
    ll b = h*((w-w/3)/2);
    ll c = h*w - a - b;
    return max_3(a,b,c)-min_3(a,b,c);
}
ll case2()
{
    ll a = w*(h/3);
    ll b = w*((h-h/3)/2);
    ll c = h*w - a - b;
    return max_3(a,b,c)-min_3(a,b,c);
}

ll case3()
{
    ll a, b, c;
    ll mindiff = LLONG_MAX;
    for (int i = 1; i<h; i++)
    {
        a = i*w;
        b = (h-i)*(w/2);
        c = (h-i)*w - b;
        mindiff = min(mindiff,max_3(a,b,c)-min_3(a,b,c));
    }
    return mindiff;
}

ll case4()
{
    ll a, b, c;
    ll mindiff = LLONG_MAX;
    for (int i = 1; i<w; i++)
    {
        a = i*h;
        b = (w-i)*(h/2);
        c = (w-i)*h - b;
        mindiff = min(mindiff,max_3(a,b,c)-min_3(a,b,c));
    }
    return mindiff;
}


int main()
{
    cin >> h >> w;
    cout << min(min(case1(),case2()),min(case3(),case4()));
}
