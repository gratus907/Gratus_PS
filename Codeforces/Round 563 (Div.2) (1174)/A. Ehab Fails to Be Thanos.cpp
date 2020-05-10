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

int arr[2010];
int main()
{
    int n;
    ll sum = 0, newsum = 0;
    scanf("%d",&n);
    for (int i = 0; i<n*2; i++)
    {
        scanf("%d",arr+i);
        sum += arr[i];
    }
    sort(arr,arr+n*2);
    for (int i=0; i<n; i++)
    {
        newsum+=arr[i];
    }
    if (newsum*2!=sum)
    {
        for (int i = 0; i<n*2; i++)
        {
            printf("%d ",arr[i]);
        }
        return 0;
    }
    else
    {
        printf("-1");
        return 0;
    }
}
