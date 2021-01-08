#include<iostream>
#include<string>
using namespace std;
void printRes(int ans)
{
     if(ans <= 3)
            {
                for(int j = 0;j < ans;++j)
                {
                    cout<<"6";
                }
            }
            else if(ans > 3 && ans <= 9)
            {
                cout<<9;
            }
            else 
            {
                cout<<27;
            }
}
int main()
{
    string str;
    getline(cin,str);
    int ans = 0;
    for(int i = 0;i < str.size();++i)
    {
        if(str[i] == '6')
        {
            ans++;
        }
        else 
        {
            printRes(ans);
            ans = 0;
            cout<<str[i];
        }
    }
    if(ans > 0)
    {
            printRes(ans);
    }
    return 0;
}