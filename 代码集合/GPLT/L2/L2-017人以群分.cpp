#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
int N;
int main()
{
    cin>>N;
    int sum = 0,sum1 = 0;
    int x = (N / 2);
    for(int i = 0;i < N;++i)
    {
        cin>>a[i];
        sum += a[i];
    }
    sort(a, a + N);
    for(int i = 0;i < x;++i)
        sum1 += a[i];
    cout<<"Outgoing #: "<<(N - x)<<endl;
    cout<<"Introverted #: "<<x<<endl;
    cout<<"Diff = "<<(sum - sum1 - sum1)<<endl;
    return 0;
}