#include<iostream>
#include<math.h>
#include<algorithm>
#define LL long long
using namespace std;
//长整型，注意化简，余数不能为零 a%b b不能为零
LL find(LL a,LL b)
{
    if(a < b)
        swap(a,b);
    return b == 0 ? a : find(b,a%b);
}
int main()
{
    LL n;
    scanf("%lld",&n);

    LL denominator= 1,molecule = 0;

    for(LL i = 0;i < n;++i)
    {
        LL x,y,CommonFactor;
        scanf("%lld/%lld",&x,&y);

        CommonFactor = find(abs(x),abs(y));
        if(CommonFactor == 0)
            CommonFactor = 1;
        x /= CommonFactor;
        y /= CommonFactor;

        molecule = molecule*y + x*denominator;
        denominator = denominator * y;

         CommonFactor = find(abs(denominator),abs(molecule));
         if(CommonFactor == 0)
            CommonFactor = 1;

        denominator /= CommonFactor;
        molecule /= CommonFactor;
    }
    LL IntergerNum = molecule/denominator;

    molecule -= (IntergerNum*denominator);
    LL CommonFactor = find(abs(molecule),abs(denominator));
     if(CommonFactor == 0)
            CommonFactor = 1;

    molecule /= CommonFactor;
    denominator /= CommonFactor;

    if(IntergerNum)
    {
               printf("%lld",IntergerNum);
               if(molecule)cout<<" ";
    }


    if(molecule)
       printf("%lld/%lld",molecule,denominator);

    if(IntergerNum == 0 && molecule == 0)
        cout<<"0";
    return 0;
}