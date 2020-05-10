#include <bits/stdc++.h>
#define ll long long
using namespace std;

int occ[27];
char str[100];
int main()
{
    scanf("%s",str);
    for (int i = 0; str[i]; i++)
    {
        occ[str[i]-'a']++;
        if (occ[str[i]-'a']>1)
        {
            printf("no");
            return 0;
        }
    }
    printf("yes");
}
