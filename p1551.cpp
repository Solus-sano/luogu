#include<bits/stdc++.h>
using namespace std;
int n,m,p,lst[5005],rnk[5005],m1,m2,p1,p2;
int get(int a)
{
    if(a==lst[a]) return a;
    else return get(lst[a]);
}
int chk(int a,int b){return get(a)==get(b);}
void merge(int a,int b)
{
    a=get(a);b=get(b);
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
    cin>>n>>m>>p;
    for(int i=1;i<=n;++i) lst[i]=i;
    while(m--)
    {
        scanf("%d%d",&m1,&m2);
        merge(m1,m2);
    }
    while(p--)
    {
        scanf("%d%d",&p1,&p2);
        if(chk(p1,p2)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}