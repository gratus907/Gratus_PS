#include <bits/stdc++.h>
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

int num_by_len_dig[11];
int arr[101010];
int conseg[11];
int32_t main()
{
    int m = 998244353LL;
    int val = 0;
    usecppio
    int n;
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        cin >> arr[i];
        num_by_len_dig[(int)(log10(arr[i]))+1]++;
    }
    for (int i = 0; i<n; i++)
    {
        for (int x = 1; x<=10; x++)
        {
            int u = 1;
            if (num_by_len_dig[x]==0)
                continue;
            int tmptmp = arr[i];
            if (x>=(int)(log10(arr[i]))+1)
            {
                while(arr[i]>0)
                {
                    ll t = arr[i]%10;
                    arr[i]/=10;
                    val+=(t*u)*num_by_len_dig[x];
                    val%=m;
                    u*=10;
                    u%=m;
                    val+=(t*u)*num_by_len_dig[x];
                    val%=m;
                    u*=10;
                    u%=m;
                }
            }
            else
            {
                int d = 0;
                while(arr[i]>0)
                {
                    d++;
                    if (d<=x)
                    {
                        ll t = arr[i]%10;
                        arr[i]/=10;
                        val+=(t*u)*num_by_len_dig[x];
                        val%=m;
                        u*=10;
                        u%=m;
                        val+=(t*u)*num_by_len_dig[x];
                        val%=m;
                        u*=10;
                        u%=m;
                    }
                    else
                    {
                        ll t = arr[i]%10;
                        arr[i]/=10;
                        val+=(t*u)*num_by_len_dig[x];
                        val%=m;
                        val+=(t*u)*num_by_len_dig[x];
                        val%=m;
                        u*=10;
                        u%=m;
                    }
                }
            }
            arr[i] = tmptmp;
            //cout << val%m << '\n';
        }

    }
    cout << val%m;
}
