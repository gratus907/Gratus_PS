#include <bits/stdc++.h>
#define ll long long
#define MAX(A,B) ((A)>(B)?(A):(B))
using namespace std;
 
int book[10200];
int main()
{
    int n;
    int pt = 1,day = 0;
    scanf("%d",&n);
    for (int i = 1 ; i<=n; i++)
        scanf("%d",book+i);
    while (pt <= n)
    {
        int target = 0;
        while(1)
        {
            target = MAX(target,book[pt]);
            pt++;
            if (target < pt)
                break;
        }
        day++;
    }
    printf("%d",day);
}
