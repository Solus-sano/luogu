#include<bits/stdc++.h>
using namespace std;
int ip[50],t[10],sum=0,tmp=10000000,lf=0,rt=0;
void fnd(int a,int b)
{
    if(a>t[b])
    {
        tmp=min(tmp,max(lf,rt));
        return;
    }
    lf+=ip[a];
    fnd(a+1,b);
    lf-=ip[a];
    rt+=ip[a];
    fnd(a+1,b);
    rt-=ip[a];
}
int main()
{
    for(int i=1;i<=4;++i) scanf("%d",&t[i]);
    for(int i=1;i<=4;++i)
    {
        for(int j=1;j<=t[i];++j)
        {
            scanf("%d",&ip[j]);
        }
        fnd(1,i);
        sum+=tmp;
        tmp=100000000;
    }
    cout<<sum;
    return 0;
}
