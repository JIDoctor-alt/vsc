#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long N;
int main(){
    cin>>N;
    int st = 2, send = sqrt(N) + 1;
    int len = 0,temp,first;
    for(int i = st;i < send;++i)//枚举每一种开始的因子
    {
        temp  = 1;//连续因子的乘积
        int j;
        for(j = i;;++j)//从指定数值开始每次加1
        {
            temp *= j;//连续因子的乘积
            if(N % temp != 0)//不能被N整除跳出即可
                break;
        }
        if(j - i > len)//计算连续因子的长度
        {
           len = j-i;//个数
           first = i;//开始的数值
        }
    }
    if(len == 0)//质数的情况或只有一个因子
    {
        cout<<1<<endl;
        cout<<N<<endl;
    }
    else 
    {
        cout<<len<<endl;
        cout<<first;
        for(int i = 1;i < len;++i)
            cout<<"*"<<(first+i);
    }
    return 0;
}