#include <cstdio>
#include <cmath>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;


int main()
{
	long long int a, b, v;
	long long int x;
	scanf("%lld %lld %lld", &a, &b, &v);
	x = ceil(((double)(v - a)) / ((double)(a - b)));
	x += 1;
	printf("%lld", x);
}