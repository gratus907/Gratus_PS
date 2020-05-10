#include <bits/stdc++.h>
using namespace std;

int x = 0;
int arr[105];
int c = 0;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i<n; i++)
    {
        if (x <= m)
        {
            x += arr[i];
            c++;
        }
    }
    if (x<=m)
        c++;
    printf("%d",c);
}
