#include <cstdio>
int n,d[365],i,tmp,cnt,ans;
int main(){
    scanf("%d",&n);
    for(;i<n;i++)scanf("%d",d+i);
    for(i=0;i<n;){
        tmp=cnt=0;
        while(i<n){
            tmp-=d[i],cnt++,i++;
            if(i<n&&d[i]*cnt+tmp>=20)
                break;
        }
        ans++;
    }
    printf("%d",ans);
}