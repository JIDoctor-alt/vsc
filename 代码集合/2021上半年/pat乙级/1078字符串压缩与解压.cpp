#include<iostream>
#include<string>
using namespace std;
int main()
{
    char c;
    string str;
    cin>>c;
    getchar();
    getline(cin,str);
    string res = "";
    if(c == 'C')
    {
        int num = 1;
        for(int i = 0;i < str.size(); ++i)
        {
            if(i < str.size() - 1 && str[i] == str[i + 1])
            {
                ++num;
            }
            else 
            {
                if(num == 1)
                {
                    res = res + str[i];
                }
                else 
                {
                    res = res  + (to_string(num) + str[i]);
                    num  = 1;
                }
            }
        }
        cout<<res<<endl;
    }
    if(c == 'D')
    {
        int num = 0;
        for(int i = 0;i < str.size(); ++i)
        {
            if(isdigit(str[i]))
            {
                num = num * 10 + (str[i] - 0);
            }
            else 
            {
                if(num == 0)
                {
                    res = res + str[i];
                }
                else 
                {
                    for(int d = 0;d < num;++d)
                    {
                        res = res + str[i];    
                    }

                }
                num = 0; 
            }
        }
        cout<<res<<endl;
    }
    return 0;
}