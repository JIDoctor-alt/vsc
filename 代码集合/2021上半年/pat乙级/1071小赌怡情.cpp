#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_V  = 110;
struct  edge
{
    int n1,b,t,n2;
};
edge stu[MAX_V];
int main()
{
    int T,K;
    cin>>T>>K;
    for(int i = 0;i < K;++i)
    {
       cin>>stu[i].n1>>stu[i].b>>stu[i].t>>stu[i].n2;
    }

    for(int i = 0;i < K;++i)
    {

        int x1 = stu[i].n1;//第一个数
        int y = stu[i].b ;//大小
        int  num = stu[i].t;//筹码
        int x2 = stu[i].n2;//第二个数
       

        if(num > T && T != 0)
        {

            cout<<"Not enough tokens. Total = "<<T<<"."<<endl;

        }
        else if(num < T)//筹码数足够
        {


            if((x2 < x1 && y == 0) ||(x2 > x1 && y == 1))
            {

                T += num;
                cout<<"Win "<<num<<"! Total = "<<T<<"."<<endl;

            }
            else 
            {

                T -= num;
                cout<<"Lose "<<num<<". Total = "<<T<<"."<<endl;
            }

        }
        if(T == 0)
        {
            
            
            cout<<"Game Over."<<endl;
            break;
        }
        
    }
    return 0;
}