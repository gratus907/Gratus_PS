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
#define usecppio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

lli arr[202000];
char str[202000];
int main()
{
    usecppio
    lli n, k;
    cin >> n >> k;
    for (int i = 0; i<n; i++)
        cin >> arr[i];
    cin >> str;
    lli dmg = 0;
    char cur = 'A';
    vector <lli> tmp;
    for (int i = 0; i<n; i++)
    {
        if (cur == str[i])
            tmp.PB(arr[i]);
        else
        {
            sort(tmp.begin(), tmp.end(), greater<int>());
            int u = (int) tmp.size();
            int cr = MIN(u,k);
            for (int j = 0; j < cr; j++)
                dmg += tmp[j];
            tmp.clear();
            cur = str[i];
            tmp.PB(arr[i]);
        }
    }
    sort(tmp.begin(), tmp.end(), greater<int>());
    int u = (int) tmp.size();
    int cr = MIN(u,k);
    for (int j = 0; j < cr; j++)
        dmg += tmp[j];
    cout << dmg << '\n';
}
