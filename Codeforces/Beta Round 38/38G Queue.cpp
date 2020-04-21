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
const bool debug = 1;
using pii = pair<int, int>;
typedef long double D;
int n;
int sn;
struct person
{
    int index;
    int a, c;
};
struct bucket
{
    deque <person> lst;
    priority_queue <int> st;
    int size(){return lst.size();}
    int max_val(){if (st.empty()) return 0;else return st.top();};
};
vector <bucket> Q;
void print_answer()
{
    for (auto it:Q)
        for (auto itt:it.lst)
            cout << itt.index << ' ';
    cout << '\n';
}

void distr()
{
    int qs = Q.size();
    vector <person> lst;
    for (int i = qs-1; i>=0; i--)
    {
        while(Q[i].size())
        {
            lst.push_back(Q[i].lst.back());
            Q[i].lst.pop_back();
            Q[i].st.pop();
        }
    }
    reverse(all(lst));
    for (int i = 0; i < lst.size(); i++)
    {
        Q[i/sn].lst.push_back(lst[i]);
        Q[i/sn].st.push(lst[i].a);
    }
}
void insert(bucket &B, person p)
{
    B.lst.push_back(p);
    B.st.push(p.a);
    int ind = B.size()-1;
    if (ind==0)
        return;
    while(ind>0)
    {
        if (B.lst[ind].a > B.lst[ind-1].a && B.lst[ind].c)
        {
            B.lst[ind].c--;
            swap(B.lst[ind-1],B.lst[ind]);
            ind--;
        }
        else break;
    }
}

int32_t main()
{
    usecppio
    cin >> n;
    sn = 350;
    Q.resize((n/sn)+5);
    for (int i = 1; i<=n; i++)
    {
        int a, c;
        cin >> a >> c;
        person p = {i, a, c};
        int qs = Q.size(), qn = qs-1;
        while(qn > 0 && Q[qn].size()<=p.c && Q[qn].max_val()<p.a)
        {
            p.c -= Q[qn].size();
            qn--;
        }
        insert(Q[qn], p);
        if (i%1000==0)
            distr();
    }
    print_answer();
}