#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
using pii = pair <int, int>;

#define MAXN (1<<18)
#define ST (1<<17)
struct merge_sort_tree
{
    vector <int> tree[MAXN];
    int n;
    void construct (vector <int> data)
    {
        n = 1;
        while(n < data.size()) n <<= 1;
        for (int i = 0; i<data.size(); i++)
            tree[i+n] = {data[i]};
        for (int i = data.size(); i<n; i++)
            tree[i+n] = {};
        for (int i = n-1; i>0; i--)
        {
            tree[i].resize(tree[i*2].size()+tree[i*2+1].size());
            for (int p = 0, q = 0, j = 0; j < tree[i].size(); j++)
            {
                if (p == tree[i*2].size() || (q<tree[i*2+1].size() && tree[i*2+1][q]<tree[i*2][p]))
                    tree[i][j] = tree[i*2+1][q++];
                else tree[i][j] = tree[i*2][p++];
            }
        }
    }
    int greater(int s, int e, int k, int node, int ns, int ne)
    {
        //printf("Queried %d %d %d %d %d %d\n",s,e,k,node,ns,ne);
        if (ne <= s || ns >= e)
            return 0;
        if(s <= ns && ne <= e)
            return tree[node].end() - upper_bound(all(tree[node]), k);
        int mid = (ns+ne)>>1;
        return greater(s,e,k,node*2,ns,mid) + greater(s,e,k,node*2+1,mid,ne);
    }
    int greater(int s, int e, int k)
    {
        //printf("Query %d %d %d\n",s,e,k);
        return greater(s,e,k,1,0,n);
    }

    void print()
    {
        for (int i = 1; i<2*n; i++)
        {
            printf("%d: ",i);
            for (auto it:tree[i])
                printf("%d ",it);
            printf("\n");
        }
    }
};
vector <int> arr;
merge_sort_tree T;
int32_t main()
{
    usecppio
    int n, m;
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    T.construct(arr);
    cin >> m;
    int last_ans = 0;
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int i, j, k;
        i = a^last_ans;
        j = b^last_ans;
        k = c^last_ans;
        last_ans = T.greater(i-1,j,k);
        cout << last_ans << '\n';
    }
}