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

int n, b;
map <int, vector<int>> mp;
map <int, int> ansmp;
set <int> st;
multiset<int> alldist;
void dins(int xx)
{
    if (xx == 0) return;
    else alldist.insert(xx);
}
void ers(int xx)
{
    if (alldist.lower_bound(xx) == alldist.end())
        return;
    alldist.erase(alldist.lower_bound(xx));
}
void stinsert(int ins)
{
    if (st.empty())
    {
        st.insert(ins);
        ers(n-1);
        dins(n-ins);
        dins(ins-1);
        return;
    }
    if (ins < *st.begin())
    {
        ers(*st.begin()-1);
        dins(*st.begin()-ins);
        dins(ins-1);
        st.insert(ins);
        return;
    }
    if (ins > *st.rbegin())
    {
        ers(n-*st.rbegin());
        dins(ins-*st.rbegin());
        dins(n-ins);
        st.insert(ins);
        return;
    }
    auto tt = st.lower_bound(ins);
    tt--;
    int u = *(tt);
    int v = *st.upper_bound(ins);
    ers(v-u);
    dins(v-ins);
    dins(ins-u);
    st.insert(ins);
    return;
}
int main()
{
    usecppio
    cin >> n >> b;
    for (int i = 1; i<= n; i++)
    {
        int x; cin >> x;
        mp[x].push_back(i);
    }
    int ans = n-1;
    for (auto it:mp)
    {
        int x = it.first;
        for (auto itt:it.second)
            stinsert(itt);
        if (alldist.empty()) ans = 0;
        else
            ans = *alldist.rbegin();
        ansmp[x] = ans;
    }
    ansmp[-1] = INT_MAX;
    while(b--)
    {
        int f, d;
        cin >> f >> d;
        cout << (((*(--ansmp.upper_bound(f))).second <= d)?1:0) << '\n';
    }
}