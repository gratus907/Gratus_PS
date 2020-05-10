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
#define mod 1000000007LL
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int kids[103];
vector<int> v;
vector<int> v2;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i<n; i++)
        scanf("%d",kids+i);
    sort(kids,kids+n);
    for (int i = 0; i<n; i+=2)
        v.PB(kids[i]);
    for (int i = 1; i<n; i+=2)
        v2.PB(kids[i]);
    for (int i = 0; i<v.size(); i++)
        printf("%d ",v[i]);
    for (int i = v2.size()-1; i>=0; i--)
        printf("%d ",v2[i]);

}
