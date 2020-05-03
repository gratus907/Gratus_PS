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
struct Trie
{
    map<string, Trie> next;
};

void insert(Trie &T, vector<string> &arr, int idx)
{
    if(idx == arr.size())
        return;
    if(T.next.find(arr[idx])==T.next.end())
        T.next[arr[idx]] = Trie();
    insert(T.next[arr[idx]], arr, idx+1);
}
void print(Trie &T, int d)
{
    for(auto it:T.next)
    {
        for (int i = 0; i<d; i++)
            cout << "--";
        cout << it.first << "\n";
        print(it.second, d+1);
    }
}
vector <string> strs;
Trie TR;
int32_t main()
{
    usecppio
    int n; cin >> n;
    for (int i = 0; i<n; i++)
    {
        strs.clear();
        int k; cin >> k;
        for (int j = 0; j<k; j++)
        {
            string s; cin >> s;
            strs.push_back(s);
        }
        insert(TR, strs, 0);
    }
    print(TR, 0);
}