#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int res = 0;
    for (int i = 2; i<n; i++)
        res += (i*(i+1));
    printf("%d",res);
}
