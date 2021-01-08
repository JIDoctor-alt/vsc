#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long sum = 0;
    for(int i = 0;i < n;++i)
    {
        double  x;
        cin>>x;
        sum += (long long)(x * 1000) * (i + 1) * (n - i);
    }
    printf("%.2f\n",sum/1000.0);
    return 0;
}