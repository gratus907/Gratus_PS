#include <cstdio>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{

	int T;
	scanf("%d", &T);
	char k = '0';
	char right = 'O';
	char wrong = 'X';
	for (int j = 0; j < T; j++)
	{
		int num = 0;
		int score = 0;
		char word[81] = " ";
		scanf("%s", &word);
		for (int i = 0; word[i] > k; i++)
		{
			if (word[i] == right)
			{
				num++;
				score = score + num;
			}
			else
			{
				num = 0;
			}

		}

		printf("%d\n", score);
	}
	
} 

