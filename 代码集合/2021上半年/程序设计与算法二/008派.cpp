#include<iostream>
#include<cmath>

#include<iomanip>
#define MAX 10100
#define EPS 1e-6
using namespace std;
const double PI = acos(-1.0);
int N,F;
double R[MAX];
bool Valid(double s){
    int cnt = 0;

    for(int i = 0;i < N;i++){
      //  if(s > (R[i]*R[i]))return false;

        cnt +=(int)((R[i]*R[i])/s);
    }
    return cnt >= F;
}
int main(){
    cin>>N>>F;
    F = F + 1;
    for(int i = 0;i < N;i++)
      {
         // double r;
          //cin>>r;
          //R[i] = r*r;
          cin>>R[i];
      } 

    double l = 0,r = 1<<30;
    while(r - l > EPS){
        double mid = l + (r - l)/2;
        if(Valid(mid)){
            l = mid  ;
        }else{
            r = mid;
        }
    }
    cout<<fixed<<setprecision(3)<<PI*l<<endl;
}