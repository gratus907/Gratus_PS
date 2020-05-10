#include <bits/stdc++.h>
using namespace std;

int arr[120];
int main()
{
    int n;
    scanf("%d",&n);
    int ans = 0;
    for (int i = 1; i<=n; i++)
    {
        scanf("%d",arr+i);
        if (i>1)
        {
            if (arr[i-1] == 2 && arr[i] == 3)
                ans += 100000;
            if (arr[i-1] == 3 && arr[i] == 2)
                ans += 100000;
            if (arr[i-1] == 1 && arr[i] == 3)
                ans += 4;
            if (arr[i-1] == 3 && arr[i] == 1)
                ans += 4;
            if (arr[i-1] == 2 && arr[i] == 1)
                ans += 3;
            if (arr[i-1] == 1 && arr[i] == 2)
                ans += 3;
            if (i>2)
            {
                if (arr[i] == 2 && arr[i-1] == 1 && arr[i-2] == 3)
                    ans --;
            }
        }
    }
    printf("%s",ans > 10000? "Infinite":"Finite");
    if (ans<10000)
        printf("\n%d",ans);
}
