#include<bits/stdc++.h>
using namespace std;
int n,m,box[105][105],ans=INT_MAX,mrk[105][105];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

void dfs(int x,int y,int cost,int flag,int now_col)
{
    // printf("%d %d %d %d %d\n",x,y,cost,flag,now_col);
    if(cost>ans) return;
    if(x==m&&y==m)
    {
        ans=min(ans,cost);
        return;
    }
    else
    {
        for(int i=0;i<4;++i)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(1<=nx&&nx<=m&&1<=ny&&ny<=m&&mrk[nx][ny]==0)
            {
                mrk[nx][ny]=1;
                if(box[nx][ny]==0&&flag==1)
                {
                    if(now_col==1)
                    {
                        dfs(nx,ny,cost+2,0,1);
                        // dfs(nx,ny,cost+3,0,2);
                    }
                    else if(now_col==2)
                    {
                        // dfs(nx,ny,cost+3,0,1);
                        dfs(nx,ny,cost+2,0,2);
                    }
                }
                else if(box[nx][ny]!=now_col&&box[nx][ny]) dfs(nx,ny,cost+1,1,box[nx][ny]);
                else if(box[nx][ny]==now_col&&box[nx][ny]) dfs(nx,ny,cost,1,box[nx][ny]);
                mrk[nx][ny]=0;
            }
        }
    }
    // mrk[x][y]=0;
}

int main()
{
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    cin>>m>>n;
    int x_ip,y_ip,col;
    for(int i=1;i<=n;++i)
    {
        cin>>x_ip>>y_ip>>col;
        if(col==0) col=2;
        box[x_ip][y_ip]=col;
    }
    mrk[1][1]=1;
    dfs(1,1,0,1,box[1][1]);
    if(ans==INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}