#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
void Valid(string c){
    int ans = 0;
    double s ;
    int beginS = 0;
    if(c[0] == '-')
        beginS = 1;
    
    int str_len = c.length();
    double num = str_len - beginS;//多少位数
    for(int i = beginS;i < str_len;i++){
        if(c[i] == '2')ans++;
    }
    s = ans/num;//
    //如果是负数乘以1.5
    if(beginS){
        s *= 1.5;
    }

    if((c[str_len - 1] - '0')%2 == 0)
        s *= 2;
    
    s *= 100;
    cout<<fixed<<setprecision(2)<<s<<"%"<<endl;


}
int main(){
    string str;
    getline(cin,str);
    Valid(str);
    return 0;
}