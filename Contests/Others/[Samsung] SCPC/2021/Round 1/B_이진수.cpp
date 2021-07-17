#include <bits/stdc++.h>
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;

char s[50505];
void solve() {
    vector <bool> A, B, fix;
    int n, t; scanf("%d %d",&n,&t);
    A.resize(n + 5);
    B.resize(n + 5);
    fix.resize(n + 5);
    scanf(" %s",s);
    for (int i = 1; i <= n; i++) {
        B[i] = (s[i-1]=='1'?1:0);
    }
    for (int i = 1; i <= n; i++) {
        if (!B[i]) {
            if (i > t) {
                A[i - t] = 0;
                fix[i - t] = 1;
            }
            if (i <= n - t) {
                A[i + t] = 0;
                fix[i + t] = 1;
            }
        }
    }
    for (int i = 1; i <= t; i++) {
        if (B[i]) {
            if (!A[i + t]) {
                A[i + t] = 1;
                fix[i + t] = 1;
            }
        }
    }
    for (int i = n - t + 1; i <= n; i++) {
        if (B[i]) {
            if (!A[i - t]) {
                A[i - t] = 1;
                fix[i - t] = 1;
            }
        }
    }
    for (int i = t + 1; i <= n - t; i++) {
        if (B[i]) {
            if (A[i - t] || A[i + t]) continue;
            else {
                if (!fix[i + t]) {
                    A[i + t] = 1;
                    fix[i + t] = 1;
                }
                else {
                    A[i - t] = 1;
                    fix[i - t] = 1;
                }
            }
        }
    }
    string str;
    
    for (int i = 1; i <= n; i++) {
        str.push_back(A[i]?'1':'0');
    }
    printf("%s\n",str.c_str());
}
int32_t main()
{
    int T, test_case;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for(test_case = 0; test_case < T; test_case++)
    {
        printf("Case #%d\n", test_case+1);
        solve();
    }
    return 0;
}