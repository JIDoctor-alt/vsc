#include<iostream>
#include<cmath>
#include<iomanip>
#define EPS 1e-6
using namespace std;
double f(double x)
{
    return pow(x,5)-15*pow(x,4)+85*pow(x,3)-225*pow(x,2)+274*x-121;
}
int main()
{
    double a = 1.5,b = 2.4;
    double mid;
    while (b - a > EPS)
    {
        mid = (a + b)/2;
        if(f(mid) == EPS)
            break;
        else if(f(mid) > EPS) //错误 f(a)*f(mid) > EPS
            a = mid;
        else 
            b = mid;
    }
    cout<<fixed<<setprecision(6)<<mid<<endl;
    return 0;
}