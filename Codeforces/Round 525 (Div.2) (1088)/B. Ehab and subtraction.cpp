#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) A>B?A:B
#define MIN(A,B) A<B?A:B
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int arr[102000];
int newarr[102000];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i = 0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        arr[i] = x;
    }
    sort(arr,arr+n);
    int tmp = 1;
    newarr[0] = arr[0];
    for (int i = 1; i<n; i++)
    {
        if (arr[i] != newarr[tmp-1])
        {
            newarr[tmp] = arr[i];
            tmp++;
        }
    }
    printf("%d\n",newarr[0]);
    for (int i = 1; i<k; i++)
    {
        if (i>=tmp)
            printf("0\n");
        else
            printf("%d\n",newarr[i]-newarr[i-1]);
    }
}
