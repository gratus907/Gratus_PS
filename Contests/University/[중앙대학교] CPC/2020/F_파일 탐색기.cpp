#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
using pii = pair<int, int>;
void print(vector<string> &v)
{
    for (auto s : v)
        cout << s << ' ';
    cout << '\n';
}
bool isNumber(char &c) {return c <= '9';}
bool isNumber(string &str) {return isNumber(str[0]);}
string trimZero(string &str)
{
    string s;
    bool flag = false;
    for (auto c : str)
    {
        if (c == '0' && !flag)
        {
            continue;
        }
        else
        {
            flag = true;
            s.push_back(c);
        }
    }
    return s;
}
int cmpNumber(string &A, string &B)
{
    //printf("%s %s\n",A.c_str(), B.c_str());
    if (A == B) return 0;
    string At = trimZero(A);
    string Bt = trimZero(B);
    if (At.length() == Bt.length())
    {
        if (At == Bt)
            return (A.length() < B.length())?1:-1;
        return (At < Bt)?1:-1;
    }
    else
        return (At.length() < Bt.length())?1:-1;
}
bool cmp(vector<string> v1, vector<string> v2)
{
    int sz = min(v1.size(), v2.size());
    for (int i = 0; i < sz; i++)
    {
        bool n1, n2;
        n1 = isNumber(v1[i]);
        n2 = isNumber(v2[i]);
        if (n1 && !n2) return true;
        else if (!n1 && n2) return false;
        else if (n1 && n2)
        {
            int x = cmpNumber(v1[i], v2[i]);
            if (x == 0) continue;
            else return x > 0;
        }
        else
        {
            double c1 = v1[i][0];
            double c2 = v2[i][0];
            if (c1 >= 'a')
            {
                c1 -= 'a';
                c1 += 0.5;
            }
            else c1 -= 'A';
            if (c2 >= 'a')
            {
                c2 -= 'a';
                c2 += 0.5;
            }
            else c2 -= 'A';
            if (c1 == c2) continue;
            else return c1 < c2;
        }
    }
    return v1.size() < v2.size();
}
vector<string> parse(string &str)
{
    vector<string> v;
    string tmp;
    for (char c : str)
    {
        if (isNumber(c)) tmp.push_back(c);
        else
        {
            if (!tmp.empty()) v.push_back(tmp);
            tmp.clear();
            tmp.push_back(c);
            v.push_back(tmp); tmp.clear();
        }
    }
    if (!tmp.empty()) v.push_back(tmp);
    return v;
}

vector<vector<string>> vt;
int32_t main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<string> tmp;
        string str; cin >> str;
        tmp = parse(str);
        vt.push_back(tmp);
    }
    sort(all(vt), cmp);
    for (auto v : vt)
    {
        for (auto s : v)
            cout << s;
        cout << '\n';
    }
}