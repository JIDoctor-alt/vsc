#include<iostream>
#include<iomanip>
#include<cmath>
#define EPS 1e-6
using namespace std;
const double PI = acos(-1.0);
double r[10100];
int N,F;
bool Valid(double c)
{
    int ans = 0;
  /*  if(c < EPS)
        return true;*/
    for(int i = 0;i < N;++i)
        ans += (r[i]*r[i])/c;
    return ans >= F;
}
int main()
{
    cin>>N>>F;
    ++F;
    for(int i = 0;i < N;++i)
        cin>>r[i];
    double L = 0,R = 1<<30;
    while(R - L > EPS) 
    {
        double mid = (R+L)/2;
        if(Valid(mid))
            L = mid + EPS;
        else 
            R = mid - EPS;
    }   
    cout<<fixed<<setprecision(3)<<L*PI<<endl;
    return 0;
}