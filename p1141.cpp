#include<bits/stdc++.h>
using namespace std;
int ans[100005],n,m,dx[]={1,0,-1,0},dy[]={0,1,0,-1},flag[1005][1005];
char idx[1005][1005];

void dfs(int x,int y,int type)
{
    for(int i=0;i<4;++i)
    {
        int nx=x+dx[i],ny=y+dy[i];
        // cout<<nx<<' '<<ny<<endl;
        if(1<=nx&&nx<=n&&1<=ny&&ny<=n&&flag[nx][ny]==0&&idx[x][y]!=idx[nx][ny])
        {
            // cout<<nx<<' '<<ny<<' '<<box[nx][ny]<<endl;
            ans[type]++;
            flag[nx][ny]=type;
            dfs(nx,ny,type);
            
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>idx[i][j];
        }
    }
    int x,y;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d",&x,&y);
        if(flag[x][y]==0)
        {
            ans[i]++;
            flag[x][y]=i;
            dfs(x,y,i);
        }
        else ans[i]=ans[flag[x][y]];
        
    }
    for(int i=1;i<=m;++i) printf("%d\n",ans[i]);
    return 0;
}