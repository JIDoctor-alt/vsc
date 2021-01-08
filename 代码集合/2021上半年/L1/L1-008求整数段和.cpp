#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int A,B,sum = 0;
    cin>>A>>B;
    int ans = 1;
    for(int i = A;i <= B;++i)
    {
        sum += i;
        cout<<fixed<<setw(5)<<setfill(' ')<<i;
        if( ans % 5 == 0)//每输出5个数后输出换行操作
            cout<<endl;
        ans++;//计数器
    }
    if((ans-1)%5)//如果最后一个数不是在第五列的情况
        cout<<endl;
    cout<<"Sum = "<<sum<<endl;
    return 0;
}