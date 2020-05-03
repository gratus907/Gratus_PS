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

const int MAX_NODES = 26;
inline int getnext(char x)
{
    return x-'a';
}
struct Trie
{
    Trie *next[MAX_NODES];
    int cnt;
    bool ends;
    Trie()
    {
        fill(next, next+MAX_NODES, nullptr);
        cnt = ends = 0;
    }
    ~Trie()
    {
        for (auto &it:next)
            if (it) delete it;
    }
    void insert(char *str)
    {
        if (*str==0)
            ends = true;
        else
        {
            int nxt = getnext(*str);
            if (!next[nxt])
            {
                next[nxt] = new Trie();
                cnt++;
            }
            next[nxt]->insert(str+1);
        }
    }
    int query(char* str, int k)
    {
        if (*str == 0)
            return k;
        else
        {
            if (cnt > 1 || ends)
                k++;
            int nxt = getnext(*str);
            return next[nxt]->query(str+1, k);
        }
    }
};

char strs[101010][100];
int32_t main()
{
    int n;
    while(scanf("%lld",&n)!=EOF)
    {
        Trie TR;
        for (int i = 0; i<n; i++)
        {
            scanf("%s", strs[i]);
            TR.insert(strs[i]);
        }
        int cnt = 0;
        for (int i = 0; i<n; i++)
            cnt += TR.query(strs[i], 0);
        if (TR.cnt==1) cnt+=n;
        printf("%.2lf\n", cnt*1.0 / n);
    }
}