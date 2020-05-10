#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define ll long long
#define int ll
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair <int, int> pii;

vector <int> arr;
int n, k;
vector <int> divisor;

bool chk(int x)
{
    int r = 0;
    vector <int> t;
    for (auto it:arr)
    {
        t.push_back(it%x);
        r += (it%x);
    }
    sort(all(t));
    int ss = arr.size();
    int u = r/x;
    int rr = 0;
    for (int i = 0; i<ss-u; i++)
        rr += t[i];
    return rr <= k;
}


int32_t main()
{
    usecppio
    cin >> n >> k;
    int sum = 0;
    for (int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
        sum += x;
    }
    for (int i = 1; i<=(int)(sqrt(sum)); i++)
    {
        if (sum%i==0)
        {
            divisor.push_back(i);
            divisor.push_back(sum/i);
        }
    }
    int ans = 1;
    for (auto it:divisor)
    {
        if (chk(it))
            ans = max(ans, it);
    }
    cout << ans;
}
