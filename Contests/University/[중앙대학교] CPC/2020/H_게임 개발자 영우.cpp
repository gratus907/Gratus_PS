#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
using pii = pair<ll, ll>;
int n;
char str[32323];
int score[32323];

// compute score of [st, ed] when exp was zero before st.
int calcScore(int st, int ed)
{
    int s = score[ed] - score[st - 1];
    if (st % 2 == 0)
        s = 6 * (ed - st + 1) - s;
    return s;
}
vector<pii> ans;
int32_t main()
{
    usecppio
    scanf("%lld %s",&n, str+1);
    for (int i = 1; i <= n; i++)
    {
        if (str[i] == 'H') score[i] = 3;
        else
            score[i] = 1 + (i % 2) * 4;
        score[i] += score[i-1];
    }
    for (int x = 1; x <= 5*n; x++)
    {
        int cur = 0, lo, hi, lv = 0, s = 0;
        while(cur < n)
        {
            if (calcScore(cur+1, n) < x)
            {
                goto nextLoop;
            }
            lo = cur, hi = n;
            while(lo + 1 < hi)
            {
                int mid = (lo + hi) / 2;
                if (calcScore(cur+1, mid) >= x)
                    hi = mid;
                else lo = mid;
            }
            s = calcScore(cur+1, hi);
            cur = hi;
            if (s < x) goto nextLoop;
            else lv++;
        }
        ans.push_back({x, lv});
        nextLoop:
        continue;
    }
    sort(all(ans));
    printf("%lld\n",(int)(ans.size()));
    for (auto it:ans)
        printf("%lld %lld\n",it.first,it.second);
}