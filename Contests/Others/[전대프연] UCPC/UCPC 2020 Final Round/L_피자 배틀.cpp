#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int dp[2][1020][1020][120]; // 0: silver's turn , 1: bronze's turn, dp: silver - bronze
// silver: k-0.5, bronze: k-0.5
int arr[1020];
int main() {
    int N, sum = 0;
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",arr+i);
        for(int j=1; j<=100; j++) {
            dp[0][i][i][j] = arr[i];
            dp[1][i][i][j] = -arr[i];
        }
        sum+=arr[i];
    }
    for(int i=1; i<N-1; i++) {
        for(int j=0; j<N; j++) {
            for(int k=1; k<=100; k++) {
                int x = j, y = (j+i)%N,a,b;
                if(arr[x]>=k) {
                    a = dp[1][(x+1)%N][y][arr[x]-k+1];
                }
                else {
                    a = dp[0][(x+1)%N][y][k-arr[x]];
                }
                if(arr[y]>=k) {
                    b = dp[1][x][(y-1+N)%N][arr[y]-k+1];
                }
                else {
                    b = dp[0][x][(y-1+N)%N][k-arr[y]];
                }
                dp[0][x][y][k] = max(a+arr[x],b+arr[y]);
                if(arr[x]>=k) {
                    a = dp[0][(x+1)%N][y][arr[x]-k+1];
                }
                else {
                    a = dp[1][(x+1)%N][y][k-arr[x]];
                }
                if(arr[y]>=k) {
                    b = dp[0][x][(y-1+N)%N][arr[y]-k+1];
                }
                else {
                    b = dp[1][x][(y-1+N)%N][k-arr[y]];
                }
                dp[1][x][y][k] = min(a-arr[x],b-arr[y]);
            }
        }
    }
    int maxi = -INT_MAX;
    for(int i=0; i<N; i++) {
        int val = arr[i];
        //printf("%d %d %d\n",(i+1)%N,(i+N-1)%N,dp[1][(i+1)%N][(i+N-1)%N][arr[i]]);
        maxi = max(dp[1][(i+1)%N][(i+N-1)%N][arr[i]]+val, maxi);
    }
    if(N==1) {
        printf("%d",arr[0]);
    }
    //printf("print: %d\n",dp[1][2][3][1]);
    else {
        printf("%d",(sum+maxi)/2);
    }
}