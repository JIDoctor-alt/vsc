#include<iostream>
#include<string>
#include<numeric>
using namespace std;
int main()
{
    int N;
    cin>>N;
    getchar();
    string str;
    while(N--)
    {
        getline(cin,str);
        int sum1 = 0, sum2 = 0;
        for(int i = 0;i < 3;++i)
        {
            sum1 += (str[i]-'0');
        }
        for(int i = 3;i < str.size();i++)
        {
            sum2 += (str[i]-'0');
        }
        if(sum1 == sum2)
        {
            cout<<"You are lucky!"<<endl;
        }
        else 
        {
            cout<<"Wish you good luck."<<endl;
        }
    }
    return 0;
}