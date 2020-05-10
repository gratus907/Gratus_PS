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

char str[101010];
int c = 0;
int vs = 0;
vector <char> v;
int main()
{
    scanf("%s",str);
    int len = strlen(str);
    for (int i = 0; i<len; i++)
    {
        v.PB(str[i]);
        vs++;
        if (vs>=2)
        {
            if (v[vs-1]!=v[vs-2])
            {
                v.pop_back();
                v.pop_back();
                vs -= 2;
                c+=2;
            }
        }
    }
    printf("%d",c);
}
