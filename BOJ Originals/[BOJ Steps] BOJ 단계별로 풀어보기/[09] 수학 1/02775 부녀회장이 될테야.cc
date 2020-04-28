#include <cstdio>
#include <string>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		int floor[15][15] = { { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14 } };
		int a, b;
		scanf("%d", &a);
		scanf("%d", &b);
		for (int j = 1; j <= a; j++)
		{
			for (int u = 0; u <= b; u++)
			{
				for (int k = 0; k <= u; k++)
				{
					floor[j][u] += floor[j - 1][k];
				}
			}
		}
		printf("%d\n", floor[a][b]);
	}
	
}