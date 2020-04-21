#include <bits/stdc++.h>
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
const bool debug = 0;
using pii = pair<int, int>;
typedef long double D;

int ct[26];
int L[3030][3030];
string str;
string lcsf(string X, string Y)
{
    int m = X.length();
    int n = Y.length();
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    int index = L[m][n];

    string lcsstring(index, 0);

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i-1] == Y[j-1])
        {
            lcsstring[index-1] = X[i-1];
            i--; j--; index--;
        }
        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }
    return lcsstring;
}

int32_t main()
{
    usecppio
    cin >> str;
    for (auto it:str) ct[it-'a']++;
    for (int i = 0; i<26; i++)
    {
        if (ct[i]>=100)
        {
            for (int j = 0; j<100; j++)
                cout << (char)(i+'a');
            return 0;
        }
    }
    string rev = str;
    reverse(all(rev));
    string lps = lcsf(rev, str);
    if (lps.length() < 100)
        cout << lps << '\n';
    else
    {
        for (int i = 0; i<50; i++) cout << (lps[i]);
        for (int i = 50; i>0; i--) cout << (lps[lps.length()-i]);
    }
}