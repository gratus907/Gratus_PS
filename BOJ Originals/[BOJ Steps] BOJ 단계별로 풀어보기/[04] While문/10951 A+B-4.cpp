#include <stdio.h>
using namespace std;
#pragma warning(disable:4996), _CRT_SECURE_NO_WARNINGS

int main()
{
	int a, b = 0;
	while(~scanf("%d %d", &a, &b))
	{
        printf("%d\n", a + b);
    }
}