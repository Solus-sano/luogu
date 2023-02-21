#include<bits/stdc++.h>
using namespace std;
int n,a,b,dh[210],cnt[210],nh1,nh2;
void mov(int ip)
{
    queue<int> Q;
    Q.push(ip);
    int tmp;
    while(!Q.empty())
    {
        tmp=Q.front();
        Q.pop();
        nh1=tmp+dh[tmp];
        nh2=tmp-dh[tmp];
        if(1<=nh1&&nh1<=n&&cnt[nh1]==-1)
        {
            cnt[nh1]=cnt[tmp]+1;
            Q.push(nh1);
        }
        if(1<=nh2&&nh2<=n&&cnt[nh2]==-1)
        {
            cnt[nh2]=cnt[tmp]+1;
            Q.push(nh2);
        }
        if(nh1==b||nh2==b) break;
    }
}
int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&dh[i]);
        cnt[i]=-1;
    }
    cnt[a]=0;
    mov(a);
    cout<<cnt[b];
    return 0;
}
