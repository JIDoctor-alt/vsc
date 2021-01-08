#include<iostream>
#include<math.h>
#include<iomanip>
#define EPS  0.005
using namespace std;
int main()
{
    double r1,p1,r2,p2;
    cin>>r1>>p1>>r2>>p2;
    double R = r1 * r2;
    double P = p1 + p2;
    double A = R * cos(P);
    double B = R * sin(P);
    if(A + EPS >= 0 && A < 0)
        cout<<"0.00";
    else 
       printf("%.2f",A);
    if(B >= 0)
        printf("+%.2fi",B);
    else if(B + EPS >= 0 && B < 0)
        printf("+0.00i");
    else 
        printf("%.2fi",B);
    return 0;
}