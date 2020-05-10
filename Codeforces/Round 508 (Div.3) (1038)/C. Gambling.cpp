#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int a[100020], b[100020];
lli sa, sb;
int ale, ble;

void work_A()
{
	if (b[ble] > a[ale])
	{
		b[ble] = 0;
		ble--;
	}
	else
	{
		sa += a[ale];
		a[ale] = 0;
		ale--;
	}
}

void work_B()
{
	if (a[ale] > b[ble])
	{
		a[ale] = 0;
		ale--;
	}
	else
	{
		sb += b[ble];
		b[ble] = 0;
		ble--;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i] = x;
	}
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		b[i] = x;
	}
	sort(a, a + n);
	sort(b, b + n);
	ale = n - 1;
	ble = n - 1;
	for (int i = 0; i < n; i++)
	{
		work_A();
		work_B();
	}
	printf("%lld", sa - sb);
}
