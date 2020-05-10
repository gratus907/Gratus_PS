#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int sum = 0;
vector <int> v;
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int x;
        scanf("%d",&x);
        if (x%10)
            v.push_back(x);
        sum += x;
    }
    if (v.size()==0)
    {
        printf("0");
        return 0;
    }
    sort(v.begin(),v.end(),greater<int>());
    while (sum%10==0)
    {
        int u = v.back();
        sum -= u;
        v.pop_back();
    }
    printf("%d",sum);
}
