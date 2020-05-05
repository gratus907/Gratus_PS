#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int A[201010];
string S;
string tmp;
void manacher()
{
	S.push_back(0);
	for (auto it:tmp)
	{
		S.push_back('#');
		S.push_back(it);
	}
	S.push_back('#');
	int N = S.length();
	int r = 0, p = 0;
	for (int i=1;i<=N;i++)
	{
		if (i <= r) A[i] = min(A[2*p-i],r-i);
		else A[i] = 0;
		while ((i-A[i]-1 > 0) && (i+A[i]+1 <= N) && (S[i-A[i]-1] == S[i+A[i]+1]))
			A[i]++;
		if (r < i+A[i]) r = i+A[i], p = i;
	}
}

int main()
{
	cin >> tmp;
	manacher();
	int len = S.length();
	int ans = -1;
	for (int i = 0; i<len; i++)
	{
		ans = max(ans, A[i]);
	}
	cout << ans << '\n';
}