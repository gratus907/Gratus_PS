#include <bits/stdc++.h>
#define lli long long int
using namespace std;

char word[120000];
int oc[26];
int main()
{
	int n, k;
	int min = 1000000;
	scanf("%d %d", &n, &k);
	scanf("%s", word);
	for (int i = 0; i < n; i++)
		oc[word[i] - 'A'] ++;
	for (int i = 0; i < k; i++)
	{
		if (min >= oc[i])
			min = oc[i];
	}
	for (int i = 0; i < k; i++)
	{
		if (min < oc[i])
			n -= (oc[i] - min);
		if (n <= 0)
		{
			printf("0");
			return 0;
		}
	}
	printf("%d", n);

}
