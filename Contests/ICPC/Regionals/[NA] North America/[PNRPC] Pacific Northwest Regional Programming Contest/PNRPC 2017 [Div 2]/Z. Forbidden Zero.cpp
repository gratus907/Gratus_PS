#include<bits/stdc++.h>
using namespace std;

int n;

bool check(int x)
{
    string str = to_string(x);
    sort(str.begin(),str.end());
    return (str[0]!='0');
}
int main()
{
    cin >> n;
    n++;
    while(!check(n))
        n++;
    cout << n;
}
close
