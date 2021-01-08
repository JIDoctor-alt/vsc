#include<iostream>
using namespace std;
void Valid(int f,int h,int w)
{
    int fw,fh;
     if(f == 0)
     {
         fh = 129,fw = 25;
     }
     
    else 
    {
         fh = 130,fw = 27;
    }
   
       if(h > fh)
        {
                cout<<"ni li hai! ";
        }
        else if(h < fh)
        {
                cout<<"duo chi yu! ";
        }
        else 
        {
                cout<<"wan mei! ";
        }
        if(w > fw)
        {
                cout<<"shao chi rou!"<<endl;
        }
        else if(w < fw)
        {
                cout<<"duo chi rou!"<<endl;
        }
        else 
        {
                cout<<"wan mei!"<<endl;
        }
        
}
int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int flag,h,w;
        cin>>flag>>h>>w;
        Valid(flag,h,w);
    }
    return 0;
}