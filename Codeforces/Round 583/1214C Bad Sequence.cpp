#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

string str;
int n;
int ct[202020];
int reff[2] = {-1,1};
int main()
{
    cin >> n >> str;
    ct[0] = reff[str[0]=='('];
    for (int i = 1; i<n; i++)
        ct[i] = ct[i-1] + reff[str[i]=='('];

      
    if (ct[n-1]!=0)
    {
        cout << "No";
        return 0;
    }    
    for (int i = 0; i<n; i++)
    {
        if (ct[i] < -1)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}