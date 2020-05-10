#include <bits/stdc++.h>
#define ll long long
#define MAX(A,B) (A)>(B)?(A):(B)
#define MIN(A,B) (A)<(B)?(A):(B)
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
typedef pair<ll,ll> pll;

int arr[302000];
int l, r, s;
int su = 0;
int und;
vector <int> v;
char str[302000];
int acc[302000][3];
int main()
{
   scanf("%d",&s);
   scanf("%s",str+1);
   for (int i = 1; i<=s; i++)
   {
       arr[i] = (str[i] == '(')? 1 : (str[i]==')'?-1:0);
       if (arr[i] == 0)
           v.PB(i);
       if (arr[i] == 1)
           l++;
       else if (arr[i]==-1)
           r++;
       else
           und++;
   }
   if (s%2)
   {
       printf(":(");
       return 0;
   }
   if (s/2 - l > und || s/2-r > und)
   {
       printf(":(");
       return 0;
   }
   if ((s/2-l) + (s/2-r) != und)
   {
       printf(":(");
       return 0;
   }
   for (int i = 0; i<(s/2)-l; i++)
       arr[v[i]] = 1;
   for (int i = (s/2-l); i<und; i++)
       arr[v[i]] = -1;
   for (int i = 1; i<s; i++)
   {
       su += arr[i];
       if (su <= 0)
       {
           printf(":(");
           return 0;
       }
   }
   if (su != 1)
   {
       printf(":(");
       return 0;
   }
   else
   {
       for (int i = 1; i<=s; i++)
       {
           printf("%c",arr[i] == 1 ? '(': ')');
       }
   }
}
