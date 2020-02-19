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
struct Point
{
    double x, y;
};
inline double is_left(Point p0, Point p1, Point p2)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
bool is_in_polygon(Point p, vector<Point>& poly)
{
    int wn = 0;
    for (int i = 0; i < poly.size(); ++i)
    {
        int ni = (i + 1 == poly.size()) ? 0 : i + 1;
        if (poly[i].y <= p.y)
        {
            if (poly[ni].y > p.y)
                if (is_left(poly[i], poly[ni], p) > 0)
                    ++wn;
        }
        else
        {
            if (poly[ni].y <= p.y)
                if (is_left(poly[i], poly[ni], p) < 0)
                    --wn;
        }
    }
    return wn != 0;
}
struct matrix
{
    double mat[3][3];
    matrix()
    {
        for (int i = 0; i<3; i++) for (int j = 0; j<3; j++) mat[i][j] = 0;
        mat[0][0] = mat[1][1] = mat[2][2] = 1;
    }
    matrix(double a, double b, double c, double d)
    {
        for (int i = 0; i<3; i++) for (int j = 0; j<3; j++) mat[i][j] = 0;
        mat[0][0] = mat[1][1] = mat[2][2] = 1;
        mat[0][0] = a;
        mat[0][1] = b;
        mat[1][0] = c;
        mat[1][1] = d;
    }
    double det()
    {
        matrix submata(mat[1][1],mat[1][2],mat[2][1],mat[2][2]);
        matrix submatb(mat[1][0],mat[1][2],mat[2][0],mat[2][2]);
        matrix submatc(mat[1][0],mat[1][1],mat[2][0],mat[2][1]);
        double a = mat[0][0]*submata.det22();
        double b = mat[0][1]*submatb.det22();
        double c = mat[0][2]*submatc.det22();
        return a-b+c;
    }
    double det22()
    {
        return mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
    }
    void switch_col(int x, double a, double b, double c)
    {
        mat[0][x] = a;
        mat[1][x] = b;
        mat[2][x] = c;
    }
};
vector <Point> v;
vector <double> ans;
int n;
double xp, yp;
int32_t main()
{
    cin >> n >> xp >> yp;
    for (int i = 0; i<n; i++)
    {
        double xt, yt;
        cin >> xt >> yt;
        v.push_back({xt-xp,yt-yp});
    }
    int a = 0, b = 1, c = 2;
    for (int i = 0; i<n; i++)
    {
        for (int j = i+1; j<n; j++)
        {
            for (int k = j+1; k<n; k++)
            {
                vector <Point> vv = {v[i], v[j], v[k]};
                if (is_in_polygon({0, 0}, vv))
                {
                    a = i, b = j, c = k;
                }
            }
        }
    }
    matrix solve_mat;
    solve_mat = matrix(v[a].x,v[b].x,v[a].y,v[b].y);
    solve_mat.mat[0][2] = v[c].x;
    solve_mat.mat[1][2] = v[c].y;
    solve_mat.mat[2][0] = solve_mat.mat[2][1] = solve_mat.mat[2][2] = 1;
    matrix sub_a = solve_mat;
    matrix sub_b = solve_mat;
    matrix sub_c = solve_mat;
    sub_a.switch_col(0,0,0,1);
    sub_b.switch_col(1,0,0,1);
    sub_c.switch_col(2,0,0,1);
    double as = sub_a.det()/solve_mat.det();
    double bs = sub_b.det()/solve_mat.det();
    double cs = sub_c.det()/solve_mat.det();
    ans.resize(n);
    for (int i = 0; i<n; i++) ans[i] = 0;
    ans[a] = as; ans[b] = bs; ans[c] = cs;
    for (auto it:ans)
        cout << fixed << setprecision(15) << it << '\n';
}