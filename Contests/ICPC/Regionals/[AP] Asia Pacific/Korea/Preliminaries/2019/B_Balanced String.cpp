#include <bits/stdc++.h>
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define sz(x) (int)((x).size())
#define gcd(a, b) (__gcd((a), (b)))
#define lcm(a, b) ((a) / __gcd((a), (b)) * (b))
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int ans = 1;
int n;
int mod = 16769023;

int main()
{
	cin >> n;
	int u = n/2 + n%2;
	for (int i = 0; i<u; i++)
		ans = (ans*2)%mod;
	cout << ans;
}