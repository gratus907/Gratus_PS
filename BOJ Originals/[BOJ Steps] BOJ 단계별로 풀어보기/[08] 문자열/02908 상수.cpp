#include <cstdio>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	int a, b, c, d, e, f;
	int p, q;
	scanf("%d %d", &p, &q);
	a = p / 100;
	d = q / 100;
	b = (p - 100 * a) / 10;
	e = (q - 100 * d) / 10;
	c = p % 10;
	f = q % 10;
	p = 100 * c + 10 * b + a;
	q = 100 * f + 10 * e + d;
	printf("%d", p > q ? p : q);
}