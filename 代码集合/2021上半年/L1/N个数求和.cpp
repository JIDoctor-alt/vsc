#include<iostream>
using namespace std;
long long gcd(long long a,long long b)
{
    return b == 0 ? a : gcd(b,a%b);
}
int main()
{
    long long n,a,b,suma = 0,sumb = 1,gcdvalue;
    cin>>n;
    //scanf("%lld",&n);
    for(int i = 0;i < n;++i)
    {
        cin>>a>>b;
       // scanf("%lld/%lld",&a,&b);
        gcdvalue = (suma == 0|| sumb == 0) ? 1 : gcd(abs(suma),abs(sumb));
        sumb = sumb / gcdvalue;
        suma = suma / gcdvalue;

        gcdvalue = (a == 0 || b == 0) ? 1 : gcd(abs(a),abs(b));

        a = a/gcdvalue;
        b = b/gcdvalue;
        suma = a*sumb + suma * b;//分子相加
        sumb = b * sumb;//分母相乘
    }


    long long interger = suma / sumb;//结果取整数
    suma = suma - (sumb * interger);//分子化简

    //取整后化简分子分母
    gcdvalue = (suma == 0 || sumb == 0) ? 1 : gcd(abs(suma),abs(sumb));
    suma = suma / gcdvalue;
    sumb = sumb / gcdvalue;
    if(interger != 0)
    {
        //cout<<interger;
        printf("%lld",interger);
        if(suma != 0)
            cout<<" ";
    }
    if(suma != 0)
        //cout<<suma<<"/"<<sumb;
        printf("%lld/%lld",suma,sumb);
    if(interger == 0 && suma == 0)
        cout<<"0";
    return 0;
}