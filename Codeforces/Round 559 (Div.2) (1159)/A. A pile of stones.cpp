#include <bits/stdc++.h>
#define MAX(A,B) ((A)>(B)?(A):(B))
using namespace std;


int n;
int st = 0;
char str[120];
int main()
{
    scanf("%d",&n);
    scanf("%s",str);
    for (int i = 0; i<n; i++)
    {
        if (str[i] == '-')
            st = MAX(0,st-1);
        else
            st++;
    }
    printf("%d",st);
}
