#include<bits/stdc++.h>
using namespace std;
int n,m,rnk[10010],lst[10010],z,x,y;
int get(int a)
{
    if(a==lst[a]) return a;
    else return get(lst[a]);
}
int chk(int a,int b)
{
    a=get(a);
    b=get(b);
    return a==b;
}
void merge(int a,int b)
{
    a=get(a);
    b=get(b);
    if(a==b) return;
    if(rnk[a]<rnk[b]) lst[a]=b;
    else
    {
        lst[b]=a;
        if(rnk[a]==rnk[b]) rnk[a]++;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) lst[i]=i;
    while(m--)
    {
        scanf("%d%d%d",&z,&x,&y);
        if(z==1) merge(x,y);
        else if(z==2)
        {
            if(chk(x,y)) printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}