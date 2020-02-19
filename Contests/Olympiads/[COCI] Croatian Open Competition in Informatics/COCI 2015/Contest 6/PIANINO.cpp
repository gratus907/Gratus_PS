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
#define PI acos(-1.0)
using pii = pair<int, int>;

map <int, int> mp;

int music[1010101];
int diff[1010101];
int32_t main()
{
    usecppio
    int base = 1;
    int n;
    cin >> n;
    for (int i = 0; i<n; i++)
        cin >> music[i];
    for (int i = 1; i<n; i++)
    {
        diff[i] = diff[i-1];
        if (music[i]>music[i-1])
            diff[i]++;
        else if (music[i] < music[i-1])
            diff[i]--;
    }
    for (int i = 1; i<n; i++)
    {
        if (diff[i] == 0)
        {
            if (music[i]-music[0]==0)
                base++;
            continue;
        }
        if ((music[i]-music[0])%diff[i]==0)
            mp[(music[i]-music[0])/diff[i]]++;
    }
    int M = -1, MIND = -1;
    for (auto it:mp)
    {
        if (it.second > M)
        {
            M = it.second; MIND = it.first;
        }
    }
    cout << M+base << '\n' << MIND << '\n';
}