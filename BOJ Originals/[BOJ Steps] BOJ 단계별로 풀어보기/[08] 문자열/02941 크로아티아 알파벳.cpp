#include <cstdio>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;

char croat[102];
int main()
{
	scanf("%s", croat);
	int c = 1;
	for (int i = 1; i < 101; i++)
	{
		if (croat[i] < 123 && croat[i] > 21)
		{
			if (croat[i] == '=' || croat[i] == '-')
				continue;
			if (croat[i] == 'j' && (croat[i - 1] == 'l' || croat[i - 1] == 'n'))
				continue;
			c++;
		}
	}
	for (int i = 2; i < 101; i++)
	{
		if (croat[i] == '=' && croat[i-1] == 'z' && croat[i-2] == 'd')
			c--;
	}
	printf("%d", c);
}