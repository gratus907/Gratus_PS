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

string vowel = "aeiou";

char word[1000][1000];
int main()
{
    int n;
    scanf("%d",&n);
    int a = 1, b = n;
    for (int i = 1; i*i<=n; i++)
    {
        if (n%i==0)
        {
            a = i;
            b = n/i;
        }
    }
    if (MIN(a,b)<5)
        printf("-1");
    else
    {
        for (int i = 0; i<a; i++)
        {
            for (int j = 0; j<b; j++)
            {
                printf("%c",vowel[(i+j)%5]);
            }
        }
    }
}
