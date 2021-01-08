#include<iostream>

using namespace std;
long long gcd(long long  a,long long b){
    return b == 0 ? a : gcd(b,a%b);//求最大公因子
}
int main(){
    long long n,a,b,suma = 0,sumb = 1,gcdvalue;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a>>b;
        //先判断分子分母的最大公因子
        gcdvalue = (suma == 0|| sumb == 0)? 1 : gcd(abs(suma),abs(sumb));
        sumb = sumb/gcdvalue;
        suma = suma/gcdvalue;
        
        gcdvalue = (a == 0||b == 0) ? 1 : gcd(abs(a),abs(b));
        //在判断数据的最大公因子
        a = a/gcdvalue;//分子
        b = b/gcdvalue;//分母
        suma = a * sumb +suma *b;
        sumb = b * sumb;
    }

    long long interger = suma / sumb;//结果的整数部分
    suma = suma - (sumb * interger);//分母
    //判断一下最大公因子 化简
    gcdvalue = (suma == 0 || sumb == 0) ? 1 : gcd(abs(suma),abs(sumb));
    suma = suma / gcdvalue;
    sumb = sumb / gcdvalue;
    if(interger != 0){///整数部分
        cout<<interger;
        if(suma!=0)
            cout<<" ";
    }
    //判断分子是否为0
    if(suma!= 0)
        cout<<suma<<"/"<<sumb;
    if(interger == 0 && suma == 0)
        cout<<"0";
    return 0;
}