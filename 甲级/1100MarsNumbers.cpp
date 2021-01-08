#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string onedig[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string secdig[13] = {"###","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
int N;
//注意，还有个数字0没有考虑，因为数字0取余13等于0，但是要特别输出tret，所以在func1的最后一句判断中加一句t == 0，
//并将a[0]位赋值成tret即可解决0的问题～
void fun1(string str)
{
    int  num = stoi(str);

    int firstdigit = num % 13;
    int seconddigit = num / 13;
    if(seconddigit)
    {
        cout<<secdig[seconddigit];
    }
    if((seconddigit)&&(firstdigit))
        cout<<" ";
    if(firstdigit || num == 0)
          cout<<onedig[firstdigit];
}
void fun2(string str)
{
    int  t1 = 0, t2  = 0;
    string s1 = str.substr(0,3),s2;

    if(str.length() > 4)
        s2 = str.substr(4,3);

    for(int j = 1;j <= 12;++j)
    {
        if(s1 == onedig[j] || s2 == onedig[j]) 
            t2 = j;

        if(s1 == secdig[j])
            t1 = j;
    }
    cout<<t1 * 13 + t2;
}
int main()
{
   cin>>N;
   getchar();
   while(N--)
   {
       string str;
       getline(cin,str);
       string s1,s2;
       if(isdigit(str[0]))
       {
            fun1(str);
       }
       else 
       {
           fun2(str);
       }
       cout<<endl;
   }
    return 0;
}