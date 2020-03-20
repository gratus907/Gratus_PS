#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int a, b, c, d, e;
int n, k;
int need(int x)
{
    return (x/k)+1-(x%k==0);
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i<n; i++)
    {
        int s, y;
        cin >> s >> y;
        if (y <= 2)
            a++;
        else if (y <= 4)
            s?b++:c++;
        else s?d++:e++;
    }
    cout << need(a)+need(b)+need(c)+need(d)+need(e) << '\n';
}