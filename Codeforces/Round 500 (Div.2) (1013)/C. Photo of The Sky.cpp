#include<bits/stdc++.h>
using namespace std;

long long ans1 = 0;
long long ans2 = 0;
long long arr[202020];
int main()
{
    long long n;
    scanf("%lld",&n);
    for (int i = 0; i<2*n; i++)
    {
        scanf("%lld",arr+i);
    }
    sort(arr,arr+2*n);
    long long temp=1000000001;
    for(int i=1; i<n; i++)
    {
        temp=min(temp,arr[i+n-1]-arr[i]);
    }
    ans1 = (arr[2*n-1]-arr[n])*(arr[n-1]-arr[0]);
    ans2 = (arr[2*n-1]-arr[0])*temp;
    printf("%lld",min(ans1,ans2));
}
