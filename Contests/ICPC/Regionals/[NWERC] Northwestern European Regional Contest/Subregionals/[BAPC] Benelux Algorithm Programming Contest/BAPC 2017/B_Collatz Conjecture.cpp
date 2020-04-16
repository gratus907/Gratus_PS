#include <bits/stdc++.h>
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
const bool debug = 0;
using pii = pair<int, int>;
typedef long double D;

int n;
set <int> st;
set <int> ans;
vector <int> v;
int32_t main()
{
    usecppio
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++)
    {
        st.insert(v[i]);
        ans.insert(v[i]);
        for (auto it=st.begin(); it!=st.end();)
        {
            int x = *it;
            it = st.erase(it);
            st.insert(__gcd(x, v[i]));
            ans.insert(__gcd(x, v[i]));
        }
    }
    cout << ans.size() << '\n';
}