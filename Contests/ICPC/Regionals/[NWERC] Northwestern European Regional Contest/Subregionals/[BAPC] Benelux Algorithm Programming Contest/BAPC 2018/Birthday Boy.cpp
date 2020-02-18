#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#define int ll
#define PI acos(-1.0)
using pii = pair<int, int>;

int day_before_month[14] = {0,0,31,59,90,120,151,181,212,243,273,304,334,365};
struct date
{
    int month, day;
    date(int m, int d)
    {
        month = m; day = d;
    }
    date(int x = 1)
    {
        if (x==0)
        {
            month = 12, day = 31; return;
        }
        for (int i = 1; i<=13; i++)
        {
            if (day_before_month[i]>=x)
            {
                month = i-1;
                break;
            }
        }
        day = x-day_before_month[month];
    }
    int to_days()
    {
        return day_before_month[month]+day;
    }
    bool operator<(date &other)
    {
        return to_days() < other.to_days();
    }
    void print()
    {
        printf("%02lld-%02lld ",month,day);
    }
};

vector <date> v;
vector <pair<date, int>> all_gaps;

inline int dt(date &k)
{
    int t = (k.to_days()-date(10, 27).to_days()+365)%365;
    return t?t:365;
}
int32_t main()
{
    int n;
    cin >> n;
    for (int i = 0; i<n; i++)
    {
        string nm, b;
        cin >> nm >> b;
        int mt = (b[0]-'0')*10+(b[1]-'0');
        int dt = (b[3]-'0')*10+(b[4]-'0');
        date curd = date(mt,dt);
        v.push_back(curd);
    }
    sort(all(v));
    v.push_back(date(v[0]));
    for (int i = 1; i<v.size(); i++)
    {
        int t = v[i].to_days()-v[i-1].to_days();
        if (i == v.size()-1)
            t += 365;
        all_gaps.push_back({date((v[i].to_days()-1)), t});
    }
    sort(all(all_gaps), [](pair<date, int> &a, pair<date, int> &b)->bool{return (a.second == b.second) ? dt(a.first) >= dt(b.first) : (a.second < b.second);});
    all_gaps.back().first.print();
    /*for(auto it:all_gaps)
    {
        it.first.print(); printf("%lld\n",it.second);
    }*/
}