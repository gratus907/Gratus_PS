#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair <int, int> pii;

int stair[101010];
int main()
{
    usecppio
    int n;
    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        cin >> stair[i];
    }
    for (int i = 1; i<=n; i++)
    {
        if (stair[i] > stair[i-1])
            stair[i]--;
    }
    bool ok = true;
    for (int i = 1; i<=n; i++)
        if (stair[i] < stair[i-1])
            ok = false;
    cout << (ok?"Yes":"No");
}
