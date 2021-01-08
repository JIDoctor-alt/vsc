#include<iostream>
using namespace std;
int total,num;
int main()
{
    cin>>total>>num;
    for(int i = 1;i <= num;++i)
    {
        if(i % 2 == 1)
        {
            total = total;
        }
        else 
        {
            total += total;
        }
    }
    int flag = 0;
    if(num % 2 != 0)
            flag = 1;
    cout<<flag<<" "<<total<<endl;
    return 0;
}