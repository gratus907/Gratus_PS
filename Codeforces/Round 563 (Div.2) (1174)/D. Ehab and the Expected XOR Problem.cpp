#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define ll long long
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define gcd(A,B) (__gcd(A,B))
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
#define mod 1000000007LL
#define all(x) x.begin(), x.end()
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int n, x;
int L = 0;
int xor_prefix[1001000];
bool marked[1001000];
int main()
{
    scanf("%d %d",&n,&x);
    int u = (1<<n);
    if (x >= (1<<n))
    {
        L = (1<<n)-1;
        for (int i = 1; i<u; i++)
        {
            xor_prefix[i] = i;
        }
        printf("%d\n",L);
        for (int i = 1; i<u; i++)
        {
            printf("%d ",xor_prefix[i] xor xor_prefix[i-1]);
        }
    }
    else
    {
        L = ((1<<n)-2)/2;
        if (L==0)
        {
            printf("0");
            return 0;
        }
        int cur = 1;
        marked[x] = true;
        for (int i = 1; i<u; i++)
        {
            if (!marked[i])
            {
                xor_prefix[cur] = i;
                marked[i xor x] = true;
                cur++;
            }
        }
        printf("%d\n",L);
        for (int i = 1; i<=L; i++)
        {
            printf("%d ",xor_prefix[i] xor xor_prefix[i-1]);
        }
    }

}
