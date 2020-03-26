#include <cstdio>
#include <array>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;

double average(int score[], int n)
{
	double sum=0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + score[i];
	}
	return sum / n;
}

int main()
{
	int C;
	scanf("%d", &C);
	int score[1000];
	fill(score, score + 1000, -1);
	for (int i = 0; i < C; i++)
	{
		int number = 0;
		int n;
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
		{
			int p;
			scanf("%d", &p);
			score[j] = p;
		}
		double avg = average(score, n);
		for (int k = 0; k < n; k++)
		{
			if (score[k] > avg)
			{
				number += 1;
			}
		}

		printf("%.3f%%\n", double (number) / double (n) * 100);
	}
}