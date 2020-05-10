#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define ll long long
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
typedef pair<char,int> pci;
string str1;
string str2;
string tmp;
vector <pci> v;
vector <pci> v2;
int main()
{
    usecppio
    int n;
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        v.clear();
        v2.clear();
        str1.clear();
        tmp.clear();
        cin >> str1 >>tmp;
        int s1 = str1.size();
        int s2 = tmp.size();
        v.push_back({str1[0],1});
        for (int j = 1; j<s1; j++)
        {
            if (v.back().first==str1[j])
            {
                v.back().second++;
            }
            else
            {
                v.push_back({str1[j],1});
            }
        }

        v2.push_back({tmp[0],1});
        for (int j = 1; j<s2; j++)
        {
            if (v2.back().first==tmp[j])
            {
                v2.back().second++;
            }
            else
            {
                v2.push_back({tmp[j],1});
            }
        }

        int vs1 = v.size();
        int vs2 = v2.size();
        if (vs1!=vs2)
        {
            cout << "NO\n";
            continue;
        }

        bool flag = true;
        for (int k = 0; k<vs1; k++)
        {
            if (v[k].first==v2[k].first)
            {
                if (v[k].second<=v2[k].second)
                {
                    continue;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (!flag)
        {
            cout << "NO\n";
            continue;
        }
        cout <<"YES\n";
    }

}
