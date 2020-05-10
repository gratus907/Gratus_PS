
 #include <bits/stdc++.h>
#define int ll
#define ll long long
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

using pii = pair<int, int>;

set<int> s;
vector <int> primes;
vector <pii> edgelist;
vector <int> graph[1010];
bool is_prime(int x)
{
    for (int i = 2; i<x; i++)
    {
        if (x%i==0)
            return 0;
    }
    return 1;
}
int32_t main()
{
    usecppio
    int n;
    cin >> n;
    for (int i = 2; i<1020; i++)
    {
        if (is_prime(i))
            primes.push_back(i);
    }
    int edge = 0;
    graph[1].push_back(n);
    graph[n].push_back(1);
    edgelist.push_back({1,n});
    edgelist.push_back({1,2});
    for (int i = 2; i<n; i++)
    {
        graph[i].push_back(i-1);
        graph[i].push_back(i+1);
        edgelist.push_back({i,i+1});
    }
    edge = n;
    for (int i = 1; i<=n; i++)
    {
        s.insert(i);
    }
    int a = 1;
    int b = (a+1)%n+1;
    while(true)
    {
        if (is_prime(edge))
            break;
        else
        {
            while(!(s.count(a) && s.count(b)))
            {
                a++;
                b = (a+1)%n+1;
            }
            graph[a].push_back(b);
            graph[b].push_back(a);
            edgelist.push_back({a,b});
            s.erase(a);
            s.erase(b);
            /*for (auto it:s)
            {
                cout << it << ' ';
            }
            cout << '\n';*/
            edge++;
        }
    }
    cout << edge << '\n';
    for (auto it:edgelist)
    {
        cout << it.first << ' ' << it.second << '\n';
    }
}
