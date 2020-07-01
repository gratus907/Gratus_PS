#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll

// Code for Teamnote - Uncorrected
class FenwickTree
{
public:
    int ft[5050][5050];
    int LSB(int x){
        return x & (-x);
    }
    int query(int x, int y){
        int sum = 0;
        for(int x_ = x; x_ > 0; x_ = x_ - LSB(x_)){
            for(int y_ = y; y_ > 0; y_ = y_ - LSB(y_)){
                sum = sum + ft[x_][y_];
            }
        }
        return sum;
    }
    int query(int x1, int y1, int x2, int y2){
        return (query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1));
    }
    void update(int x, int y, int value){
        for(int x_ = x; x_ < 5020; x_ = x_ + LSB(x_)){
            for(int y_ = y; y_ < 5020; y_ = y_ + LSB(y_)){
                ft[x_][y_] += value;
            }
        }
    }
};
// DO NOT TOUCH HERE!

FenwickTree FW;
int32_t main()
{
    usecppio
    int n, m, q;
    cin >> n >> m >> q;
    while(q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x1, x2, y1, y2, d;
            cin >> x1 >> y1 >> x2 >> y2 >> d;
            FW.update(x1, y1, d);
            FW.update(x1, y2+1, -d);
            FW.update(x2+1, y2+1, d);
            FW.update(x2+1, y1, -d);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << FW.query(x, y) << '\n';
        } 
    }
}