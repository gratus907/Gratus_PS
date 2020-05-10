#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

using pii = pair<int, int>;

int party[105];
vector <int> coal;
int n;
int main()
{
    usecppio
    cin >> n;
    int total = 0;
    int a;
    int af = 0;
    cin >> a;
    coal.push_back(1);
    total += a;
    af += a;
    for (int i = 0; i<n-1; i++)
    {
        cin >> party[i];
        total += party[i];
        if (a >= 2*party[i])
        {
            coal.push_back(i+2);
            af += party[i];
        }
    }
    if ((total)/2 < af)
    {
        cout << coal.size() << '\n';
        for (auto it:coal)
        {
            cout << it << ' ';
        }
    }
    else
        cout << 0;
}
