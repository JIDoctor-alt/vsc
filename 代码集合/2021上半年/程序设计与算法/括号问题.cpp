#include<iostream>
#include<string>

using namespace std;
string s;//存储序列
int ans;//记录有多少种合法的序列
//判断括号序列是否合法
bool check()
{   //用来标记左括号的数量
    int cnt  = 0;
    for(int i = 0;i < s.length();i++)
        if(s[i] == '(')
            ++cnt;//如果是左括号加1
        else///不是左括号就是有括号了呀！！！
        {
            //如果是右括号
            if(--cnt < 0)return false;//只要cnt变为负数就说明不合法
        }
        //如果序列合法说明cnt为零，cnt大于零说明左括号多
        return cnt == 0;  
}
//判断第k个符号
void dfs(int k)
{
    if(k == s.length())
    {
        if(check())
            ++ans;
        return;
    }
    //如果是问号 可能是左括号，也可能是有括号
    if(s[k] == '?')
    {
        s[k] = '(';
        dfs(k+1);//判断完成之后可以在下一个判断完成再恢复现场信息
        //
        s[k] = ')';
        dfs(k+1);
        //以上两种情况判断完成要恢复现场信息
        s[k] = '?';
    }else
    //不是问号,继续向下递归
    dfs(k+1);
}
int main()
{
    cin>>s;
    dfs(0);//从开始位置遍历
    cout<<ans<<endl;
    return 0;
}