#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, arr[303030];
ll leftsum[303030], rightsum[303030];
ll ans = LLONG_MIN;
priority_queue <int, vector<int>, greater<int>> pq;
priority_queue <int> pq2;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 3 * n; i++)
        scanf("%d", &arr[i]);
    for (int i = 1; i <= n; i++)
    {
        leftsum[n] += arr[i];
        pq.push(arr[i]);
    }
    for (int i = n + 1; i <= 2 * n; i++)
    {
        int x = pq.top();
        if (arr[i] - x > 0)
        {
            leftsum[i] = leftsum[i - 1] + arr[i] - x;
            pq.pop();
            pq.push(arr[i]);
        }
        else
            leftsum[i] = leftsum[i - 1];
    }
    for (int i = 2*n+1; i <= 3*n; i++)
    {
        rightsum[2*n+1] += arr[i];
        pq2.push(arr[i]);
    }
    for (int i = 2 * n; i >= n + 1; i--)
    {
        int x = pq2.top();
        if (arr[i] - x < 0)
        {
            rightsum[i] = rightsum[i + 1] + arr[i] - x;
            pq2.pop();
            pq2.push(arr[i]);
        }
        else
            rightsum[i] = rightsum[i + 1];
    }
    for (int i = n; i <= 2 * n; i++)
        ans = max(ans, leftsum[i] - rightsum[i + 1]);
    printf("%lld", ans);
}
