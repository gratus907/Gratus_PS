#include "artclass.h"
#include <bits/stdc++.h>
#define colordist(x1,y1,x2,y2) (abs(R[x1][y1]-R[x2][y2])+abs(G[x1][y1]-G[x2][y2])+abs(B[x1][y1]-B[x2][y2]))
using namespace std;


int style(int H, int W, int R[500][500], int G[500][500], int B[500][500]) 
{
    double avg_color_dist = 0;
    for (int i = 1; i<H; i++)
    {
        for (int j = 1; j<W; j++)
        {
            double a = colordist(i,j,i-1,j);
            double b = colordist(i,j,i,j-1);
            avg_color_dist += (a+b);
        }
    }
    avg_color_dist /= (H*W);
    printf("%lf\n",avg_color_dist);
    if(avg_color_dist < 18) return 4;
    if(avg_color_dist < 47) return 1;
    if(avg_color_dist > 107) return 3;
    return 2;
}
