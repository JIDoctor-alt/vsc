#include<iostream>
#include<algorithm>
using namespace std;
int a[10];
int main()
{
    int N;
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        cin>>a[i];
    }
    int sum = 0;
    for(int i = 0;i < N;++i)
    {
        for(int j = 0;j < N;++j)
        {
            if(j != i)
            {
                sum += (a[i] * 10) + a[j];
            }
        }
    }
    cout<<sum<<endl;

    return 0;
}