#include <cstdio>
#pragma warning(disable: 4996)
using namespace std;

int main()
{
	int i = 1;
	int n;
	scanf("%d", &n);
	if (n == 1)
	{
		printf("1");
		return 0;
	}
	while (3 * i*(i + 1) + 1 < n)
		i++;
	printf("%d", i + 1);
}