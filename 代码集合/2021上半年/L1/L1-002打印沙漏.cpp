#include<iostream>
using namespace std;
int main()
{
    int N;
    char c;
    cin>>N>>c;
    if(N <= 1000)
    if(N < 7){//当打印一个字符的情况
        cout<<c<<endl;
        cout<<(N - 1)<<endl;//注意输出剩下没用掉的字符数量
    }
    else //当输出的字符超过一个的情况
    {
        int ans = 1, i = 0;//首先用ans记录尽可能用掉了多少字符
        while(ans <= N)//当ans超过了给定的字符结束循环  
        {
            ++i;
            ans += 2 * (2*i + 1);//通过循环查找最多用掉多少字符
        }
        if(ans > N)//如果ans大于N则减掉多余的部分
        {
            ans -= 2*(2*i + 1);
            --i;
        }        
        int nx = i;
  //      cout<<ans<<" "<<i<<endl;
        for(int j = 0;j <= nx;++j)//首先输出上半部分 0 到 nx行
        {
            for(int k = 0;k < j;++k)//空格数第一行从0开始，向下一次加1
                cout<<" ";
            for(int d = 0;d < 2*(nx-j)+1;++d)//
                cout<<c;
            cout<<endl;
        }
        for(int j = 1;j <= nx;++j)//输出一个字符的下半部分
        {
            for(int k = 0;k < nx - j;++k)
                cout<<" ";
            for(int d = 0;d < 2*j + 1;++d)
                cout<<c;
            cout<<endl;   
        }
        cout<<(N - ans)<<endl;
    }
    return 0;
}