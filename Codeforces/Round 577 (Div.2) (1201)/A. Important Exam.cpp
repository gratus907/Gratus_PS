#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimine("O3")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int count_ans[1010][7];
int score[1010];
int totalscore;
int main()
{
	usecppio
	int n, m;
	cin >> n >> m;
	for (int i = 0; i<n; i++)
	{
		string answer;
		cin >> answer;
		for (int x = 0; x<m; x++)
		{
			count_ans[x][answer[x]-'A']++;
		}
	}
	for (int i = 0; i<m; i++)
	{
		cin >> score[i];
	}
	for (int i = 0; i<m; i++)
	{
		int M = 0;
		for (int x = 0; x<7; x++)
		{
			M = max(M, count_ans[i][x]);
		}
		totalscore += (score[i] * M);
	}
	cout << totalscore;
}
