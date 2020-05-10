#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii> ans;
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d:\n",n);

    for(int i=2;i<=(n+1)/2;i++)
    {
        if(n%(2*i-1)==0||(n+i-1)%(2*i-1)==0)
            printf("%d,%d\n",i,i-1);

        if(n%i==0)
            printf("%d,%d\n",i,i);
    }
}
