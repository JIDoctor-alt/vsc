#include<iostream>
using namespace std;
int fun(int x,int y)
{
    if(x < y)
        swap(x,y);
    while(y)
    {
        int c = y;
        y = x % c;
        x = c;
    }
    return x;
}
int main()
{
    int a1,b1,a2,b2;
    scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2);

    return 0;
}