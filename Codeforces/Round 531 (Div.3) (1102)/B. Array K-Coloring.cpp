#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) A>B?A:B
#define MIN(A,B) (A)<(B)?(A):(B)
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
#define mod 1000000007LL
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int arr[5012];
int occ[5012];
int maxocc;
int maxoccnum;
int distinct;
int main()
{
    int n,k;
    vector <pii> tmp1;
    vector <pii> tmp2;
    scanf("%d%d",&n,&k);
    for (int i = 0; i<n; i++)
    {
        scanf("%d",arr+i);
        occ[arr[i]]++;
        if (occ[arr[i]]==1)
            distinct++;
        if (occ[arr[i]]>maxocc)
        {
            maxocc = occ[arr[i]];
            maxoccnum = arr[i];
        }
    }
    if (maxocc>k)
    {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for (int i = 0; i<n; i++)
        tmp1.PB(MP(arr[i],i));
    sort(tmp1.begin(),tmp1.end());
    for (int i = 0; i<n; i++)
        tmp2.PB(MP(tmp1[i].second,(i%k)+1));
    sort(tmp2.begin(),tmp2.end());
    for (int i = 0; i<n; i++)
        printf("%d ",tmp2[i].second);
}
