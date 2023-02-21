#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,box[505][505],dx[]={1,0,-1,0},dy[]={0,1,0,-1};
typedef pair<int,int> node;

int main()
{
    cin>>n>>m>>a>>b;
    queue<node> que;
    int x,y;
    for(int i=1;i<=a;++i)
    {
        scanf("%d%d",&x,&y);
        box[x][y]=1;
        que.push(node{x,y});
    }
    while(!que.empty())
    {
        node node_tmp=que.front();
        que.pop();
        for(int i=0;i<4;++i)
        {
            int nx=node_tmp.first+dx[i],ny=node_tmp.second+dy[i];
            if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&box[nx][ny]==0)
            {
                box[nx][ny]=box[node_tmp.first][node_tmp.second]+1;
                que.push(node{nx,ny});
            }
        }
    }
    for(int i=1;i<=b;++i)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",box[x][y]-1);
    }
    return 0;
}