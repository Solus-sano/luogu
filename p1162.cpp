#include<bits/stdc++.h>
using namespace std;
int n,box[35][35],dx[]={1,0,-1,0},dy[]={0,1,0,-1};
typedef pair<int,int> node;

void bfs(int x,int y)
{
    queue<node> que;
    que.push(node{x,y});

    while (!que.empty())
    {
        node node_tmp=que.front();
        que.pop();

        for(int i=0;i<4;++i)
        {
            int nx=node_tmp.first+dx[i],ny=node_tmp.second+dy[i];
            if(1<=nx&&nx<=n&&1<=ny&&ny<=n&&box[nx][ny]==2)
            {
                box[nx][ny]=0;
                que.push(node{nx,ny});
            }
        }
    }
    
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            scanf("%d",&box[i][j]);
            if(box[i][j]==0) box[i][j]=2;
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(box[1][i]==2) bfs(1,i);
        if(box[n][i]==2) bfs(n,i);
    }
    for(int i=2;i<=n-1;++i)
    {
        if(box[i][1]==2) bfs(i,1);
        if(box[i][n]==2) bfs(i,n);
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            printf("%d ",box[i][j]);
        }
        printf("\n");
    }
    return 0;
}