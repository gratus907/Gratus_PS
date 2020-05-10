#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
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
#define all(x) x.begin(), x.end()
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int arr[202020];
int main()
{
    int n, z;
    scanf("%d %d",&n,&z);
    for (int i = 0; i<n; i++)
        scanf("%d",arr+i);
    sort(arr,arr+n);
    int l = 0;
    int r = n/2 + 1;
    while(r-1>l)
    {
        int mid = (l+r)/2;
        bool flag = 1;
        for (int i = 0; i<mid; i++)
        {
            if (arr[n-mid+i]-arr[i] < z)
            {
                flag = false;
                break;
            }
        }
        if(flag)
            l = mid;
        else
            r = mid;
    }
    printf("%d",l);
}
