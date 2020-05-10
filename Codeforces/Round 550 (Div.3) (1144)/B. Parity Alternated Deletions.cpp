#include <bits/stdc++.h>
using namespace std;
int arr[2100];
int odd[2100];
int even[2100];
int n;
int oddpt, evenpt;
int main()
{
    scanf("%d",&n);
    for (int i = 0; i<n; i++)
    {
        scanf("%d",arr+i);
        if (arr[i]%2)
        {
            odd[oddpt] = arr[i];
            oddpt++;
        }
        else
        {
            even[evenpt] = arr[i];
            evenpt++;
        }
    }
    if (abs(oddpt-evenpt)<=1)
    {
        printf("0");
        return 0;
    }
    else
    {
        if (oddpt > evenpt)
        {
            int total = 0;
            sort(odd, odd+oddpt);
            for (int i = 0; i<oddpt-evenpt-1; i++)
                total += odd[i];
            printf("%d",total);
        }
        else
        {
            int total = 0;
            sort(even, even+evenpt);
            for (int i = 0; i<evenpt-oddpt-1; i++)
                total += even[i];
            printf("%d",total);
        }
    }
}
