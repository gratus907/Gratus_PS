#include <cstdio>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	char word[1001003] = "";
	scanf("%s", &word);
	int i = 0;
	int v = 2;
	int ind;
	int num[26] = {};
	while ((word[i] > 96 && word[i] < 123) || (word[i] >= 'A' && word[i] <='Z'))
	{
		if (word[i] > 95)
			num[word[i] - 97] ++;
		if (word[i] <= 'Z')
			num[word[i] - 'A'] ++;
		i++;
	}
	i = 0;
	int max = num[0];
	while (i < 26)
	{
		if (max < num[i])
			max = num[i];
		i++;
	}
	i = 0;
	while (i < 26)
	{
		if (max == num[i])
		{
			v--;
			ind = i;
		}
		i++;
	}
	if (v <= 0)
	{
		printf("?");
	}
	else
		printf("%c", ind + 'A' );
}