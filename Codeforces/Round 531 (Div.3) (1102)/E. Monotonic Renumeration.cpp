#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) (A)>(B)?(A):(B)
#define MIN(A,B) (A)<(B)?(A):(B)
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
#define mod 998244353LL
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define x first
#define y second
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

lli modulo_pow(lli a, lli b, lli p)
{
    lli x = 1, y = a;
    if (b == 0)
        return 1;
    lli r;
    r = modulo_pow (a, b / 2, p);
    r = (r * r) % p;
    if (b % 2 == 1)
        r = (r*a) % p;
    return (r % p);
}

map <int,pii> m;
vector <pair<pii,int> > vec;
int branch;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i<n; i++)
    {
        int a;
        scanf("%d",&a);
        if (m.count(a))
        {
            int foo = m[a].first;
            m[a] = pii(foo,i);
        }
        else
            m[a] = pii(i,i);
    }
    for (const auto &it:m)
        vec.PB(MP(it.second,it.first));
    sort(vec.begin(),vec.end());
    int len = vec.size();
    int crit = (vec[0].first.second)+1;
    for (int i = 1; i<len; i++)
    {
        if (vec[i].first.first < crit)
        {
            crit = MAX(crit, (vec[i].first.second)+1);
            continue;
        }
        else
        {
            branch++;
            crit = (vec[i].first.second)+1;
        }
    }
    printf("%lld",modulo_pow(2,branch,mod));
}
