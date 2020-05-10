#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) (A)>(B)?(A):(B)
#define MIN(A,B) (A)<(B)?(A):(B)
#define MP make_pair
#define PB push_back
#define int long long int
using namespace std;

typedef pair<int,int> pii;

const int NUM = 100200;
int n,m;

int quantity[NUM];
int totalquantity;
int price[NUM];
int cheapest = 0;
vector <pii> foods;

void order()
{
    int food, dish;
    int payment=0;
    scanf("%lld %lld",&food,&dish);
    totalquantity -= dish;
    if (totalquantity < 0)
    {
        printf("0\n");
        return;
    }
    if (quantity[food]>=dish)
    {
        payment += dish*price[food];
        quantity[food]-=dish;
        dish = 0;
        while(quantity[foods[cheapest].second]<=0)
        {
            cheapest++;
            if (cheapest==n)
                break;
        }
        printf("%lld\n",payment);
        return;
    }
    else
    {
        payment += quantity[food]*price[food];
        dish -= quantity[food];
        quantity[food]=0;
        while(dish>0)
        {
            int currentfood = foods[cheapest].second;
            if (quantity[currentfood]>=dish)
            {
                payment += dish*price[currentfood];
                quantity[currentfood]-=dish;
                dish = 0;
                printf("%lld\n",payment);
                return;
            }
            else
            {
                payment += quantity[currentfood]*price[currentfood];
                dish -= quantity[currentfood];
                quantity[currentfood]=0;
            }
            while(quantity[foods[cheapest].second]<=0)
            {
                cheapest++;
                if (cheapest==n)
                    break;
            }
        }
    }
    while(quantity[foods[cheapest].second]<=0)
    {
        cheapest++;
        if (cheapest==n)
            break;
    }
    printf("%lld\n",payment);
}

int32_t main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &quantity[i]);
        totalquantity += quantity[i];
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &price[i]);
        foods.PB(MP(price[i], i));
    }
    sort(foods.begin(), foods.end());
    for (int i = 0; i < m; i++)
        order();
}
