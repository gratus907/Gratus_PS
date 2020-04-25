#include <cstdio>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;

int occurence[26];

int check()
{
	char word[102];
	scanf("%s", word);
	for (int i = 0; i < 103; i++)
	{
		if (word[i] < 'a' || word[i] > 'z')
			break;
		if (i > 0)
		{
			if (word[i] == word[i - 1])
				continue;
		}
		if (occurence[word[i]-'a'] == 0)
		{
			occurence[word[i] - 'a'] = -1;
			continue;
		}
		if (occurence[word[i] - 'a'] == -1)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += check();
		for (int j = 0; j < 26; j++)
			occurence[j] = 0;
	}
	printf("%d\n", sum);
}