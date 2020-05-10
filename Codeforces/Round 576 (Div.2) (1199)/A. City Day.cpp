#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define ll long long
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair <int, int> pii;

int rain[101010];
bool ok[101010];
int n, x, y;
int main()
{
    usecppio
    cin >> n >> x >> y;
    for (int i = 1; i<=n; i++)
    {
        cin >> rain[i];
    }
    for (int i = 1; i<=n; i++)
    {
        bool ck = true;
        for (int j = (max(1,i-x)); j <= (min(n,i+y)); j++)
        {
            if (rain[i] > rain[j])
            {
                ck = false;
                break;
            }
        }
        ok[i] = ck;
    }
    for (int i = 1; i<=n; i++)
    {
        if (ok[i])
        {
            cout << i;
            return 0;
        }
    }
}
