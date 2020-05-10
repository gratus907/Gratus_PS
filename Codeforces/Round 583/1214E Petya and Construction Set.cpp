#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using pii = pair<int, int>;
int d[101010];
int n;

deque <int> longest_chain;
vector <pii> v;
void printedge(int a, int b)
{
    cout << a << ' ' << b << '\n';
}
int main()
{
    usecppio
    cin >> n;
    int lcl = n;
    for (int i = 1; i<=n; i++)
    {
        cin >> d[i];
        v.push_back({d[i], i});
    }        
    sort(all(v),greater<pii>());
    for (int i = 0; i<n; i++)
    {
        longest_chain.push_back(2*v[i].second-1);
    }    
    for (int i = 0; i<n-1; i++)
    {
        printedge(longest_chain[i],longest_chain[i+1]);
    }
    for (int i = 0; i<n; i++)
    {
        if (v[i].first == lcl-i)
        {
            longest_chain.push_back(2*v[i].second);
            lcl++;
            printedge(longest_chain[lcl-2],longest_chain[lcl-1]);
        }
        else
        {
            int dis = v[i].first;
            int targ = longest_chain[i+dis-1];
            printedge(targ,2*v[i].second);
        }
    }
}