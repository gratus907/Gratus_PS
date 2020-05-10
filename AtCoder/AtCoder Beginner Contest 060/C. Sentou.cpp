#include <bits/stdc++.h>
using namespace std;

int n,t;
vector <pair <int, int>> v;
int main()
{
    scanf("%d %d",&n,&t);
    for (int i = 0; i<n; i++)
    {
        int ai;
        scanf("%d",&ai);
        v.push_back({ai,ai+t});
    }
    int cur_start = v[0].first;
    int cur_end = v[0].second;
    int ans = 0;
    for (int i = 1; i<n; i++)
    {
        if (v[i].first>cur_end)
        {
            ans += cur_end-cur_start;
            cur_start = v[i].first;
            cur_end = v[i].second;
        }
        else
        {
            cur_end = v[i].second;
        }
    }
    ans += cur_end-cur_start;
    printf("%d",ans);
}
