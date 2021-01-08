#include<iostream>
#include<algorithm>
using namespace std;
int flag[2];
int main()
{
    int pa,pb;
    cin>>pa>>pb;
    for(int i = 0;i < 3;++i)
    {
        int id;
        cin>>id;
        flag[id]++;
    }
    if((flag[0] > 0 && pa > pb)||(flag[0] ==3))
    {
        cout<<"The winner is a: "<<pa<<" + "<<flag[0]<<endl;
    }
    else 
    {
        cout<<"The winner is b: "<<pb<<" + "<<flag[1]<<endl;
    }
    return 0;
}