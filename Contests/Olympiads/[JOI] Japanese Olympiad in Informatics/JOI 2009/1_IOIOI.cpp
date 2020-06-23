#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using pii = pair<int, int>;

string cur, str;
vector <int> v;
int32_t main()
{
    bool status = true;
    int n, m; cin >> n >> m >> str;
    int cnt = 1;
    for (auto s:str)
    {
        status = true;
        if (cur.empty())
        {
            if (s == 'I')
                cur.push_back(s);
            else
                status = false;
        }
        else if (cur.back()=='I')
        {
            if (s == 'O')
                cur.push_back(s);
            else status = false;
        }
        else if (cur.back()=='O')
        {
            if (s == 'I')
                cur.push_back(s);
            else status = false;
        }

        if (!status)
        {
            if (!cur.empty())
            {
                if (cur.back()=='O')
                    cur.pop_back();
                v.push_back((cur.size()-1)/2);
                cur.clear();
                cur.push_back(s);
            }
        }
        cnt++;
    }
    if (!cur.empty())
    {
        if (cur.back()=='O')
            cur.pop_back();
        v.push_back((cur.size()-1)/2);
        cur.clear();
    }
    int ans = 0;
    for (auto it:v)
        ans += (max(0, it-n+1));
    cout << ans << '\n';
}