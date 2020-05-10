#include<bits/stdc++.h>
using namespace std;

int main()
{
    double pos[7], sum = 0, maxi = 0;
    for(int i=0; i<6; i++)
    {
        scanf("%lf",pos+i);
        sum += ((double)(i+1)) * pos[i];
        maxi = max(maxi,pos[i]);
    }
    printf("%.3lf",abs((double)3.5-sum)/maxi);
}
