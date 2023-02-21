#include<bits/stdc++.h>
using namespace std;
int n,m,mark[55][55],tmp,box[55][55][4],dx[]={0,-1,0,1},dy[]={1,0,-1,0};

struct node
{
    int x;
    int y;
    int idx;
};

int fang2idx(char a)
{
    char lst[]={'E','N','W','S'};
    for(int i=0;i<4;++i)
    {
        if(lst[i]==a) return i;
    }
    return -1;
}

int bfs(int x_begin,int y_begin,int x_end,int y_end,int idx_init)
{
    if(!(mark[x_end][y_end]==0&&mark[x_begin][y_begin]==0&&1<=x_begin&&x_begin<=n-1&&1<=y_begin&&y_begin<=m-1)) return -1;
    
    queue<node> que;
    que.push(node{x_begin,y_begin,idx_init});
    box[x_begin][y_begin][idx_init]=1;

    while (!que.empty())
    {
        node node_tmp=que.front();
        //printf("%d %d %d %d\n",node_tmp.x,node_tmp.y,node_tmp.idx,box[node_tmp.x][node_tmp.y][node_tmp.idx]);
        que.pop();
        if(node_tmp.x==x_end&&node_tmp.y==y_end) return box[x_end][y_end][node_tmp.idx]-1;
        
        int nx=node_tmp.x,ny=node_tmp.y,nidx;
        nidx=(node_tmp.idx+1)%4;
        if(!box[nx][ny][nidx])
        {
            box[nx][ny][nidx]=box[nx][ny][node_tmp.idx]+1;
            que.push(node{nx,ny,nidx});
        }
        nidx=(node_tmp.idx-1+4)%4;
        if(!box[nx][ny][nidx])
        {
            box[nx][ny][nidx]=box[nx][ny][node_tmp.idx]+1;
            que.push(node{nx,ny,nidx});
        }

        for(int i=1;i<=3;++i)
        {
            nx=node_tmp.x+dx[node_tmp.idx]*i;
            ny=node_tmp.y+dy[node_tmp.idx]*i;
            if(mark[nx][ny]==1||1>nx||nx>n-1||1>ny||ny>m-1) break;

            if(box[nx][ny][node_tmp.idx]==0)
            {
                box[nx][ny][node_tmp.idx]=box[node_tmp.x][node_tmp.y][node_tmp.idx]+1;
                que.push(node{nx,ny,node_tmp.idx});
            }
        }
    }
    return -1;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            scanf("%d",&tmp);
            if(tmp==1)
            {
                mark[i][j]=1;
                mark[i-1][j]=1;
                mark[i][j-1]=1;
                mark[i-1][j-1]=1;
            }
        }
    }
    int x_begin,y_begin,x_end,y_end;
    char fang_init;
    cin>>x_begin>>y_begin>>x_end>>y_end>>fang_init;
    int ans=bfs(x_begin,y_begin,x_end,y_end,fang2idx(fang_init));
    cout<<ans;
    return 0;
}