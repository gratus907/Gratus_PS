#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    bool flag = 0;
    int n;
    cin >> n;
    for (int i = 1; i<=9; i++)
        for (int j = 1; j<=9; j++)
            if (n == i*j) 
                flag = 1;
    cout << (flag?"Yes\n":"No\n");
}