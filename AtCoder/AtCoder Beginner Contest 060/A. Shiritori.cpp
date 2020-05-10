#include <bits/stdc++.h>
using namespace std;

char a[100], b[100], c[100];
int main()
{
    scanf("%s %s %s",a,b,c);
    int la = strlen(a);
    int lb = strlen(b);
    printf("%s",(a[la-1]==b[0]?(b[lb-1]==c[0]?"YES":"NO"):"NO"));
}
