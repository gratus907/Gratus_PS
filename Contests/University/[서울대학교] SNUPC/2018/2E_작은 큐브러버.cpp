#include <bits/stdc++.h>
using namespace std;
char cb[8][4];

int main()
{
    for (int i = 0; i < 8; i++)
        cin >> cb[i][0] >> cb[i][1] >> cb[i][2];
    bool unable = false;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int s1 = cb[i][j];
            int s2 = cb[i][(j + 1) % 3];
            int ct = 0;

            for (int k = 0; k < 8; k++)
                if (i != k)
                    for (int p = 0; p < 3; p++)
                        if (cb[k][p] == s1 && cb[k][(p + 2) % 3] == s2)
                            ct++;
            if (ct != 1)
                unable = true;
        }
    }
    cout << (unable?"NO":"YES");
}
