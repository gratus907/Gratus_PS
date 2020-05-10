#include<bits/stdc++.h>
using namespace std;

int n,x;
int arr[101010];
int occ[101010];
int andocc[101010];
int main()
{
    scanf("%d %d",&n,&x);
    for (int i = 0; i<n; i++)
    {
        int tmp;
        scanf("%d",&tmp);
        arr[i] = tmp;
        occ[tmp]++;
    }
    for (int i = 0; i<101010; i++)
    {
        if (occ[i]>=2)
        {
            printf("0");
            return 0;
        }
    }
    for (int i = 0; i<n; i++)
    {
        //printf("%d and %d = %d\n",arr[i],x,arr[i]&x);
        if ((arr[i] & x)!=arr[i])
        {
            if (occ[arr[i]&x])
            {
                printf("1");
                return 0;
            }
        }
    }
    for (int i = 0; i<n; i++)
    {
        andocc[arr[i]&x]++;
    }
    for (int i = 0; i<101010; i++)
    {
        if (andocc[i]>=2)
        {
            printf("2");
            return 0;
        }
    }
    printf("-1");
    return 0;
}
