#include<iostream>
using namespace std;
int N;
char c;
//利用2*i的公式进行操作，注意边界问题，i开始的下标
int main()
{
    cin>>N>>c;
    if(N < 7)
    {
        cout<<c<<endl;
        cout<<(N - 1)<<endl;
    }
    else 
    {
        int sum = 1,i = 1;
        while(sum <= N)
        {
            ++i;
            sum += 2*(2*(i-1) + 1);
        }
        if(sum > N)
        {
            sum -= 2*(2 * (i - 1) + 1);
            --i;
        }
        for(int d = i;d > 0;--d)
        {
            for(int j = 0;j < i - d;++j)
                cout<<" ";
            for(int j = 1;j <= 2*(d-1) + 1;++j)
                cout<<c;
            cout<<endl;
        }
        for(int d = 2;d <= i;++d)
        {
            for(int j = 0;j < i - d;++j)
                cout<<" ";
            for(int j = 1;j <= 2*(d - 1) + 1;++j)
                cout<<c;
            cout<<endl;
        }
        cout<<(N-sum)<<endl;
    }
   
    return 0;
}