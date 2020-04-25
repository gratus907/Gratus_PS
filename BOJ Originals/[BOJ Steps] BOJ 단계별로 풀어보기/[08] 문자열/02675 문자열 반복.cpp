#include <cstdio>
#include <cstring>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;


int main() 
{
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		char str[22];
		int times;
		scanf("%d", &times);
		scanf("%s", str);
		int x = 0;
		while (true)
		{
			
			if (str[x] >= 33 && str[x] <= 95)
			{
				for (int j = 0; j < times; j++)
					printf("%c", str[x]);
				
			}
			else
				break;
			x++;
		}
		printf("\n");
	}
}