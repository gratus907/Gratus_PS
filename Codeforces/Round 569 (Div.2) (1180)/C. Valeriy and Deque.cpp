#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define ll long long
#define int ll
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define gcd(A,B) (__gcd(A,B))
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
#define mod 1000000007LL
#define all(x) x.begin(), x.end()
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int n, q;
deque <int> ordq;
vector <pii> ans;
int repstart = 0;
void oper (deque<int> &todq)
{
    int a = todq.front();
    todq.pop_front();
    int b = todq.front();
    ans.push_back({a,b});
    todq.pop_front();
    todq.push_back(min(a,b));
    todq.push_front(max(a,b));
    return;
}

void print_query(int query)
{

    return;
}
int32_t main()
{
    usecppio
    cin >> n >> q;
    int maxi = INT_MIN;
    for (int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        ordq.push_back(x);
        maxi = MAX(maxi,x);
    }
    bool ck = 1;
    ans.push_back({0,0});
    for (int i = 1; i<202020; i++)
    {
        oper(ordq);
        if (ck && ordq.front()==maxi)
        {
            repstart = i+1;
            ck = 0;
        }
    }
    while(q--)
    {
        int query;
        cin >> query;
        if (query>=repstart)
        {
            int u = (query-repstart);
            int k = (u % (n-1));
            int newquery = repstart + k;
            cout << ans[newquery].first << ' ' << ans[newquery].second << '\n';
        }
        else cout << ans[query].first << ' ' << ans[query].second << '\n';
    }
}
