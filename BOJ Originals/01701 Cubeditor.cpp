#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define ll long long
#define int ll
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef pair <int, int> pii;

const ll MOD = 100007;

int L;
char S[202020];
int safemod(int n)
{
    if(n >= 0)
        return n % MOD;
    return ((-n/MOD+1)*MOD + n) % MOD;
}

bool chk(int len)
{
    vector <int> hashmap[MOD];
    int Hash = 0;
    int pp = 1;
    for(int i=0; i<=L-len; i++)
    {
        if(i == 0)
        {
            for(int j = 0; j<len; j++)
            {
                Hash = safemod(Hash + S[len-j-1]*pp);
                if(j < len-1)
                    pp = safemod(pp*2);
            }
        }
        else
            Hash = safemod(2*(Hash - S[i-1]*pp) + S[len+i-1]);

        if(!hashmap[Hash].empty())
        {
            for(auto it:hashmap[Hash])
            {
                bool ck = true;
                for(int j=0; j<len; j++)
                {
                    if(S[i+j] != S[it+j])
                    {
                        ck = false;
                        break;
                    }
                }
                if(ck)
                    return true;
            }
        }
        hashmap[Hash].push_back(i);
    }
    return false;
}
int32_t main()
{
    scanf("%s",S);
    L = strlen(S);
    int lo = 0, hi = L;
    while(lo < hi - 1)
    {
        int mid = (lo + hi)/2;
        if (chk(mid))
            lo = mid;
        else
            hi = mid;
    }
    printf("%lld", lo);

}