#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) A>B?A:B
#define MIN(A,B) A<B?A:B
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
#define modulo 998244353
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int arr[102000];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i = 0; i<n; i++)
        scanf("%d",arr+i);
    sort(arr,arr+n);
    int sum = arr[k-1]-arr[0];
    for (int i = k; i<n; i++)
        sum = MIN(sum, (arr[i]-arr[i-k+1]));
    printf("%d",sum);
}
