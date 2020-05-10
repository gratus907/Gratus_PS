#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
vector <pair <int, int>> v;
int main()
{
    int n; 
    cin >> n; 
    for (int i = 1; i<=n; i++)
    {
        int t;
        cin >> t;
        v.push_back({t, i});
    }
    sort(all(v));
    for (auto it:v)
    {
        cout << it.second << ' ';
    }
    cout << '\n';
}