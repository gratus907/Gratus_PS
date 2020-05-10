#include <bits/stdc++.h>
#define lli long long int
using namespace std;

vector <int> v1;
vector <int> v2;

void pvec()
{
	int vs1 = v1.size();
	int vs2 = v2.size();
	printf("%d ", vs1);
	for (int i = 0; i < vs1-1; i++)
		printf("%d ", v1[i]);
	printf("%d\n", v1[vs1 - 1]);
	printf("%d ", vs2);
	for (int i = 0; i < vs2 - 1; i++)
		printf("%d ", v2[i]);
	printf("%d\n", v2[vs2 - 1]);
	return;
}

int main()
{
	int n;
	scanf("%d", &n);
	if (n == 2 || n == 1)
	{
		printf("No");
		return 0;
	}
	else
		printf("Yes\n");
	if (n % 2 == 0)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i % 2 == 0)
				v1.push_back(i);
			else
				v2.push_back(i);
		}
		pvec();
		return 0;
	}
	else
	{
		int k = (n + 1) / 2;
		for (int i = 1; i <= n; i++)
		{
			if (i % k == 0)
				v1.push_back(i);
			else
				v2.push_back(i);
		}
		pvec();
		return 0;
	}

}
