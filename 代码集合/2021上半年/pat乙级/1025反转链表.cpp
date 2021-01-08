#include<iostream>
#include<iomanip>
#include<numeric>
using namespace std;
const int Max_P = 100005;
int ptr[Max_P];
int ntr[Max_P];
int data[Max_P];
int main()
{
    int head,N,K;
    cin>>head>>N>>K;
    for(int i = 0;i < N;++i)
    {
        int address,d,next;
        cin>>address>>d>>next;
        ntr[address] = next;
        data[address] = d;
        ptr[next] = address;
    }
        int rhtr = head;
        for(int i = 1; i< K;++i)
        {
            rhtr = ntr[rhtr];
        }
        ptr[head] = ntr[rhtr];
  //      cout<<"======================="<<endl;
        int move_tr = rhtr;
       while(move_tr != ptr[head])
       {
           cout<<fixed<<setw(5)<<setfill('0')<<move_tr<<" ";
           cout<<data[move_tr]<<" ";
           if(ptr[move_tr] != -1)
            cout<<fixed<<setw(5)<<setfill('0')<<ptr[move_tr]<<endl;
            else
                cout<<"-1"<<endl;
            move_tr = ptr[move_tr];
       }
       while(move_tr != -1)
       {
            cout<<fixed<<setw(5)<<setfill('0')<<move_tr<<" ";
            cout<<data[move_tr]<<" ";
            if(ntr[move_tr] != -1)
             cout<<fixed<<setw(5)<<setfill('0')<<ntr[move_tr]<<endl;
            else 
                cout<<"-1"<<endl;
            move_tr = ntr[move_tr];
       }
    
    return  0;
}