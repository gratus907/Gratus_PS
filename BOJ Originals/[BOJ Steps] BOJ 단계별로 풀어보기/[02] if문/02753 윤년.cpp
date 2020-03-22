#include <cstdio>
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
	int year;
	scanf("%d", &year);
	int t=0;
	t = ((year % 4 == 0) && (year % 100 != 0))|| ((year % 4 == 0) && (year%400==0)) ;
	printf("%d", t);
}