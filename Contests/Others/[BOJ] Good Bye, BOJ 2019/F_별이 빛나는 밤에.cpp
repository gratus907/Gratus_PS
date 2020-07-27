#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair <int, int>;
using DB = long double;
#define int ll
const int mod = 1000000007;

int n;
DB x_1, x_2, y_1, y_2;
DB m, yp;
struct point
{
	DB x, y;
	point(DB a, DB b)
	{
		x = a, y = b;
	}
};
class convex_hull
{
public:
	int n;

	int ccw (point &a, point &b, point &c)
	{
		int v = (b.x - a.x) * (c.y - a.y) - (b.y-a.y)*(c.x-a.x);
		if (v > 0) return 1;
		if (!v) return 0;
		return -1;
	}
	static bool compy (point &a, point &b)
	{
		if (a.y == b.y) return a.x < b.x;
		return a.y < b.y;
	}
	static bool compang(point &a, point &b)
	{
		if (a.y*b.x == a.x*b.y) return compy(a, b);
		return a.y*b.x < a.x*b.y;
	}
	vector <point> pt;
	vector <point> convex;
	void graham_scan()
	{
		sort(all(pt),compy);
		point down = pt[0];
		for (int i = 0; i<n; i++)
		{
			pt[i].x -= down.x;
			pt[i].y -= down.y;
		}
		sort(all(pt), compang);
		convex.push_back(pt[0]);
		convex.push_back(pt[1]);
		for (int i = 2; i<n; i++)
		{
			while(convex.size() > 1)
			{
				point tp = convex.back();
				convex.pop_back();
				point tptp = convex.back();
				if (ccw(tptp,tp,pt[i]) >= 0)
				{
					convex.push_back(tp);
					break;
				}
			}
			convex.push_back(pt[i]);
		}
	}
};

convex_hull CV;
struct rail
{
	DB st, ed, mdp;
	DB y;
	bool need = true;
	rail (int a = 0, int b = 0, int c = 0)
	{
		st = a, ed = b, y = c;
	}
	DB mindist_pt()
	{
		DB tg;
		if (x_2 == x_1)
			tg = x_1;
		else
			tg = (y-yp)/m;
		if (st <= tg && tg <= ed)
		{
			need = false;
			return tg;
		}
		else
		{
			if (abs(tg-st) < abs(tg-ed)) return st;
			else return ed;
		}
	}
};
vector <rail> stars;
DB xs[10101], ys[10101];
DB txs[10101], tys[10101];
DB area(int A, int B, int C)
{
	DB xa, xb, ya, yb;
	xa = xs[B]-xs[A];
	ya = ys[B]-ys[A];
	xb = xs[C]-xs[A];
	yb = ys[C]-ys[A];
	return (abs((xa*yb-ya*xb)*(DB)0.5));
}
int32_t main()
{
	usecppio
	cin >> n;
	cin >> x_1 >> y_1 >> x_2 >> y_2;
	if (x_2 == x_1) m = INT_MAX;
	else m = (y_2-y_1)*1.0/(x_2-x_1);
	if (x_2 == x_1) yp = 0;
	else yp = y_1 - m*x_1;
	for (int i = 0; i<n; i++)
	{
		int yy, xst, xed;
		cin >> yy >> xst >> xed;
		stars.push_back(rail(xst, xed, yy));
		stars.back().mdp = stars.back().mindist_pt();
		if (!stars.back().need)
			stars.pop_back();
	}
	n = stars.size();
	if (n == 0)
	{
		cout << setprecision(30) << fixed << 0 << '\n';
		return 0;
	}
	txs[0] = x_1, tys[0] = y_1;
	for (int i = 1; i<=n; i++)
	{
		txs[i] = stars[i-1].mdp;
		tys[i] = stars[i-1].y;
	}
	txs[n+1] = x_2;
	tys[n+1] = y_2;
	n+=2;
	CV.n = n;
	for (int i = 0; i<n; i++)
		CV.pt.push_back(point(txs[i],tys[i]));
	CV.graham_scan();
	int tt= CV.convex.size();
	n = tt;
	for (int i = 0; i<n; i++)
	{
		xs[i] = CV.convex[i].x;
		ys[i] = CV.convex[i].y;
	}
	int A = 0, B = 1, C = 2;
	int bA= A, bB= B, bC= C;
	while (1)
	{
		while (1)
		{
			while (area(A, B, C) < area(A, B, (C+1)%n))
				C = (C+1)%n;
			if (area(A, B, C) < area(A, (B+1)%n, C))
			{
				B = (B+1)%n;
				continue;
			}
			else
				break;
		}
		if ((area(A, B, C)) > (area(bA, bB, bC)))
		{
			bA = A; bB = B; bC = C;
		}
		A = (A+1)%n;
		if (A==B)
			B = (B+1)%n;
		if (B==C)
			C = (C+1)%n;
		if (A==0)
			break;
	}
	cout << setprecision(50) << fixed << area(bA, bB, bC) << '\n';
}
