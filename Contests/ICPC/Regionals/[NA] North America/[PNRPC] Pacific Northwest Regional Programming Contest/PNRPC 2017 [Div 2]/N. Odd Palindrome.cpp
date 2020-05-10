#include<bits/stdc++.h>
using namespace std;

char str[200];
char ans[2][200] = {"Odd.", "Or not."};
bool is_palindrome(int l, int r)
{
    int s = (r-l+1);
    for (int i = 0; i<(s/2); i++)
    {
        if (str[l+i]!=str[r-i])
            return 0;
    }
    return 1;
}

int main()
{
    int flag = 0;
    scanf("%s",str);
    int slen = strlen(str);
    for (int i = 0; i<slen-1; i++)
    {
        for (int j = i+1; j<slen; j+=2)
        {
            if (is_palindrome(i, j))
                flag = 1;
        }
    }
    printf("%s",ans[flag]);
}
