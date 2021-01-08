#include<iostream>
#include<string>
#include<math.h>
#include<iomanip>

using namespace std;
double exp(){
    //读入一个逆波兰表达式，并计算
    char s[20];
    cin>>s;
    switch (s[0])
    {
    case '+': return exp()+exp();
            break;
    case '-': return exp()-exp();
            break;
    case '/': return exp()/exp();
            break;
    case '*':return exp()*exp();
            break;
    default: return atof(s);
        break;
    }
}
int main()
{
    cout<<fixed<<setprecision(6)<<exp();
    return 0;
}
