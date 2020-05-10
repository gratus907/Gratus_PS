#include <bits/stdc++.h>
#define ll long long
using namespace std;

int arr[1020];
int main()
{
    int n;
    int ans = INT_MIN;
    scanf("%d",&n);
    for (int i = 0; i<n; i++)
    {
        scanf("%d",arr+i);
        bool flag = true;
        for (int j = 0; j<=1000; j++)
        {
            if (j*j==arr[i])
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            ans = arr[i]>ans? arr[i]:ans;
        }
    }
    printf("%d",ans);

}
