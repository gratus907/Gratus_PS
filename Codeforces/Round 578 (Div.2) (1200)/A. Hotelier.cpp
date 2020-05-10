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

bool hotelroom[10];
string op;
int main()
{
	usecppio
	int n;
	cin >> n;
	cin >> op;
	for (auto it:op)
	{
		if (it=='L')
		{
			for (int i = 0; i<10; i++)
			{
				if (!hotelroom[i])
				{
					hotelroom[i] = 1;
					break;
				}
			}
		}
		else if (it=='R')
		{
			for (int i = 9; i>=0; i--)
			{
				if (!hotelroom[i])
				{
					hotelroom[i] = 1;
					break;
				}
			}
		}
		else if ('0' <= it && it <= '9')
		{
			hotelroom[it-'0'] = 0;
		}
	}

	for (int i = 0; i<10; i++)
	{
		printf("%d",hotelroom[i]?1:0);
	}
}
 
