#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;

char str[100020];
int ct[200020];
vector<pii> s;
int main()
{
    scanf("%s",str);
    int l = strlen(str), maxi = 0, mini = 0, sum = 0;
    s.push_back(pii(0,0));
    ct[100001]++;
    for(int i=0; i<l; i++)
    {
        if(str[i]=='B')
            sum++;
        else
            sum--;
        if(!ct[sum+100001])
            s.push_back(pii(sum,i+1));
        ct[sum+100001]++;
    }
    sort(s.begin(),s.end());
    maxi = max(s.begin()->second,(s.end()-1)->second);
    mini = min(s.begin()->second,(s .end()-1)->second);
    printf("%d %d",mini+1,maxi);
}
 
