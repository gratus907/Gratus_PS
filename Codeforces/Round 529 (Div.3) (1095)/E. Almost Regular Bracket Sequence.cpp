#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) (A)>(B)?(A):(B)
#define MIN(A,B) (A)<(B)?(A):(B)
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
#define modulo 998244353
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int val[1020000];
char word[1020000];
vector <int> leq_than_one_ind;
vector <int> neg;
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",word+1);
    for (int i = 1; i<=n; i++)
    {
        if (word[i]=='(')
            val[i] = val[i-1]+1;
        else if (word[i] == ')')
            val[i] = val[i-1]-1;
        if (val[i] <= 1)
            leq_than_one_ind.PB(i);
        if (val[i] < 0)
            neg.PB(i);
        if (val[i] < -2)
        {
            printf("0");
            return 0;
        }
    }
    int ans = 0;
    int start = leq_than_one_ind[leq_than_one_ind.size()-1]+1;
    int ed = neg.size()==0? n : neg[neg.size()-1];
    if (val[n]==2)
    {
        for (int i = start; i<=ed; i++)
        {
            if (word[i]=='(')
                ans++;
        }
    }
    if (val[n]==-2)
    {
        int end = neg[0];
        for (int i = 0; i<=end; i++)
        {
            if (word[i]==')')
                ans++;
        }
    }
    printf("%d",ans);

}