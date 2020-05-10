#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define ll long long
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
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


void vpo(int occ[], vector <int> &v)
{
    for (auto it:v)
        for (int i = 0; i<occ[it]; i++)
            printf("%c",it+'a');
    printf("\n");
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int tc = 0; tc<T; tc++)
    {
        char sstr[120];
        scanf(" %s",sstr);
        vector <int> v;
        vector <int> vv;
        int occ[26];
        memset(occ,0,sizeof(occ));
        int len;
        len = strlen(sstr);
        for (int i = 0; i<len; i++)
        {
            if (occ[sstr[i]-'a'] == 0)
            {
                v.push_back(sstr[i]-'a');
            }
            occ[sstr[i]-'a']++;
        }
        sort(all(v));
        int ss = v.size();
        if (ss==1)
        {
            vv.PB(v[0]);
            vpo(occ,v);
            continue;
        }
        if (ss==2)
        {
            if (v[1]-v[0]==1)
            {
                printf("No answer\n");
                continue;
            }
            else
            {
                vv.PB(v[0]);
                vv.PB(v[1]);
                vpo(occ,v);
                continue;
            }
        }
        if (ss==3)
        {
            if (v[1]-v[0] == 1)
            {
                if (v[2] - v[1] == 1)
                {
                    printf("No answer\n");
                    continue;
                }
                else
                {
                    vv.PB(v[1]);
                    vv.PB(v[2]);
                    vv.PB(v[0]);
                }
            }
            else
            {
                vv.push_back(v[1]);
                vv.PB(v[0]);
                vv.PB(v[2]);
            }
        }
        else
        {
            for (int i = ss-2; i>=0; i-=2)
                vv.PB(v[i]);
            for (int i = ss-1; i>=0; i-=2)
                vv.PB(v[i]);
        }
        vpo(occ,vv);
    }
}
