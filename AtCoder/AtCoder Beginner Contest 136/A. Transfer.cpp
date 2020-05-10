#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair <int, int> pii;


int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << (c-min(a-b,c));
}
