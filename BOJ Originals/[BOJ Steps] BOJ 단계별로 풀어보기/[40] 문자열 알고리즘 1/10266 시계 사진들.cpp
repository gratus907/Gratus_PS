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

vector <int> A(720000,0),B(360000,0);
int ar[404040], br[404040];
vector<int> getPi(vector <int> &p)
{
    int j = 0;
    int plen = p.size();
    vector<int> pi;
    pi.resize(plen);
    for(int i = 1; i< plen; i++)
    {
        while((j > 0) && (p[i] !=  p[j]))
            j = pi[j-1];
        if(p[i] == p[j])
        {
            j++;
            pi[i] = j;
        }
    }
    return pi;
}
vector <int> kmp(vector <int> &s, vector <int> &p)
{
    vector<int> ans;
    auto pi = getPi(p);
    int slen = s.size(), plen = p.size(), j = 0;
    for(int i = 0 ; i < slen ; i++)
    {
        while(j>0 && s[i] != p[j])
            j = pi[j-1];
        if(s[i] == p[j])
        {
            if(j==plen-1)
            {
                ans.push_back(i-plen+1);
                j = pi[j];
            }
            else
                j++;
        }
    }
    return ans;
}

int32_t main()
{
    usecppio
    int n; cin >> n;
    for (int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        ar[x] = 1;
    }
    for (int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        br[x] = 1;
    }
    for (int i = 0; i<360000; i++)
    {
        if (ar[i]) A[i] = A[i+360000] = 1;
        if (br[i]) B[i] = 1;
    }
    vector<int> occ = kmp(A, B);
    cout << (occ.empty()?"impossible":"possible") << '\n';
}