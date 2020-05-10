#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,long double> pid;

int arr[202020];
int occ[202020];
int inc[202020];
int decr[202020];
int incpt, decpt;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        arr[i] = x;
        occ[x]++;
        if (occ[x]>2)
        {
            printf("NO");
            return 0;
        }
    }

    printf("YES\n");
    sort(arr,arr+n);
    int ind = 0;
    while (ind < n)
    {
        if (occ[arr[ind]]==1)
        {
            decr[decpt] = arr[ind];
            decpt++;
            ind++;
        }
        else if (occ[arr[ind]]==2)
        {
            inc[incpt] = arr[ind];
            incpt++;
            decr[decpt] = arr[ind+1];
            decpt++;
            ind +=2;
        }
    }
    sort(inc,inc+incpt);
    sort(decr,decr+decpt,greater<int>());
    printf("%d\n",incpt);
    for (int i = 0; i<incpt; i++)
        printf("%d ",inc[i]);
    printf("\n");
    printf("%d\n",decpt);
    for (int i = 0; i<decpt; i++)
        printf("%d ",decr[i]);
    printf("\n");
}
