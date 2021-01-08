#include<iostream>
#include<iomanip>
using namespace std;
double a[100005];
int main()
{
    int N;
    cin>>N;
    double sum = 0;
    for(int i = 0;i < N;++i)
    {
        cin>>a[i];
        sum += a[i];
    }
    double res = sum;
    for(int i = 1;i < N;++i)
    {
       sum -= a[i-1];
       res += sum;
    }
    cout<<fixed<<setprecision(2)<<sum<<endl;
    return 0;
}