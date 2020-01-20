#include <bits/stdc++.h>
using namespace std;
#define ll long long
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin()),((x).end())
#define MOD 1000000007
using pii = pair <int, int>;

int n;
int arr[1010];
int orig[1010];
int su;
vector <int> reff;
bool is_possible(int f)
{
    vector <int> v;
    v.push_back(f);
    for (int i = 1; i<n; i++)
        v.push_back(arr[i]-v.back());
    /*printf("Try with %d\n",f);
    for (auto it:v)
    {
        printf("%d ",it);
    }
    printf("\n");*/
    sort(all(v));
    return v == reff;
}
int32_t main()
{
    ifstream fin("photo.in");
    ofstream fout("photo.out");
    fin >> n;
    for (int i = 1; i<=n; i++) reff.push_back(i);
    for (int i = 1; i<n; i++)
    {
        fin >> arr[i];
        su += arr[i];
    }
    int t = n*(n+1)-su;
    for (int i = 1; i<t; i++)
    {
        if (is_possible(i))
        {
            orig[1] = i;
            break;
        }
    }
    for (int i = 2; i<=n; i++)
    {
        orig[i] = arr[i-1] - orig[i-1];
    }
    for (int i = 1; i<n; i++)
        fout << orig[i] << ' ';
    fout << orig[n];
}
