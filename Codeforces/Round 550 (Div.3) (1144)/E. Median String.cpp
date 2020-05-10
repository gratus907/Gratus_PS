#include <bits/stdc++.h>
using namespace std;

char s[202020];
char t[202020];
int med[202020];

int main()
{
    int k;
    scanf("%d",&k);
    scanf("%s %s",s+1,t+1);
    for (int i = 1; i<=k; i++)
        med[i] = (s[i]-'a')+(t[i]-'a');
    for (int i = k; i>=1; i--)
    {
        if(med[i]>=26)
        {
            med[i]-=26;
            med[i-1]++;
        }
    }
    if (med[0]==1)
    {
        med[0] = 0;
        med[1] += 26;
    }
    for (int i = 1; i<=k; i++)
    {
        if (med[i]%2)
        {
            med[i]--;
            med[i+1]+=26;
        }
        med[i] /=2;
        printf("%c",med[i]+'a');
    }
}
