#include<iostream>
using namespace std;
int a[10];
int main()
{
    for(int i = 0;i < 10;++i)
    {
        cin>>a[i];
    }
    int sum = 0;
    if(a[0] == 0)
    {
        for(int i = 0;i < 10;++i)
        {
            for(int j = 0;j < a[i];++j)
            {
                sum = sum * 10 + i;
            }
        }
        cout<<sum<<endl;
    }
    else 
    {
        int s;
        for(int i = 1;i < 10;++i)
        {
            if(a[i] != 0)
            {
                s = i;
                --a[i];
                break;
            }
        }
        int sum = s;
        for(int i = 0;i < 10; ++i)
        {
            for(int j = 0;j < a[i];++j)
            {
                sum = sum * 10 + i;
            }
        }
        cout<<sum<<endl;
    }
   
    return 0;
}