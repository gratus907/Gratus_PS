#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using pii = pair<int, int>;

bool vst[101];
vector <int> arr;
int32_t main()
{
    usecppio
    while(true)
    {
        int n; cin >> n;
        if (!n) return 0;
        arr.clear();
        memset(vst, 0, sizeof(vst));
        set<int> current, prev;
        for (int i = 0; i<n; i++)
        {
            int x; cin >> x;
            vst[x] = true;
            current.insert(x);
            for (auto it:prev)
            {
                int g = __gcd(it, x);
                current.insert(g);
                vst[g] = true;
            }
			prev = current;
            current.clear();
        }
        int cnt = 0;
        for (int i = 1; i<=100; i++)
            if (vst[i]) 
                cnt++;
        cout << cnt << '\n';
    }
}