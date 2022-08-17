#include<bits/stdc++.h>
using namespace std;
string ip,s1,s2;
int n,m,par[20005],rnk[20005];
unordered_map<string,int> lst;
int get(int a)
{
    if(a==par[a]) return a;
    else return get(par[a]);
}
int chk(int a,int b){return get(a)==get(b);}
void merge(int a,int b)
{
    a=get(a);b=get(b);
    if(a==b) return;
    if(rnk[a]<rnk[b]) par[a]=b;
    else{
        par[b]=a;
        if(rnk[a]==rnk[b]) rnk[a++];
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>ip;
        lst[ip]=i;
        par[i]=i;
    }
    while(m--)
    {
        cin>>s1>>s2;
        merge(lst[s1],lst[s2]);
    }
    cin>>n;
    while(n--)
    {
        cin>>s1>>s2;
        if(chk(lst[s1],lst[s2])) printf("Yes.\n");
        else printf("No.\n");
    }
    return 0;
}