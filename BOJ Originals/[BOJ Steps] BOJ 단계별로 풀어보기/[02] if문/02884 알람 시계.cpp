#include <cstdio>
#include <cstring>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	int h, m;
	scanf("%d %d", &h, &m);
	int a, b;
	b = m - 45;
	a = h;
	if (b < 0)
	{
		b = b + 60;
		a--;
	}
	if (a < 0)
	{
		a += 24;
	}
	printf("%d %d", a, b);
}