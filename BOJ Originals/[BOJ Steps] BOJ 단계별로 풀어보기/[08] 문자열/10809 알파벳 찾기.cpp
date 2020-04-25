#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	char word[103] = "";
	scanf("%s", &word);
	int i = 0;
	int num[26] = {};
	fill(num, num + 26, -1);
	while (word[i] > 96 && word[i] < 123)
	{
		if (num[word[i] - 97] == -1)
		{
			num[word[i] - 97] = i;
		}
		i++;
	}
	for (int j = 0; j < 25; j++)
	{
		printf("%d ", num[j]);
	}
	printf("%d", num[25]);
}