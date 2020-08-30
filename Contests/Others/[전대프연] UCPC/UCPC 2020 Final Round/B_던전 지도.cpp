#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
#define int ll
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
const bool debug = 0;

int n, m, k;
char dungeon[26][202020];
char row[202020];
int leftClose[26][202020];
int rightClose[26][202020];
int segment[26][202020];
int32_t main()
{
    scanf("%lld %lld %lld\n",&n, &m, &k);
    for (int i = 0; i<k; i++)
        scanf("%s",dungeon[i]+1);
    scanf("%s",row+1);
    for (int i = 0; i<k; i++)
    {
        vector <int> allUp;
        for (int j = 1; j<=m; j++)
        {
            if (dungeon[i][j]=='U')
                allUp.push_back(j);
        }
        int pt = 1;
        int last = 1;
        for (int j = 0; j<=m; j++)
        {
            if (dungeon[i][j]=='R')
                segment[i][j] = last;
            else
            {
                segment[i][j] = last;
                last = j+1;
            }
        }
        for (int j = 0; j<allUp.size(); j++)
        {
            while(pt <= allUp[j])
            {
                rightClose[i][pt] = allUp[j];
                pt++;
            }
        }
        while(pt <= m)
        {
            rightClose[i][pt] = m+1;
            pt++;
        }
        pt = m;
        for (int j = allUp.size()-1; j>=0; j--)
        {
            while (pt >= allUp[j])
            {
                leftClose[i][pt] = allUp[j];
                pt--;
            }
        }
        while (pt>=1)
        {
            leftClose[i][pt] = 0;
            pt--;
        }
    }
    int curLeft = m;
    int curRight = m;
    int lftend = m;
    int curDownPoint = m;
    int ans = 0;
    for (int r = n; r > 1; r--)
    {
        int curRow = row[r]-'A';
        int nxtRow = row[r-1]-'A';
        int rightDown = leftClose[nxtRow][curRight];
        int leftMost = segment[curRow][curLeft];
        lftend = leftMost;
        int leftDown = rightClose[nxtRow][leftMost];
        if (curDownPoint <= 0 || curDownPoint > m) continue;
        ans += (curDownPoint-leftMost+1);

        curLeft = leftDown;
        curRight = rightDown;
        curDownPoint = rightDown;
        if (leftDown > rightDown) break;
        if (leftDown > m || rightDown <= 0)
        {

            break;
        }
    }
    lftend = segment[row[1]-'A'][curLeft];
    if (curDownPoint > 0 && curDownPoint <= m && 0 < curLeft && curLeft <= m)
    {
        if (lftend <= curDownPoint)
            ans += (curDownPoint-lftend+1);
    }
    printf("%lld\n",ans);
}