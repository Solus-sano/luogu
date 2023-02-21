#include<bits/stdc++.h>
using namespace std;
struct edge{
    int v;
    int next;
}e[6005];
int dp[6005][2],n,cnt,h[6005],r[6005],chk[6005],l,k,ihead[6005];
void ade(int u,int v)
{
    e[++cnt].v=v;
    e[cnt].next=h[u];
    h[u]=cnt;
}
void opt(int k)
{
    // cout<<k<<endl;
    // chk[k]=1;
    dp[k][1]=r[k];
    for(int i=h[k];i;i=e[i].next)
    {
        // if(chk[e[i].v]) continue;
        opt(e[i].v);
        dp[k][0]+=max(dp[e[i].v][0],dp[e[i].v][1]);
        dp[k][1]+=dp[e[i].v][0];
    }
    return;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&r[i]);
    }
    for(int i=1;i<n;++i)
    {
        scanf("%d%d",&l,&k);
        ade(k,l);
        ihead[l]=1;
    }
    for(int i=1;i<=n;++i)
    {
        if(ihead[i]==0)
        {
            opt(i);
            printf("%d",max(dp[i][1],dp[i][0]));
        }
    }
    return 0;
}
