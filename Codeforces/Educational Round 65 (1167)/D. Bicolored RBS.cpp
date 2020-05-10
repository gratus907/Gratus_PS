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

char str[202020];
stack <int> stk;
int ans[202020];
int n;
int main()
{
    scanf("%d",&n);
    scanf("%s",str);
    int color = 0;
    for (int i = 0; i<n; i++)
    {
        if (str[i]=='(')
        {
            stk.push(i);
        }
        else
        {
            ans[i] = stk.size()%2;
            ans[stk.top()] = stk.size()%2;
            stk.pop();
        }
    }
    for (int i = 0; i<n; i++)
        printf("%d",ans[i]);
}
