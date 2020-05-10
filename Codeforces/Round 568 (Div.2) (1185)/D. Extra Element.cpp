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

int n;
vector <pii> v;
int pos;
bool check_1()
{
    int first = v[0].first;
    int last = v[n-1].first;
    if ((last-first)%(n-2))
        return 0;
    int d = (last-first)/(n-2);
    int tol = 0;
    int tmp = 0;
    for (int i = 0; i<n; i++)
    {
        if (v[i].first == first+(i-tol)*d)
        {
            continue;
        }
        else
        {
            tol++;
            tmp=v[i].second;
        }
        if (tol>1)
            return false;
    }
    if (tol==0)
        return 0;
    pos = tmp;
    //printf("1FOUND %d\n",pos);
    return true;
}

bool check_2()
{
    int first = v[0].first;
    int last = v[n-2].first;
    if ((last-first)%(n-2))
        return 0;
    int d = (last-first)/(n-2);
    for (int i = 0; i<n-1; i++)
    {
        if (v[i].first == first+(i)*d)
        {
            continue;
        }
        else
            return false;
    }
    pos = v[n-1].second;
    //printf("2FOUND %d\n",v[n-1].second);
    return true;
}

bool check_3()
{
    int first = v[1].first;
    int last = v[n-1].first;
    if ((last-first)%(n-2))
        return 0;
    int d = (last-first)/(n-2);
    for (int i = 1; i<n; i++)
    {
        if (v[i].first == first+(i-1)*d)
            continue;
        else
            return false;
    }
    pos = v[0].second;
    //printf("3FOUND %d\n",v[0].second);
    return true;
}

int main()
{
    scanf("%d",&n);
    for (int i = 1; i<=n; i++)
    {
        int x;
        scanf("%d",&x);
        v.push_back({x,i});
    }
    sort(all(v));
    if (n<=3)
    {
        printf("1");
        return 0;
    }
    if (check_1()||check_2()||check_3())
    {
        if (pos == 0)
            return -1;
        printf("%d",pos);
        return 0;
    }
    else
    {
        printf("-1");
        return 0;
    }
}
