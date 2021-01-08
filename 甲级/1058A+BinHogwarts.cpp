#include<iostream>
#include<string>
using namespace std;
int main()
{
    int a1,a2,a3,b1,b2,b3;
    scanf("%d.%d.%d %d.%d.%d",&a1,&a2,&a3,&b1,&b2,&b3);
    int digit;
    digit = (a3 + b3) / 29;
    a3 = (a3 + b3) % 29;
    int sum = a2 + b2 + digit;
    a2 = sum % 17;
    digit = sum / 17;
    a1 = (a1 + b1 + digit);

    printf("%d.%d.%d",a1,a2,a3);
    return 0;
}