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

int arr[3];
int main()
{
    int d;
    cin >> arr[0] >> arr[1] >> arr[2] >> d;
    sort(arr,arr+3);
    int d1 = arr[1]-arr[0];
    int d2 = arr[2]-arr[1];
    int a1 = (d-min(d,d1))+(d-min(d,d2));
    int a2 = INT_MAX;
    if (d1+d2>=2*d)
        a2 = min((abs(arr[1]-arr[0]-d)),(abs(arr[1]-arr[2]+d)));
    cout << min(a1,a2);
}
