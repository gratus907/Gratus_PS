#include <bits/stdc++.h>
#define ll long long
using namespace std;

int group[13] = {0,1,3,1,2,1,2,1,1,2,1,2,1};
int main()
{
    int x, y;
    cin >> x >> y;
    printf("%s",group[x] == group[y]? "Yes":"No");
}
