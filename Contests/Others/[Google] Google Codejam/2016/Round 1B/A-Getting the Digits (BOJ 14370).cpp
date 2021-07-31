#include <bits/stdc++.h>
#define ll long long
#define int ll
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
bool dbg = 0;

int mat[26][10];
int matT[10][26];
int A[10][10];
int vec[10];
int res[26];
int b[10];
double aug[10][11], x[10];
string nstr[10] = {
    "ZERO", "ONE", "TWO", "THREE", "FOUR",
    "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};
int32_t main() {
    int T; cin >> T;
    for (int j = 0; j < 10; j++) {
        for (char c : nstr[j]) {
            mat[c-'A'][j]++;
            matT[j][c-'A']++;
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int k = 0; k < 10; k++) {
            for (int j = 0; j < 26; j++) {
                A[i][k] += matT[i][j] * mat[j][k];
            }
        }
    }
    int tc = 0;
    while(T--) {
        tc++;
        memset(vec, 0, sizeof(vec));
        memset(res, 0, sizeof(res));
        memset(b, 0, sizeof(b));
        string s; cin >> s;
        for (char c : s) {
            res[c-'A']++;
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 26; j++) {
                b[i] += matT[i][j] * res[j];
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                aug[i][j] = 1.0 * A[i][j];
            }
            aug[i][10] = b[i];
        }
        for (int i = 0; i < 10; i++) {
            for (int j = i+1; j < 10; j++) {
                double w = aug[j][i] / aug[i][i];
                for (int k = 0; k < 11; k++) {
                    aug[j][k] -= aug[i][k] * w;
                }
            }
        }
        for (int i = 9; i >= 0; i--) {
            x[i] = aug[i][10] / aug[i][i];
            for (int j = i-1; j >= 0; j--) {
                aug[j][10] -= aug[j][i] * x[i];
                aug[j][i] = 0;
            }
        }
        printf("Case #%d: ",tc);
        for (int i = 0; i < 10; i++) {
            int oi = (int)(round(x[i]) + eps);
            for (int j = 0; j < oi; j++)
                printf("%d",i);
        }
        printf("\n");
    }
}