#include<iostream>
#include<string>
using namespace std;
int main()
{
    int N;
    cin>>N;
    getchar();
    string str;
    for(int i = 0;i < N;++i)
    {
        getline(cin,str);
        bool isEg = false ,isNm = false,isCo = false;
        for(int j = 0;j < str.size();++j)
        {
            if(isdigit(str[j]))
                isNm = true;
            if(isalpha(str[j]))
                isEg  = true;
            if(!isalnum(str[j]) && str[j] != '.')
                isCo = true;//不合法字符
        }
        if(isNm && isEg &&!isCo)
        {
            if(str.size() < 6)
            {
                cout<<"Your password is tai duan le."<<endl;
            }
            else if(str.size() <= 80 && str.size() >= 6)
            {
                cout<<"Your password is wan mei."<<endl;
            }
        }
        else if(isCo && str.size() >= 6)
        {
            cout<<"Your password is tai luan le."<<endl;
        }
        else if(!isNm && isEg&& str.size() >= 6)
        {
            cout<<"Your password needs shu zi."<<endl;
        }
        else if(!isEg && isNm &&  str.size() >= 6)
        {
            cout<<"Your password needs zi mu."<<endl;
        }

    }
    return 0;
}