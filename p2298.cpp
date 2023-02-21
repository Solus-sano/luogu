#include<bits/stdc++.h>
using namespace std;
char idx[2005][2005];
int box[2005][2005],n,m,dx[]={1,0,-1,0},dy[]={0,1,0,-1};
typedef pair<int,int> node;

int bfs(int x1,int y1,int x2,int y2)
{
    queue<node> que;
    que.push(node{x1,y1});
    box[x1][y1]=1;

    while(!que.empty())
    {
        node tmp_node=que.front();
        que.pop();
        if(tmp_node.first==x2&&tmp_node.second==y2)
        {
            return box[x2][y2]-1;
        }

        for(int i=0;i<4;++i)
        {
            int nx=tmp_node.first+dx[i],ny=tmp_node.second+dy[i];
            if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&idx[nx][ny]=='.'&&box[nx][ny]==0)
            {
                box[nx][ny]=box[tmp_node.first][tmp_node.second]+1;
                que.push(node{nx,ny});
            }
        }
    }
    return -1;
}

int main()
{
    int x1,y1,x2,y2;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>idx[i][j];
            if(idx[i][j]=='m')
            {
                x1=i;
                y1=j;
            }
            if(idx[i][j]=='d')
            {
                x2=i;
                y2=j;
                idx[i][j]='.';
            }
        }
    }
    int ans=bfs(x1,y1,x2,y2);
    if(ans==-1) printf("No Way!");
    else cout<<ans;
    return 0;
}