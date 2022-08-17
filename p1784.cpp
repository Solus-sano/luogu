#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int p[11][11],l[11][11],box[11][11];

void dfs(int x,int y)
{
    if(x==10&&y==1)
    {
        for(int i=1;i<=9;++i)
        {
            for(int j=1;j<=9;++j) printf("%d ",a[i][j]);
            cout<<endl;
        }
        exit(0);
    }
    if(a[x][y]!=0)
    {
        if(y==9) dfs(x+1,1);
        else dfs(x,y+1);
    }

    else
    {
        // int tmp[10];
        // memset(tmp,0,sizeof(tmp));
        // for(int i=1;i<=9;++i)
        // {
        //     tmp[a[x][i]]=1;
        //     tmp[a[i][y]]=1;
        // }
        // int m=x-1-(x-1)%3,n=y-1-(y-1)%3;
        // for(int i=m+1;i<=m+3;++i)
        // {
        //     for(int j=n+1;j<=n+3;++j)
        //     {
        //         tmp[a[i][j]]=1;
        //     }
        // }

        for(int i=1;i<=9;++i)
        {
            if((p[x][i]==0)&&(l[y][i]==0)&&(box[(x-1)/3*3+(y-1)/3+1][i]==0))//tmp[i]==0
            {
                a[x][y]=i;
                p[x][i]=l[y][i]=box[(x-1)/3*3+(y-1)/3+1][i]=1;
                if(y==9) dfs(x+1,1);
                else dfs(x,y+1);
                a[x][y]=0;
                p[x][i]=l[y][i]=box[(x-1)/3*3+(y-1)/3+1][i]=0;
            }
        }
    }
}


int main()
{
    memset(a,0,sizeof(a));
    memset(p,0,sizeof(p));
    memset(l,0,sizeof(l));
    memset(box,0,sizeof(box));
    int ip;
    for(int i=1;i<=9;++i)
    {
        for(int j=1;j<=9;++j)
        {
            scanf("%d",&ip);
            a[i][j]=ip;
            if(ip!=0) p[i][ip]=l[j][ip]=box[(i-1)/3*3+(j-1)/3+1][ip]=1;
        }
    }
    dfs(1,1);
    return 0;
}
