#include <bits/stdc++.h>
#define ll long long
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define mod 1000000007LL
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,long double> pid;

int cand[210000];
int percand[210000];
int n;

bool is_valid_permutation(int candidate[])
{
    sort(candidate,candidate+n);
    for (int i = 0; i<n; i++)
    {
        if (candidate[i] != i+1)
            return false;
    }
    return true;
}
int main()
{
    scanf("%d",&n);
    int mini = INT_MAX;
    for (int i = 1; i<n; i++)
    {
        int tmp;
        scanf("%d",&tmp);
        cand[i] = cand[i-1]+tmp;
        percand[i] = cand[i];
        mini = MIN(mini, cand[i]);
    }
    mini = MIN(mini,0);
    int u = mini-1;
    for (int i = 0; i<n; i++)
    {
        cand[i] -= u;
        percand[i] -= u;
    }
    if (is_valid_permutation(cand))
    {
        for (int i = 0; i<n; i++)
            printf("%d ",percand[i]);
    }
    else
        printf("-1");
}
