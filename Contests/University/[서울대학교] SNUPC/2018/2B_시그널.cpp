#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#define ll long long
#define gcd(A,B) (__gcd(A,B))
using namespace std;

typedef pair <int, int> pii;

bool signals[5][20100];
bool w[20100];
char raw[101010];
vector <int> converted_signal;

int convert(int x)
{
    string str="";
    for (int i = 0; i<5; i++)
        for (int j = x; j<x+3; j++)
            str += signals[i][j]?"1":"0";
    if (str == "111101101101111")
        return 0;
    if (str == "111001111100111")
        return 2;
    if (str == "111001111001111")
        return 3;
    if (str == "101101111001001")
        return 4;
    if (str == "111100111001111")
        return 5;
    if (str == "111100111101111")
        return 6;
    if (str == "111001001001001")
        return 7;
    if (str == "111101111101111")
        return 8;
    if (str == "111101111001111")
        return 9;
}

int main()
{
    int n;
    scanf("%d",&n);
    int t = n/5;
    scanf("%s",raw);
    for (int i = 0; i<5; i++)
        for (int j = 0; j<t; j++)
            signals[i][j] = (raw[i*t+j]=='#');
    for (int i = 0; i<t; i++)
        w[i] = (signals[0][i] || signals[2][i]);
    int u = 0;
    while(u<t)
    {
        if (w[u])
        {
            if (w[u+1])
            {
                converted_signal.push_back(convert(u));
                u+=3;
            }
            else
            {
                converted_signal.push_back(1);
                u++;
            }
        }
        else
            u++;
    }
    for (auto it:converted_signal)
        printf("%d",it);
}