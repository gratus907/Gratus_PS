#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) (A)>(B)?(A):(B)
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

char s[1200];
char t[1200];

int is_vowel(char x)
{
    if (x=='a'||x=='e'||x=='i'||x=='o'||x=='u')
        return 1;
    return 0;
}

int main()
{
    scanf("%s",s);
    scanf("%s",t);
    if (strlen(s)!=strlen(t))
    {
        printf("No");
        return 0;
    }
    int l = strlen(s);
    for (int i = 0; i<l; i++)
    {
        if (is_vowel(s[i])!=is_vowel(t[i]))
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
}
