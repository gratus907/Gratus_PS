#include <bits/stdc++.h>
#define ll long long
#define MAX(A,B) A>B?A:B
#define MIN(A,B) A>B?B:A
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/__gcd(A,B)*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int a[120];
int counter[120];
vector <pii> v;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i<n; i++)
    {
        scanf("%d",a+i);
        counter[a[i]]++;
    }
    sort(a,a+n);
    for (int i = 1; i<=100; i++)
    {
        if (counter[i])
            v.PB(MP(i, counter[i]));
    }
    if (v.size()>3)
    {
        printf("-1");
    }
    else if (v.size() == 1)
    {
        printf("0");
    }
    else if (v.size() == 2)
    {
        int d = v[1].first-v[0].first;
        d = (d%2)?d:d/2;
        printf("%d",d);
    }
    else if (v.size()==3)
    {
        int d1 = v[2].first-v[1].first;
        int d2 = v[1].first-v[0].first;
        if (d1!=d2)
            printf("-1");
        else
        {
            printf("%d",d1);
        }
    }

}
