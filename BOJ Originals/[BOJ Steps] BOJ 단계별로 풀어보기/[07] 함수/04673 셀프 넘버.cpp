#include <cstdio>
using namespace std;

int generate(int n)
{
	if(n>=1000)
	{
		return n+n%10+(n%100)/10+(n%1000)/100+n/1000;
	}
	else if(n>=100)
	{
		return n+n%10+(n%100)/10+(n%1000)/100;
	}
	else if (n>=10)
	{
		return n+n%10+(n%100)/10;
	}
	else
	{
		return n+n%10;
	}
}

int main()
{
	int arr[10100];
	int k;
	for (int i=0;i<10100;i++)
	{
		arr[i]=i;
	}
	for (int j =1; j<10001; j++)
	{
		if(arr[j] !=0)
		{
			k = arr[j];
			for (;generate(k)<10001;)
			{
				k=generate(k);
				arr[k]=0;
			}
		}
	}
	for (int u=1; u<10001; u++)
	{
		if(arr[u]!=0)
		{
			printf("%d\n",arr[u]);
		}
	}
}