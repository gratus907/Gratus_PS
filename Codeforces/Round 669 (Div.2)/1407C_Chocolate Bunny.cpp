#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;

struct Q
{
    int bigind, smallind, big, small;
};
vector <Q> v;
int arr[10101];
int32_t main()
{
    usecppio
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("! 1\n");
        fflush(stdout);
        return 0;
    }
    int last_ind = 1;
    for (int i = 2; i<=n; i++)
    {
        int p1, p2;
        printf("? %d %d\n", last_ind, i);
        fflush(stdout);
        scanf("%d",&p1);
        printf("? %d %d\n",i, last_ind);
        fflush(stdout);
        scanf("%d",&p2);

        if (p1 > p2)
        {
            v.push_back({i, last_ind, p1, p2});
            last_ind = i;
        }

        if (p1 < p2)
        {
            v.push_back({last_ind, i, p2, p1});
        }
    }
    int B = v.back().bigind;
    arr[B] = n;
    while(!v.empty())
    {
        Q q = v.back();
        v.pop_back();
        arr[q.smallind] = q.big;
    }
    printf("! ");
    for (int i = 1; i<=n; i++)
        printf("%d ",arr[i]);
    fflush(stdout);
}