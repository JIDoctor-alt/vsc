#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    int indexE = str.find('E');
    int indexPoint = str.find('.');
    int doublePoint = indexE - indexPoint - 1;//小数点后几位
    double Pd = 0.1;
    for(int i = 1;i < doublePoint;++i)
    {
        Pd *= 0.1;
    }
    string Enum = str.substr(indexE + 2);
    int Enumber = stoi(Enum);//指数部分
    int num = 0;

    for(int i = 1;i < indexE;++i)
    {
        if(str[i] != '.')
        {
            num = num * 10 + (str[i] - '0');
        }
    }
    double sum = num * Pd;
    if(str[0] == '-')
         sum = 0 - sum;
    if(str[indexE + 1] == '-')
    {
        int w = doublePoint + Enumber;
        for(int i = 1;i <= Enumber;++i)
        {
            sum *= 0.1;
        }
        cout<<fixed<<setprecision(w)<<sum<<endl;   
    }
    else 
    {
        int w = Enumber - doublePoint;
        if(w <= 0)
        {
            for(int i = 0;i < -w;++i)
            {
                sum *= 0.1;
            }
            cout<<fixed<<setprecision(-w)<<sum<<endl;
        }
        else 
        {
            for(int i = 0;i < w;++i)
            {
                sum *= 10;
            }
            cout<<sum<<endl;
        }
    }
    

    return 0;
}