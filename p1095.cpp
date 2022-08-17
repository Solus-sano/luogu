#include<bits/stdc++.h>
using namespace std;

long M,S,T;
int main()
{
    cin>>M>>S>>T;
    long s1=0,s2=0,s=0;
    for(long t=1;t<=T;t++)
    {
        s1 += 17;
        if(M >= 10)
        {
            M -= 10;
            s2 += 60;
        }
        else
        {
            M += 4;
        }
        if(s1 < s2)
        {
            s1 = s2;
        }
        if(s1 >= S)
        {
            cout<<"Yes"<<endl<<t<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl<<s1<<endl;
}
