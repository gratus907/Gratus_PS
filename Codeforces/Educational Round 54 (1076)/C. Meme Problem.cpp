#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) A>B?A:B
#define MIN(A,B) A<B?A:B
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int main()
{
    int n;
    cin>>n;
    for (int i = 0; i<n; i++)
    {
        long double a,b,d,tmp;
        lli k;
        scanf("%lld",&k);
        d = (long double)k;
        if (0<k && k<4)
        {
            cout << 'N' << endl;
            continue;
        }
        tmp = d*d-4*d;
        tmp = sqrt(tmp);
        a = (0.5)*(tmp+d);
        b = d-a;
        cout.precision(12);
        cout << 'Y' << ' '<< a <<' '<< b <<endl;
    }
}
