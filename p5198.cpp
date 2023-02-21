#include<bits/stdc++.h>
using namespace std;
int n,dx[]={1,0,-1,0},dy[]={0,1,0,-1},box[1005][1005];
char mark[1005][1005];
typedef pair<int,int> node;

int cmp(node a,node b)
{
    if(a.first==b.first) return a.second<b.second;
    return a.first>b.first;
}

node bfs(int x,int y)
{
    int S=0,C=0;
    queue<node> que;
    que.push(node{x,y});
    mark[x][y]='.';
    while(!que.empty())
    {
        node node_tmp=que.front();
        que.pop();
        S++;C+=4;//默认每个格子贡献4条边
        for(int i=0;i<4;++i)
        {
            int nx=node_tmp.first+dx[i],ny=node_tmp.second+dy[i];
            if(box[nx][ny]==1) C--;//如果旁边也有相邻格子则贡献边数-1
            if(0<=nx&&nx<=n+1&&0<=ny&&ny<=n+1&&mark[nx][ny]=='#')
            {
                que.push(node{nx,ny});
                mark[nx][ny]='.';
            }
        }
    }
    return node{S,C};
}

int main()
{
    cin>>n;
    for(int i=0;i<=n+1;++i)
    {
        for(int j=0;j<=n+1;++j)
        {
            mark[i][j]='.';
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>mark[i][j];
            if(mark[i][j]=='#') box[i][j]=1;
        }
    }
    node ans=node{0,10000};

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(mark[i][j]=='#')
            {
                node tmp_ans=bfs(i,j);
                if(cmp(tmp_ans,ans)) ans=tmp_ans;
            }
        }
    }
    cout<<ans.first<<' '<<ans.second;
    return 0;
}