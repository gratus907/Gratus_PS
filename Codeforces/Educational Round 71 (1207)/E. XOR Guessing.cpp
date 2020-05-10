#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 987654321
using namespace std;
using pii = pair<int, int>;

vector <int> seq1;
vector <int> seq2;
int answer, n1, n2;
int main()
{
	for (int i = 0; i<100; i++)
		seq1.push_back(i);
	for (int i = 1; i<=100; i++)
		seq2.push_back(i<<7);
	printf("?");
	for(auto it:seq1)
		printf(" %d",it);
	printf("\n");
	fflush(stdout);
	scanf("%d",&n1);
	for (int i = 7; i<14; i++)
	{
		if (n1 & (1<<i))
			answer += (1<<i);
	}
	printf("?");
	for(auto it:seq2)
		printf(" %d",it);
	printf("\n");
	fflush(stdout);
	scanf("%d",&n2);
	for (int i = 0; i<7; i++)
	{
		if (n2 & (1<<i))
			answer += (1<<i);
	}
	printf("! %d\n",answer);
	fflush(stdout);
}
