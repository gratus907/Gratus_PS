#include <bits/stdc++.h>
#define lli long long int
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/__gcd(A,B)*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define sgn(A) (A==0)? (0) : (A/(abs(A)))
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

vector <char> str;

char tmp[1200000];
int main()
{
    int i = 0;
    scanf("%s",tmp);
    int len = strlen(tmp);
    while(i<len)
    {
        str.PB(tmp[i]);
        if (str.size()>3)
        {
            int u = str.size();
            if (str[u-1]== 'P')
            {
                if (str[u-2] == 'A')
                {
                    if (str[u-3] == 'P')
                    {
                        if (str[u-4] == 'P')
                        {
                            str.erase(str.begin()+u-4, str.end());
                            str.PB('P');
                        }
                    }
                }
            }
        }
        i++;
    }
    if (str.size()==1 && str[0] == 'P')
        printf("PPAP");
    else
        printf("NP");
}