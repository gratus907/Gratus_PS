#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int main()
{
	while(true)
	{
		char tmp[1010];
		cin.getline(tmp,1010);
		string str = string(tmp);
		if (str[0] == '.')
		{
			return 0;
		}
		else
		{
			stack <char> st;
			for (auto it:str)
			{
				if (it=='(' || it == '[')
				{
					st.push(it);
				}
				else if (it==')')
				{
					if (!st.empty() && st.top()=='(')
						st.pop();
					else
					{
						cout << "no\n";
						goto end;
					}
				}
				else if (it==']')
				{
					if (!st.empty() && st.top()=='[')
						st.pop();
					else
					{
						cout << "no\n";
						goto end;
					}
				}
				else continue;
			}
			if (st.empty())
				cout << "yes\n";
			else
				cout << "no\n";
			goto end;
		}
		end:
		continue;
	}
}