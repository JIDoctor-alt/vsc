#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int N;
//注意因子的边界范围 开根号，
bool judge(int x)
{
    return N % x == 0;
}
int main()
{
    cin>>N;
    int s= 0,max_len = 0;
    for(int i = 2;i <= sqrt(N);++i)
    {
        int j = i;
        int ans = 0,sum = 1;
        for(;j <= sqrt(N);++j)
        {
            sum *= j;
            if(judge(sum))
            {
               ++ans;
            }
            else 
            {
                break;
            }
        }
        if(max_len < ans)
        {
            s = i;
            max_len = ans;
        }
    }
    if(s == 0)
    {
        cout<<1<<endl;
        cout<<N<<endl;
    }
    else 
    {
            cout<<max_len<<endl;
    cout<<s;
    for(int j = 1;j < max_len;++j)
        cout<<"*"<<(s+j);

    }


    return 0;
}