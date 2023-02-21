#include<bits/stdc++.h>
using namespace std;

double dis(double a,double b,double c,double d)
{
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main()
{
    double a[10];
    double x,y,z,c;
    for(int i = 0;i < 6; i++)
    {
        scanf("%lf",&a[i]);
    }
    x = dis(a[0],a[1],a[2],a[3]);
    y = dis(a[2],a[3],a[4],a[5]);
    z = dis(a[4],a[5],a[0],a[1]);
    c = x + y + z;
    printf("%.2lf",c);
    return 0;
}
