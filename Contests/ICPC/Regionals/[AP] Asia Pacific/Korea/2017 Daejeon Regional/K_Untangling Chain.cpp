#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimine("O3")
using namespace std;
 
int maxpt[4];
int dir = 0;
int newdir (int curdir, int turn)
{
	return (curdir + turn + 4) % 4;
}
 
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	int curx = 0, cury = 0;
	for (int i = 0; i<n; i++)
	{
		int l, t;
		cin >> l >> t;
		if (dir == 0)
		{
			int targ = maxpt[dir] + 1;
			maxpt[dir] = targ;
			cout << abs(targ-curx) << ' ';
			curx = targ;
		}
		else if (dir == 1)
		{
			int targ = maxpt[dir] + 1;
			maxpt[dir] = targ;
			cout << abs(targ-cury) << ' ';
			cury = targ;
		}
		else if (dir == 2)
		{
			int targ = maxpt[dir] - 1;
			maxpt[dir] = targ;
			cout << abs(targ-curx) << ' ';
			curx = targ;
		}
		else if (dir == 3)
		{
			int targ = maxpt[dir] - 1;
			maxpt[dir] = targ;
			cout << abs(targ-cury) << ' ';
			cury = targ;
		}
		//printf("newpt %d %d\n",curx,cury);
		dir = newdir(dir, t);
	}
}