#include <bits/stdc++.h>
using namespace std;

int arr[202020];
int occ[202020];
int maxocc,maxoccel;
int n,flag;
int main()
{
    scanf("%d",&n);
    for (int i = 1; i<=n; i++)
    {
        int x;
        scanf("%d",&x);
        arr[i] = x;
        occ[x]++;
        if (occ[x] > maxocc)
        {
            maxocc = occ[x];
            maxoccel = x;
        }
    }
    int target = maxoccel;
    for (int i = 1; i<=n; i++)
    {
        if (arr[i] == target)
        {
            flag = i;
            break;
        }
    }
    printf("%d\n",n-maxocc);
    if(n-maxocc==0)
        return 0;
    for (int i = flag-1; i >= 1; i--)
        printf("%d %d %d\n",(arr[i]>target)?2:1,i,i+1);
    int newflag = 0;
    for (int i = flag+1; i<=n; i++)
    {
        if (arr[i] == target)
            continue;
        else
            printf("%d %d %d\n",(arr[i]>target)?2:1,i,i-1);
    }


}
