#include<bits/stdc++.h>
using namespace std;
int h,w,dx[]={1,0,-1,0},dy[]={0,1,0,-1};
char box[25][25];
typedef pair<int,int> node;

int bfs(int x,int y)
{
    queue<node> que;
    que.push(node{x,y});
    box[x][y]='#';
    int ans=0;
    while (!que.empty())
    {
        ans++;
        node node_tmp=que.front();
        que.pop();
        for(int i=0;i<4;++i)
        {
            int nx=node_tmp.first+dx[i],ny=node_tmp.second+dy[i];
            if(1<=nx&&nx<=h&&1<=ny&&ny<=w&&box[nx][ny]=='.')
            {
                box[nx][ny]='#';
                que.push(node{nx,ny});
            }
        }
    }
    return ans;
}

int main(void)
{
    cin>>w>>h;
    int x_init,y_init;
    for(int i=1;i<=h;++i)
    {
        for(int j=1;j<=w;++j)
        {
            cin>>box[i][j];
            if(box[i][j]=='@')
            {
                x_init=i;y_init=j;
            }
        }
    }

    int ans=bfs(x_init,y_init);
    cout<<ans;
    return 0;
}