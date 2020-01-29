#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define MOD 1000000007
#define int ll
using pii = pair <int, int>;

int n, k, ans;
int arr[1010];
int able(int x)
{
    int res = 0;
    vector <int> v(k, 0);
    for (int i = 1; i<=n; i++)
    {
        int divide_to = arr[i]/x;
        if (divide_to == 0)
            v.push_back(arr[i]);
        else
        {
            int mm = arr[i]%divide_to;
            for (int j = 0; j<divide_to; j++)
            {
                int uu = arr[i]/divide_to;
                if (j < mm)
                    uu++;
                v.push_back(uu);
            }
        }
    }
    sort(all(v), greater<int>());
    for (int i = k/2; i<k; i++)
        res += v[i];
    return res;
}
int32_t main()
{
    ifstream fin("berries.in");
    ofstream fout("berries.out");
    fin >> n >> k;
    for (int i = 1; i<=n; i++)
        fin >> arr[i];
    for (int i = 1; i<=1001; i++)
        ans = max(ans, able(i));
    fout << ans;
}