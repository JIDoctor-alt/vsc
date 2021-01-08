#include<iostream>
using namespace std;
char a[4][4],flag;
bool judge()
{
   for(int i = 0;i < 3;++i)
   {
       if(a[i][0] == a[i][1] && a[i][0] == a[i][2] && a[i][0] != 'O')
       {
            flag = a[i][0];
            return true;
       }
   }

   for(int i = 0;i < 3;++i)
   {
       if(a[0][i] == a[1][i] && a[0][i] == a[2][i] && a[0][i] != 'O')
       {
            flag = a[0][i];
            return true;
       }
   }

   if(a[0][0] == a[1][1] && a[0][0] == a[2][2] && a[0][0] != 'O')
    {
        flag = a[0][0];
        return true;
    }
    if(a[0][2] == a[1][1] && a[0][2] == a[2][0] && a[0][0] != 'O')
    {
        flag = a[0][0];
        return true;
    }
    return false;
}
int main()
{

    for(int i = 0;i < 3;++i)
    {
        for(int j = 0;j < 3;++j)
            cin>>a[i][j];
    }
    judge();
    if(flag == 'B')
        cout<<"BoBo wins!";
    else if(flag == 'K')
        cout<<"KiKi wins!";
    else 
        cout<<"No winner!";
    return 0;
}