#include <bits/stdc++.h>
#define MIN(A,B) ((A)<(B)?(A):(B))
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,long double> pid;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        char str[105];
        memset(str,0,sizeof(str));
        scanf("%s",str);
        int a = 0, b = 0;
        for (int i = 0; i<n; i++)
        {
            if (str[i] == '>')
            {
                a = i;
                break;
            }
        }
        for (int i = n-1; i>=0; i--)
        {
            if (str[i] == '<')
            {
                b = n-1-i;
                break;
            }
        }
        printf("%d\n",MIN(a,b));
    }
}
