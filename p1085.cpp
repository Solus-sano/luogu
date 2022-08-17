#include<bits/stdc++.h>
using namespace std;

struct lesson{
    int t1;
    int t2;

};

int main()
{
    lesson L[7];
    int a[7];
    for(int i = 0;i<7;i++)
    {
        cin>>L[i].t1>>L[i].t2;
        a[i] = L[i].t1 + L[i].t2;
    }
    for(int j = 0;j<7;j++)
    {
        if(a[j]>8)
        {
            cout<<j+1<<endl;
            return 0;
        }
    }
    cout<<0<<endl;


}
