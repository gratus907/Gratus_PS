#include <bits/stdc++.h>
#define lli long long int
#define MAX(A,B) A>B?A:B
#define MIN(A,B) A<B?A:B
#define gcd(A,B) __gcd(A,B)
#define lcm(A,B) A/(__gcd(A,B))*B
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define ld long double
#define modulo 998244353
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<int,double> pid;

int printed[400];
vector <pis> vec;
vector <string> org;
int n;
int visit[400];

int checkvalid1()
{
    for (int i = 0; i<400; i++)
        visit[i]=0;
    string front = vec[2*n-3].second;
    string guess = front;
    guess.push_back((vec[2*n-4].second[n-2]));
    for (int i = 1; i<n; i++)
    {
        int flag=0;
        string tmp = guess.substr(0,i);
        for (int j = 0; j<(2*n-2); j++)
        {
            if (visit[j])
                continue;
            if (visit[j] == 0)
            {
                if (vec[j].second == tmp)
                {
                    if (visit[j] == 0)
                    {
                        visit[j] = 1;
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (flag == 0)
            return -1;
    }
    for (int i = 1; i<n; i++)
    {
        int flag=0;
        string tmp = guess.substr(n-i,i);
        for (int j = 0; j<(2*n-2); j++)
        {
            if (visit[j])
                continue;
            if (visit[j] == 0)
            {
                if (vec[j].second == tmp)
                {
                    if (visit[j] == 0)
                    {
                        visit[j] = 2;
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (flag == 0)
        {
            return -1;
        }
    }
    return 0;
}

int checkvalid2()
{
    for (int i = 0; i<400; i++)
        visit[i]=0;
    string front = vec[2*n-4].second;
    string guess = front;
    guess.push_back((vec[2*n-3].second[n-2]));
    for (int i = 1; i<n; i++)
    {
        int flag=0;
        string tmp = guess.substr(0,i);
        for (int j = 0; j<(2*n-2); j++)
        {
            if (visit[j])
                continue;
            if (visit[j] == 0)
            {
                if (vec[j].second == tmp)
                {
                    if (visit[j] == 0)
                    {
                        visit[j] = 1;
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (flag == 0)
        {
            return -1;
        }
    }
    for (int i = 1; i<n; i++)
    {
        int flag=0;
        string tmp = guess.substr(n-i,i);
        for (int j = 0; j<(2*n-2); j++)
        {
            if (visit[j])
                continue;
            if (visit[j] == 0)
            {
                if (vec[j].second == tmp)
                {
                    if (visit[j] == 0)
                    {
                        visit[j] = 2;
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (flag == 0)
        {
            return -1;
        }
    }
    return 0;
}

int main()
{
    char al[3] = {0,'P','S'};
    scanf("%d",&n);
    for (int i = 0; i<2*n-2; i++)
    {
        string str;
        cin >> str;
        org.PB(str);
        vec.push_back(MP((int)str.length(),str));
    }
    sort(vec.begin(),vec.end());

    int a = checkvalid1();
    if (a==0)
    {
        for (int i = 0; i<(2*n-2); i++)
        {
            for (int j = 0; j<(2*n-2); j++)
            {
                if (printed[j])
                    continue;
                if (org[i] == vec[j].second)
                {
                    printf("%c",al[visit[j]]);
                    printed[j]=1;
                    break;
                }
            }
        }
        return 0;
    }
    int b = checkvalid2();
    if (b==0)
    {
        for (int i = 0; i<(2*n-2); i++)
        {
            for (int j = 0; j<(2*n-2); j++)
            {
                if (printed[j])
                    continue;
                if (org[i] == vec[j].second)
                {
                    printf("%c",al[visit[j]]);
                    printed[j]=1;
                    break;
                }
            }
        }
        return 0;
    }

}
