#include<bits/stdc++.h>
using namespace std;
int n,ip[105],dp1[105],dp2[105],cnt,ans=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&ip[i]);
    for(int i=1;i<=n;++i)
    {
        vector<int> lst1;
        vector<int> lst2;
        for(int j=1;j<=i;++j) lst1.push_back(ip[j]);
        for(int j=n;j>=i;--j) lst2.push_back(ip[j]);
        fill(dp1,dp1+n,500);
        fill(dp2,dp2+n,500);
        for(int j=0;j<lst1.size();++j) *lower_bound(dp1,dp1+n,lst1[j])=lst1[j];
        for(int j=0;j<lst2.size();++j) *lower_bound(dp2,dp2+n,lst2[j])=lst2[j];
        cnt=(lower_bound(dp1,dp1+n,500)-dp1)+(lower_bound(dp2,dp2+n,500)-dp2)-1;
        ans=max(ans,cnt);
    }
    cout<<n-ans;
    return 0;
}
