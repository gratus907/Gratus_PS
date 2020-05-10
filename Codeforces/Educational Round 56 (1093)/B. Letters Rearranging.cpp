#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for (int T = 0; T<t; T++)
    {
        char word[1030];
        scanf("%s",word);
        int checker = 0;
        int l = strlen(word);
        int ocount[26];
        for (int i = 0; i<26; i++)
            ocount[i] = 0;
        for (int i = 0; i<l; i++)
        {
            if (ocount[word[i]-'a'] == 0)
            {
                checker++;
                ocount[word[i]-'a'] = 1;
            }
        }
        if (checker == 1)
        {
            printf("-1\n");
        }
        else
        {
            sort(word,word+l);
            printf("%s\n",word);
        }
    }
}
