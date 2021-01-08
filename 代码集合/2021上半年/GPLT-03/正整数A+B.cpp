#include<iostream>
#include<string>

using namespace std;
//判断是否为数
int Vlaid(string & s)
{ 
    int sum = 0;
    int len = s.length();
    for(int i = 0;i < len;i++)
    {
        if(s[i] >= 48 && s[i] <= 58)
            sum  = sum*10 +(s[i] - '0');
        else 
            return 0;
    }
    //注意这个地方 A或者B的区间范围一定要正确
    if(sum <= 1000 && sum >= 1)
        return sum;
    else 
        return 0;


}
int main()
{
    string str;
    getline(cin,str);
    //从左边开始查找第一个空格的下标
    int fla  = str.find(" ");
    //A的值是从下标零开始 截取长度为fla的子串
    string a = str.substr(0,fla);
    //B的值是从下标fla开始向后截取
    string b = str.substr(fla+1);

    int  A = Vlaid(a);
    int  B = Vlaid(b);
    if(A && B){
        cout<<A<<" + "<<B<<" = "<<(A+B)<<endl;
    }
    else 
    {
        if(!A)
            cout<<"?";
        else 
            cout<<a;
        cout<<" + ";

        if(!B)
            cout<<"?";
        else 
            cout<<b;

        cout<<" = ?";
    }   
    return 0; 
}