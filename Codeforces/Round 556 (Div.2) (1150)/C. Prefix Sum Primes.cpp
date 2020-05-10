#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define ll long long
#define MAX(A,B) (A)>(B)?(A):(B)
#define MIN(A,B) (A)<(B)?(A):(B)
#define gcd(A,B) __gcd(A,B)
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

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int a, b;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i<n; i++)
    {
        int tmp;
        scanf("%d",&tmp);
        if (tmp == 1)
            a++;
        else
            b++;
    }
    if (a <= 2)
    {
        if (b!=0)
        {
            printf("2 ");
            if (a!=0)
                printf("1 ");
            for (int i = 1; i<b; i++)
                printf("2 ");
            for (int i = 1; i<a; i++)
                printf("1 ");
        }
        else
        {
            for (int i = 0; i<a; i++)
                printf("1 ");
        }
    }
    else
    {
        if (a%2)
        {
            for (int i = 0; i<a; i++)
                printf("1 ");
            for (int i = 0; i<b; i++)
                printf("2 ");
        }
        else
        {
            for (int i = 0; i<a-1; i++)
                printf("1 ");
            for (int i = 0; i<b; i++)
                printf("2 ");
            printf("1");
        }
    }
}
