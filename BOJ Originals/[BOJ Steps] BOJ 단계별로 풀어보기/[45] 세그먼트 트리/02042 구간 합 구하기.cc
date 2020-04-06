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

int arr[1010101];
int tree[4040404];
int makeTree(int left,int right,int node)
{
    if (left == right)
        return tree[node] = arr[left];
    int mid = (left + right) / 2;
    tree[node] += makeTree(left, mid, node * 2);
    tree[node] += makeTree(mid + 1,right, node * 2 +1);
    return tree[node];
}

void update(int left,int right, int node, int change_node ,int diff)
{
    if (!(left <= change_node &&change_node <= right))
        return; //No effect on such nodes.
    tree[node] += diff; // This part must be changed with tree function.
    if (left != right)
    {
        int mid = (left + right) / 2;
        update(left, mid, node * 2, change_node, diff);
        update(mid +1,right, node * 2 +1, change_node, diff);
    }
}

int Query(int node, int left, int right, int start, int end)
{
    if (right < start || end < left)
        return 0; //Node is out of range
    if (start <= left && right <= end)
        return tree[node]; //If node is completely in range
    int mid = (left + right) / 2;
    return Query(node * 2, left, mid, start, end)+Query(node*2+1,mid+1,right,start,end);
}

int32_t main()
{
    usecppio
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 0; i<n; i++)
    {
        cin >> arr[i+1];
    }
    makeTree(1,n,1);
    for (int i = 0; i<(m+k); i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a==1)
        {
            int dif = c-arr[b];
            arr[b] = c;
            update(1,n,1,b,dif);
        }
        else
        {
            cout << Query(1,1,n,b,c)<<'\n';
        }
    }
}
