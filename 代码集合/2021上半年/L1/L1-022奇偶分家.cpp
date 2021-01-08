#include<iostream>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int ans1 = 0, ans2 = 0;//奇数  偶数
    for(int i = 0;i < N;++i)
    {
        int num;
        cin>>num;
        if(num%2)
            ++ans1;
        else 
            ++ans2;
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}