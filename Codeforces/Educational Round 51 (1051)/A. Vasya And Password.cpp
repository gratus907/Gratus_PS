#include <bits/stdc++.h>
#define lli long long int
#define bignum (int)1e9
using namespace std;

char newp[3] = {'0','A','a'};

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {

        char password[120];
        scanf("%s",password);
        int check[3] = {0,0,0};
        int pos[3];
        int len = strlen(password);
        for (int i = 0; i<len; i++)
        {
            if (password[i] >= '0' && password[i] <= '9')
            {
                check[0]++;
                pos[0] = i;
            }
            else if (password[i] >= 'A' && password[i] <= 'Z')
            {
                check[1]++;
                pos[1] = i;
            }
            else if (password[i] >= 'a' && password[i] <= 'z')
            {
                check[2]++;
                pos[2] = i;
            }
        }
        int cnt=0;
        int lack;
        int many=0;
        for (int i = 0; i<3; i++)
        {
            if(check[i] == 0)
            {
                cnt++;
                lack = i;
            }
            if(check[i] >= 2)
                many=i;
        }
        if (cnt== 0)
        {
            printf("%s\n",password);
            continue;
        }
        else if(cnt == 1)
        {
            password[pos[many]] = newp[lack];
        }
        else if (cnt == 2)
        {
            password[0] = newp[lack];
            password[1] = newp[3-lack-many];
        }
        printf("%s\n",password);
        continue;
    }
}

