/******************************
This works for both D1 and D2 
******************************/

#include <bits/stdc++.h>
#define ll long long
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
#define modulo 998244353
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int n, m;
vector <int> coffee;

bool is_able(int k)
{
    ll total = 0;
    for (int i = 0; i<n; i++)
        total += MAX(0, coffee[i]-i/k);
    return total>=m;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i<n; i++)
    {
        int tmp;
        scanf("%d",&tmp);
        coffee.push_back(tmp);
    }
    sort(coffee.begin(), coffee.end(), greater<int>());
    int l = 1, r = n;
    if (!is_able(n))
    {
        printf("-1");
        return 0;
    }
    while(r>l+1)
    {
        int m = l+r;
        m /= 2;
        if (is_able(m))
            r = m;
        else
            l = m;

    }
    if (is_able(r))
    {
        if (is_able(l))
            printf("%d",l);
        else
            printf("%d",r);
    }
}
