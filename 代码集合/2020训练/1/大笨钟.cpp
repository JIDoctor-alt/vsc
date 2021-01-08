#include<iostream>
#include<string>
using namespace std;
int main()
{
    int x,y;
    scanf("%d:%d",&x,&y);
    if(x < 12 ||(x == 12 && y == 0))
    {
        cout<<"Only ";
        printf("%02d:%02d",x,y);
        cout<<".  Too early to Dang.\n";
    }
    else 
    {
        int len = (x - 12) + (y != 0 ? 1 : 0);
        for(int i = 0;i < len;++i)
            cout<<"Dang";
    }
    return 0;
}