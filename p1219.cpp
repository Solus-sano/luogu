#include<bits/stdc++.h>
using namespace std;
int cnt=0,n,ans[100]={0},l1[100]={0},l2[100]={0},c[100]={0};
void queen(int ip)
{
    if(ip>n)
    {
        cnt++;
        if(cnt<=3)
        {
            for(int i=1;i<=n;++i) printf("%d ",ans[i]);
            printf("\n");
            return;
        }
    }
    else
    {
        for(int j=1;j<=n;++j)
        {
            if((!c[j])&&(!l1[ip+j])&&(!l2[ip-j+n]))
            {
                ans[ip]=j;
                c[j]=1;
                l1[ip+j]=1;
                l2[ip-j+n]=1;
                queen(ip+1);
                //ans[ip]=0;
                c[j]=0;
                l1[ip+j]=0;
                l2[ip-j+n]=0;
            }
        }
    }
}
int main()
{
    cin>>n;
    queen(1);
    cout<<cnt;
    return 0;
}
