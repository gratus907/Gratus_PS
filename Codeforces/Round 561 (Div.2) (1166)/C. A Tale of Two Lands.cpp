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

string vowel = "aeiou";

vector <int> positions;

ll lid(int size, int val)
{
    int l = 0, h = size - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (positions[mid] >= val)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}
ll uid(int size, int val)
{
    int l = 0, h = size - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (positions[mid] <= val)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return h;
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        positions.push_back(abs(x));
    }
    sort(all(positions));
    ll ans = 0;
    for (int i = 0; i<n; i++)
    {
        ll low = lid(positions.size(),abs(positions[i]+1)/2);
        ll high = uid(positions.size(),abs(positions[i])*2);
        //printf("%lld %lld\n",high,low);
        ans+=(high-low);
    }
    printf("%lld",ans/2);

}
