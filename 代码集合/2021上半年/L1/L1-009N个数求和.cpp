#include<iostream>
using namespace std;
long long getInt(long long  a,long long  b)
{
    if(a < b)
        swap(a,b);
    return b == 0 ? a : getInt(b,a%b);
    /*if(a < b)//较大的数作为被除数
        swap(a,b);
    while(b)
    {
        int t = b;
        b = a%b;
        a = t;
    }
    return a;*/
}
int main()
{
    long long N;
   // cin>>N;
    scanf("%lld",&N);
    long long  f1 = 0, f2 = 1,gcdvalue;
 
    while (N--)
    {
        long long  a,b;
        //cin>>a>>b;
        scanf("%lld/%lld",&a,&b);
        
        gcdvalue = (f1 == 0 || f2 == 0) ? 1 : getInt(abs(f1),abs(f2));
        f1 /= gcdvalue;
        f2 /= gcdvalue;

        gcdvalue = (a == 0 || b == 0) ? 1 : getInt(abs(a),abs(b));
        a /= gcdvalue;
        b /= gcdvalue;

        f1 = a * f2 + b * f1;
        f2 = b*f2;

    }
    long long  intNum = f1 / f2;
    f1  -= f2*intNum;//分子
    long long  gongyinzi = (f1 == 0 || f2 == 0)? 1 : getInt(abs(f1),abs(f2));//最大公因子
    //约分
    f1 /= gongyinzi;
    f2 /= gongyinzi;
    if(intNum){
        //  cout<<intNum;
      printf("%lld",intNum);
      if(f1)
        cout<<" ";
       else 
        cout<<endl;
    }
      
    
     
    if(f1)
      //  cout<<" "<<f1<<"/"<<f2<<endl;
      printf("%lld/%lld",f1,f2);
    
    if(intNum == 0 && f1 == 0)
        cout<<"0";
    return 0;
}


