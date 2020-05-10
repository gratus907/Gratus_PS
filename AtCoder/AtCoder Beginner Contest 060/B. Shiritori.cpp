#include <bits/stdc++.h>
using namespace std;

int a,b,c;
int main()
{
    cin >> a >> b >> c;
    for (int i = 0; i<=10000; i++)
    {
        if ((a*i)%b == c)
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}
