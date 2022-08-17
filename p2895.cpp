#include<bits/stdc++.h>
using namespace std;
int spc[1010][310][310],m,t,x,y,dx[]={1,1,-1,-1},dy[]={1,-1,1,-1};
struct node{
    int t0;
    int x0;
    int y0;
};
void mov(int a,int b,int c)
{
    queue<node> Q;
    node tmp,tmp1;
    tmp.t0=a;
    tmp.x0=b;
    tmp.y0=c;
    Q.push(tmp);
    while(!Q.empty())
    {
        tmp=Q.front();
        Q.pop();
        for(int i=0;i<4;++i)
        {
            tmp1.t0=tmp.t0+1;tmp1.x0=tmp.x0+dx[i];tmp1.y0=tmp.y0+dy[i];
            if(tmp1.t0<=1000&&0<=tmp1.x0&&tmp1.x0<=300&&0<=tmp1.y0&&tmp1.y0<=300&&spc[tmp1.t0][tmp1.x0][tmp1.y0]==-1)
            {
                spc[tmp1.t0][tmp1.x0][tmp1.y0]=spc[tmp.t0][tmp.x0][tmp.y0]+1;
                cout<<tmp1.t0<<" "<<tmp.x0<<" "<<tmp.y0;
                int chk=1;
                for(int j=tmp1.t0;j<=1000;++j)
                {
                    if(spc[j][tmp1.x0][tmp1.y0]==-2) chk=0;
                }
                if(chk==1)
                {
                    cout<<spc[tmp1.t0][tmp1.x0][tmp1.y0];
                    return;
                }
                Q.push(tmp1);
            }

        }
    }
    cout<<-1;
}
int main()
{
    cin>>m;
    for(int i=0;i<=1000;++i)
    {
        for(int j=0;j<=300;++j)
        {
            for(int k=0;k<=300;++k) spc[i][j][k]=-1;
        }
    }
    while(m--)
    {
        scanf("%d%d%d",&t,&x,&y);
        for(int i=t;i<=1000;++i)
        {
            spc[i][x][y]=-2;
            for(int j=0;j<4;++j)
            {
                int nx=x+dx[j],ny=y+dy[j];
                if(0<=nx&&nx<=300&&0<=ny&&ny<=300)
                {
                    spc[i][nx][ny]=-2;
                }
            }
        }
    }
    if(spc[0][0][0]==-2)
    {
        cout<<-1;
        return 0;
    }
    spc[0][0][0]=0;
    mov(0,0,0);
    return 0;
}
