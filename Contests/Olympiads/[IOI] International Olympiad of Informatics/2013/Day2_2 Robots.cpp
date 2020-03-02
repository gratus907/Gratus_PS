#include "robots.h"
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
 
struct toy
{
    int w, s, ind;
    void print()
    {
        printf("Toy %d : Weight %d, Size %d\n",ind,w,s);
    }
};
bool by_weight(toy &a, toy &b)
{
    return a.w < b.w;
}
bool by_size(toy &a, toy &b)
{
    return a.s < b.s;
}
vector <toy> toy_w, toy_s;
vector <int> weak;
vector <int> small;
toy all_toy[1010101];
bool took[1010101];
int a, b, t;
const bool debug = false;
priority_queue<pii> pq;
bool check(int x)
{
    memset(took, 0, sizeof(took));
    int pt = 0;
    for (int i = 0; i<a; i++)
    {
        while(pt<t && toy_w[pt].w < weak[i])
        {
            pq.push({toy_w[pt].s, toy_w[pt].ind});
            pt++;
        }
        int gt = 0;
        while(gt<x && !pq.empty())
        {
            took[pq.top().second] = true;
            pq.pop();
            gt++;
        }
    }
    while(pt<t)
    {
        pq.push({toy_w[pt].s, toy_w[pt].ind});
        pt++;
    }
    vector <pii> temp;
    while(!pq.empty())
    {
        temp.push_back(pq.top());
        pq.pop();
    }
    for (int i = 0; i<b; i++)
    {
        int gt = 0;
        while(gt<x && !temp.empty() && temp.back().first < small[i])
        {
            took[temp.back().second] = true;
            temp.pop_back();
            gt++;
        }
    }
    for (int i = 0; i<t; i++)
    {
        if (took[i]==0) return false;
    }
    return true;
}
 
 
int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]) {
    a = A, b = B, t = T;
    for (int i = 0; i<a; i++)
    {
        int x; x = X[i];
        weak.push_back(x);
    }
    for (int i = 0; i<b; i++)
    {
        int x; x = Y[i];
        small.push_back(x);
    }
    sort(all(weak));
    sort(all(small));
    for (int i = 0; i<t; i++)
    {
        int ww, ss;
        ww = W[i], ss = S[i];
        toy_w.push_back({ww, ss, i});
        toy_s.push_back({ww, ss, i});
        all_toy[i] = {ww, ss, i};
    }
    sort(all(toy_w),by_weight);
    sort(all(toy_s),by_size);
    int lo = 1, hi = 1e6+1;
    if (!check(1e6+1))
    {
        return -1;
    }
    while(lo + 1 < hi)
    {
        int mid = (lo + hi)/2;
        if (check(mid))
            hi = mid;
        else lo = mid;
    }
    return (check(lo)?lo:hi);
}