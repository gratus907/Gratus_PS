#include <bits/stdc++.h>
#define int ll
#define ll long long
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;

int n, m;
struct group {
    int l2, l3, l4, l5, l6;
    vector <int> stress;
    void tidy() {
        sort(all(stress));
        l2 = stress[0] + stress[1];
        l3 = 2 * stress[0] + stress[1];
        l4 = stress[0] + stress[1] + stress[2] + stress[3];
        l5 = 2 * stress[0] + stress[1] + stress[2] + stress[3];
        l6 = 2 * stress[0] + 2 * stress[1] + stress[2] + stress[3];
    }
    int es() {
        return stress.size()%2?INT_MAX:l2 - l4;
    }
    int os() {
        return stress.size()%2?l3 - l5:INT_MAX;
    }
    int sc() {
        return stress.size()%2?os():es();
    }
    int val() {
        return stress.size()%2?l5:l4;
    }
};
int solve() {
    int ans = 0;
    int even = 0, odd = 0;
    cin >> n >> m;
    vector <group> groups;
    for (int i = 0; i < n; i++) {
        int l; cin >> l;
        group g;
        for (int j = 0; j < l; j++) {
            int x; cin >> x;
            g.stress.push_back(x);
        }
        g.tidy();
        groups.push_back(g);
        if (g.stress.size()%2 == 0) even++;
        else odd++;
    }
    if (odd == 0 || even == 0 || (odd >= 4 and even > 0)){
        sort(all(groups),[](group &g1, group &g2) -> bool {
            return g1.sc() < g2.sc();
        });
        for (int i = 0; i < n; i++) {
            ans += groups[i].val();
        }
        ans += groups[0].sc();
        ans += groups[1].sc();
    }
    else if (odd == 2 and even > 0) {
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        sort(all(groups),[](group &g1, group &g2) -> bool {
            return g1.es() < g2.es();
        });
        for (int i = 0; i < n; i++) {
            c1 += groups[i].val();
        }
        c1 += groups[0].es();
        c2 = c1;
        c1 += groups[1].es();

        sort(all(groups),[](group &g1, group &g2) -> bool {
            return g1.os() < g2.os();
        });
        c2 += groups[0].os();

        for (int i = 0; i < n; i++) {
            c3 += groups[i].l6;
        }
        c3 += groups[0].l3 - groups[0].l6;
        c3 += groups[1].l3 - groups[1].l6;
        ans = min({c1, c2, c3});
    }

    return ans;
}
int32_t main()
{
    usecppio
    int T, test_case;
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        cout << "Case #" << test_case+1 << endl;
        cout << solve() << endl;
    }
    return 0;
}