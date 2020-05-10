#include <bits/stdc++.h>
using namespace std;
char str[120];

bool is_cons(char str[], int s)
{
    int occ[27];
    memset(occ,0,sizeof(occ));
    for (int i = 0; i<s; i++)
        occ[str[i]-'a'+1]++;
    int chunk = 0;
    for (int i = 1; i<27; i++)
        if (occ[i]>0 && occ[i-1]==0)
            chunk++;
    if (chunk == 1)
        return true;
    else
        return false;
}

bool is_uniq(char str[], int s)
{
    int occ[27];
    memset(occ,0,sizeof(occ));
    for (int i = 0; i<s; i++)
        occ[str[i]-'a'+1]++;
    for (int i = 1; i<27; i++)
        if (occ[i]>1)
            return false;
    return true;
}
int main()
{
    int testcase;
    scanf("%d",&testcase);
    while(testcase--)
    {
        scanf("%s",str);
        if (is_cons(str, strlen(str))&& is_uniq(str,strlen(str)))
            printf("Yes\n");
        else
            printf("No\n");
    memset(str,0,sizeof(str));
    }

}
