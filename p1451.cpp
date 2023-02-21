#include<bits/stdc++.h>
using namespace std;
int n,m,dx[]={1,0,-1,0},dy[]={0,1,0,-1};
char box[105][105];
typedef pair<int,int> node;

void dfs(int x,int y)
{
    box[x][y]='0';
    for(int i=0;i<4;++i)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if('1'<=box[nx][ny]&&box[nx][ny]<='9')
        {
            dfs(nx,ny);
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>box[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(box[i][j]!='0')
            {
                dfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
