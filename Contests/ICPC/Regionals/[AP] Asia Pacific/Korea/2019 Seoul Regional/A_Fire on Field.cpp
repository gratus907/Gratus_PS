#include <bits/stdc++.h>
using namespace std;

int A[1050];
int main()
{
    int n;
    scanf("%d",&n);
    A[0] = 1;
    A[1] = 1;
    for (int i = 2; i<=1010; i++)
    {
        for (int k = 1; k<= 500; k++)
        {
            bool flag = true;
            for (int j = 1; j*2<=i; j++)
            {
                if (k-A[i-j]==A[i-j]-A[i-2*j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                A[i] = k;
                break;
            }
        }
    }
    printf("%d\n",A[n]);
}