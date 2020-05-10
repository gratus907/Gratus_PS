#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimization ("unroll-loops")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using namespace std::chrono;
using pii = pair<int, int>;

map <string, int> m;
vector <ll> v;
int main()
{
	auto start = high_resolution_clock::now();
	ll a = 0;
	for (ll i = 1; i<=34000; i++)
	{
		ll x = (i*i)*i;
		string str = to_string(x);
		sort(all(str));
		m[str]++;
	}
	for (ll i = 1; i<=34000; i++)
	{
		ll x = (i*i)*i;
		string str = to_string(x);
		sort(all(str));
		if (m[str]==5)
			v.push_back(x);
	}
	sort(all(v));

	auto end = high_resolution_clock::now();
	cout << v[0] << endl;
	auto elapse = duration_cast<milliseconds>(end-start);
	cout << "Solve time :" << elapse.count();
}
