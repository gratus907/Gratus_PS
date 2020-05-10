#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) A>B?A:B
#define MIN(A,B) A<B?A:B
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int arr[120];
int main()
{
    int n;
    int p = 0;
    scanf("%d",&n);
    for (int i = 0; i<n; i++)
        scanf("%d",arr+i);
    sort(arr,arr+n);
    for (int i = 0; i<n; i+=2)
        p += arr[i+1]-arr[i];
    printf("%d",p);
}
