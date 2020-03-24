#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define ll long long
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define gcd(A,B) __gcd(A,B)
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

pii bintree[36];
int n;
vector <int> pre;
vector <int> mid;
vector <int> post;
int visit[50];
void pvec(vector <int> &v)
{
    for(auto it:v)
    {
        cout<<char(it+'A'-1);
    }
    cout << '\n';
}
int preorder(int r)
{
    pre.PB(r);
    if (bintree[r].first != 0 && visit[bintree[r].first]==0)
    {
        preorder(bintree[r].first);
        visit[bintree[r].first]++;
    }
    if (bintree[r].second != 0 && visit[bintree[r].second]==0)
    {
        preorder(bintree[r].second);
        visit[bintree[r].second]++;
    }
}
int midorder(int r)
{
    if (bintree[r].first != 0 && visit[bintree[r].first]==0)
    {
        midorder(bintree[r].first);
        visit[bintree[r].first]++;
    }
    mid.PB(r);
    if (bintree[r].second != 0 && visit[bintree[r].second]==0)
    {
        midorder(bintree[r].second);
        visit[bintree[r].second]++;
    }
}
int postorder(int r)
{
    if (bintree[r].first != 0 && visit[bintree[r].first]==0)
    {
        postorder(bintree[r].first);
        visit[bintree[r].first]++;
    }
    if (bintree[r].second != 0 && visit[bintree[r].second]==0)
    {
        postorder(bintree[r].second);
        visit[bintree[r].second]++;
    }
    post.PB(r);
}
int main()
{
    cin >> n;
    for (int i = 1; i<=n; i++)
    {
        char name, l, r;
        cin >> name >> l >> r;
        bintree[name-'A'+1].first = (isalpha(l))?(l-'A'+1):(0);
        bintree[name-'A'+1].second = (isalpha(r))?(r-'A'+1):(0);
    }
    preorder(1);
    memset(visit,0,sizeof(visit));
    midorder(1);
    memset(visit,0,sizeof(visit));
    postorder(1);

    pvec(pre);
    pvec(mid);
    pvec(post);

}