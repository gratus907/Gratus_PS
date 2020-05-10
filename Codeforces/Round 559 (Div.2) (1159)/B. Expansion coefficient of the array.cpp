#include <bits/stdc++.h>
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
using namespace std;

int n;
int arr[302000];
int k = INT_MAX;
int main()
{
    scanf("%d",&n);
    for (int i = 1; i<=n; i++)
    {
        scanf("%d",arr+i);
        int maxd = MAX(i-1,n-i);
        int newk = arr[i]/maxd;
        k = MIN(k,newk);
    }
    printf("%d",k);
}
