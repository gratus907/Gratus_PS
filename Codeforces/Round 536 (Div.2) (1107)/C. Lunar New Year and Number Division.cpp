#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int numbers[304000];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i<n; i++)
        scanf("%d",&numbers[i]);
    sort(numbers,numbers+n);
    lli ans = 0;
    for (int i = 0; i<n/2; i++)
        ans += ((numbers[i]+numbers[n-i-1])*(numbers[i]+numbers[n-i-1]));
    printf("%lld",ans);
}
