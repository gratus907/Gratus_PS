#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const bool debug = 0;
using pii = pair<int, int>;
int n;
vector <int> pfix, bfix;
vector <int> possible_sol;
inline int query(int i, int j)
{
    return bfix[i]^pfix[j]^bfix[0];
}
int check_p0(int x)
{
    vector <int> perm(n, 0);
    vector <int> bval(n, 0);
    vector <int> pp;
    perm[0] = x;
    bval[0] = bfix[0]^x;
    for (int i = 1; i<n; i++)
    {
        perm[i] = query(i, 0)^bval[0];
        bval[i] = query(0, i)^perm[0];
    }
    pp = perm;
    for (int i = 0; i<n; i++)
        if (perm[bval[i]]!=i)
            return 0;
    sort(all(perm)); sort(all(bval));
    for (int i = 0; i<n; i++)
        if (perm[i]!=i || bval[i]!=i)
            return 0;
    possible_sol = pp;
    return 1;
}
int32_t main()
{
    scanf("%d",&n);
    for (int i = 0; i<n; i++)
    {
        int x;
        printf("? %d %d\n",i,0); fflush(stdout);
        scanf("%d",&x);
        bfix.push_back(x);
        printf("? %d %d\n",0,i); fflush(stdout);
        scanf("%d",&x);
        pfix.push_back(x);
    }
    int ans = 0;
    for (int i = 0; i<n; i++)
        ans += check_p0(i);
    printf("!\n%d\n",ans);
    for (int i = 0; i<n; i++)
        printf("%d ",possible_sol[i]);
    printf("\n"); fflush(stdout);
}