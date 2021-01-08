#include<iostream>
#include<string>
using namespace std;
int book[10];
int main()
{
    string num;
    cin>>num;

    int digit = 0;

    int l = int(num.size());
    for(int i = l - 1;i >= 0;--i)
    {
        int temp = num[i] - '0';
        book[temp]++;

        temp = temp * 2 + digit;

        digit = temp/10;//进位
        temp = temp % 10;//当前位
        num[i] = (temp + '0');
        
        book[temp]--;
    }
    int flag = 0;
    for(int i = 0;i < 10;++i)
    {
        if(book[i] != 0)
            flag = 1;
    }
    cout<<((flag == 1 || digit == 1) ? "No\n" : "Yes\n");
    if(digit == 1)
        cout<<"1";
    cout<<num<<endl;
    return 0;
}