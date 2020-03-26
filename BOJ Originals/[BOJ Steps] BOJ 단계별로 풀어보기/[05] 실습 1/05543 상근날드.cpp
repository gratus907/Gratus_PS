#include <cstdio>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	int burger;
	int drink;
	int buff;
	scanf("%d", &burger);
	scanf("%d", &buff);
	if (buff <= burger)
	{
		burger = buff;
	}
	scanf("%d", &buff);
	if (buff <= burger)
	{
		burger = buff;
	}
	scanf("%d", &drink);
	scanf("%d", &buff);
	if (buff <= drink)
	{
		drink = buff;
	}
	printf("%d", burger + drink - 50);
}