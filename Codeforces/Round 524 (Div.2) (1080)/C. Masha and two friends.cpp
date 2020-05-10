#include <bits/stdc++.h>
#define lli long long int
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/__gcd(A,B)*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

lli MIN(lli A, lli B)
{
    return A>B? B:A;
}
lli MAX(lli A, lli B)
{
    return A>B? A:B;
}

void query()
{
    lli n,m;
    lli black, white;
    scanf("%lld %lld",&n,&m);
    lli board_size = m*n;
    black = (board_size)/2;
    white = board_size - black;

    lli box_white[4];
    lli box_black[4];
    scanf("%lld %lld %lld %lld",&box_white[0],&box_white[1],&box_white[2],&box_white[3]);
    scanf("%lld %lld %lld %lld",&box_black[0],&box_black[1],&box_black[2],&box_black[3]);
    lli size_boxwhite = (box_white[2]-box_white[0]+1) * (box_white[3]-box_white[1]+1);
    lli size_boxblack = (box_black[2]-box_black[0]+1) * (box_black[3]-box_black[1]+1);
    lli overlap_region[4];
    overlap_region[0] = MAX(box_white[0],box_black[0]);
    overlap_region[1] = MAX(box_white[1],box_black[1]);
    overlap_region[2] = MIN(box_white[2],box_black[2]);
    overlap_region[3] = MIN(box_white[3],box_black[3]);
    lli p1 = (overlap_region[2]-overlap_region[0]+1);
    p1 = MAX(p1,0);
    lli p2 = (overlap_region[3]-overlap_region[1]+1);
    p2 = MAX(p2,0);
    lli overlap =  p1* p2;
    overlap = MAX(overlap,0);
    lli overlap_reg_black=0;
    if (size_boxwhite%2 == 0)
    {
        white += (size_boxwhite/2);
        black = board_size-white;
    }
    else
    {
        if ((box_white[0]+box_white[1]) %2 == 0)
        {
            black -= size_boxwhite/2;
            white = board_size-black;
        }
        else
        {
            black -= size_boxwhite/2 +1;
            white = board_size-black;
        }
    }
    if (size_boxblack%2 == 0)
    {
        black += (size_boxblack/2);
        white = board_size-black;
    }
    else
    {
        if ((box_black[0]+box_black[1]) %2 == 0)
        {
            white -= size_boxblack/2 + 1;
            black = board_size-white;
        }
        else
        {
            white -= size_boxblack/2;
            black = board_size-white;
        }
    }

    if (overlap%2 == 0)
    {
        overlap_reg_black = (overlap/2);
    }
    else
    {
        if ((overlap_region[0]+overlap_region[1]) %2 == 0)
        {
            overlap_reg_black = (overlap/2);
        }
        else
        {
            overlap_reg_black = (overlap/2) + 1;
        }
    }

    black += overlap_reg_black;
    white = board_size-black;

    printf("%lld %lld\n",white,black);

}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        query();
    }
}