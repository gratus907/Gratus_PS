#include <bits/stdc++.h>
#define ll long long
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define mod 1000000007LL
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,long double> pid;

vector <pii> matched_pair;
queue <int> aocc[27];
queue <int> bocc[27];
int n;
char a[152000], b[152000];
void parse_string(char *str, queue<int> *target)
{
    for (int i = 0; i<n; i++)
    {
        char c = str[i];
        if ('a'<= c && c <= 'z')
            target[c-'a'].push(i);
        else
            target[26].push(i);
    }
}
int main()
{
    scanf("%d",&n);
    scanf("%s",a);
    scanf("%s",b);
    parse_string(a,aocc);
    parse_string(b,bocc);
    int ind = 0;
    while(ind < 26)
    {
        while(!(aocc[ind].empty() || bocc[ind].empty()))
        {
            int x = aocc[ind].front();
            int y = bocc[ind].front();
            matched_pair.PB(MP(x,y));
            aocc[ind].pop();
            bocc[ind].pop();
        }
        ind++;
    }
    ind = 0;
    while(ind < 27)
    {
        while(!(aocc[26].empty() || bocc[ind].empty()))
        {
            int x = aocc[26].front();
            int y = bocc[ind].front();
            matched_pair.PB(MP(x,y));
            aocc[26].pop();
            bocc[ind].pop();
        }
        ind++;
    }
    ind = 0;
    while(ind < 27)
    {
        while(!(aocc[ind].empty() || bocc[26].empty()))
        {
            int x = aocc[ind].front();
            int y = bocc[26].front();
            matched_pair.PB(MP(x,y));
            aocc[ind].pop();
            bocc[26].pop();
        }
        ind++;
    }
    int ss = (int)matched_pair.size();
    printf("%d\n",ss);
    for (int i = 0; i<ss; i++)
    {
        printf("%d %d\n",matched_pair[i].first+1,matched_pair[i].second+1);
    }
}
