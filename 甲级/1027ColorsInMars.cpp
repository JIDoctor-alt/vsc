#include<iostream>
#include<vector>
using namespace std;
int getRadix(int x)
{
    return (x/13)*10 + (x%13);
}
char signTable[14] ="0123456789ABC";
int main()
{
    int a,b,c;
    cin>>a>>b>>c;


    printf("#");
    printf("%c%c%c%c%c%c",signTable[a/13],signTable[a%13],signTable[b/13],signTable[b%13],signTable[c/13],signTable[c%13]);
    return 0;
}