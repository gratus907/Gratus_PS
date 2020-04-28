#include <cstdio>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;


int main()
{
	int n;
	int group;
	int min;
	int gnum;
	scanf("%d", &n);
	int a, b;
	for (int i = 1; i*(i - 1) / 2 < n; i++)
		group = i;
	min = (group-1)*(group)/2+1;
	gnum = n - min;
	a = group - gnum;
	b = gnum+1 ;
	if (group % 2 == 0)
		printf("%d/%d", b, a);
	else
		printf("%d/%d", a, b);
}