#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
#define lli long long int
using namespace std;

lli gcd(lli a, lli b)
{
	return b ? gcd(b, a%b) : a;
}

lli min(lli a, lli b)
{
	return a > b ? b : a;
}

int main()
{
	lli a, b, x, y;
	scanf("%lld %lld %lld %lld", &a, &b, &x, &y);
	lli g = gcd(x, y);
	x = x / g;
	y = y / g;
	printf("%lld", min(a / x, b / y));
}