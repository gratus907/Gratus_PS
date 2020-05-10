#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define ll long long
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define gcd(A,B) (__gcd(A,B))
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
#define mod 1000000007LL
#define all(x) x.begin(), x.end()
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

vector <pii> pos;
vector <pii> z;
vector <pii> neg;
vector <pii> alls;
int sign = 1;
vector <int> orig;
vector <pii> tmp;
int main()
{
    usecppio
    int n;
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        if (x==0)
            z.push_back({0,i});
        else if (x>0)
            pos.push_back({x,i});
        else if (x<0)
        {
            neg.push_back({x,i});
            sign *= -1;
        }
        alls.push_back({x,i});
        orig.push_back(x);
    }
    sort(all(alls),greater<pii>());
    for (int i = 0; i<n; i++)
    {
        if (alls[i].first>=0)
        {
            sign *= (-1);
            alls[i].first = (-alls[i].first-1);
        }
    }
    sort(all(alls));
    if (sign==-1)
    {
        alls[0].first = -alls[0].first-1;
    }

    for (auto it:alls)
    {
        tmp.push_back({it.second,it.first});
    }

    sort(all(tmp));
    for (auto it:tmp)
    {
        cout << it.second << ' ';
    }
    cout << '\n';
}
