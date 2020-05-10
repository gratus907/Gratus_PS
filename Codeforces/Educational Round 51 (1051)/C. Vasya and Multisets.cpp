#include <bits/stdc++.h>
#define lli long long int
#define bignum (int)1e9
using namespace std;

int num[120];
int occ[120];

int ind[120];
int tmp=0;
int once, twice, more;
int main()
{
    int n;
    int free=0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        occ[x]++;
        num[i] = x;
    }
    for (int i = 0; i<120; i++)
    {
        if (occ[i] == 1)
        {
            ind[i] = 1;
            once++;
        }
        if (occ[i] == 2)
        {
            ind[i] = 2;
            twice++;
        }
        if (occ[i] > 2)
        {
            ind[i] = 2;
            more++;
            free = i;
        }
    }
  //  printf("Test once %d twice %d more %d, free%d\n",once,twice,more, free);

    if(more >= 1)
    {
        printf("YES\n");
        if (once %2 == 1)
            ind[free] = 1;
        else if (once%2==0)
            free=0;
    }
    else if (more < 1 && once %2 == 1)
    {
        printf("NO\n");
        return 0;
    }
    else if (more < 1 && once %2 == 0)
        printf("YES\n");


    if (once == 0 && (more+twice)>0)
    {
        for (int i = 0; i<n; i++)
            printf("A");
        return 0;
    }


    for (int i = 1; i<120; i++)
    {
        if (tmp%2==0 && ind[i] == 1)
        {
            ind[i] = 2;
            tmp++;
        }
        if (tmp%2==1 && ind[i] == 1)
        {
            ind[i] = 1;
            tmp++;
        }
     //   printf("ind of %d is %d\n",i,ind[i]);
    }


    for (int i = 0; i<n; i++)
    {
        int u = num[i];
        if (u == free)
        {
            if (ind[u] == 1)
            {
                if (occ[u] == 1)
                {
                    printf("A");
                    continue;
                }
                else
                {
                    printf("B");
                    occ[u]--;
                    continue;
                }
            }
            if (ind[u] == 2)
            {
                if (occ[u] == 1)
                {
                    printf("B");
                    continue;
                }
                else
                {
                    printf("A");
                    occ[u]--;
                    continue;
                }
            }
        }
        else
        {
            if (ind[u] == 1)
            {
                printf("A");
                ind[u] = 2;
                continue;
            }
            if (ind[u] == 2)
            {
                printf("B");
                continue;
            }
        }
    }
}
