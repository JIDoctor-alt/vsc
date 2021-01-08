#include<iostream>
#include<string>
using namespace std;
int main()
{
    int p1,p2,p3,a1,a2,a3;
    scanf("%d.%d.%d %d.%d.%d",&p1,&p2,&p3,&a1,&a2,&a3);
    int sum1 = p1*17*29 + p2 * 29 + p3;
    int sum2 = a1*17*29 + a2 * 29 + a3;
    int res = sum2 - sum1;
    if(res < 0)
    {
        res = 0 - res;
        int pp1 = res / 17.0 / 29.0;
        int pp2 = (res - pp1*17*29)/29;;
        int pp3 = (res - pp1*17*29 - pp2*29);
        printf("-%d.%d.%d",pp1,pp2,pp3);
    }
    else 
    {
        int pp1 = res / 17.0 / 29.0;
        int pp2 = (res - pp1*17*29)/29;;
        int pp3 = (res - pp1*17*29 - pp2*29);
        printf("%d.%d.%d",pp1,pp2,pp3);
    }
    return 0;
}