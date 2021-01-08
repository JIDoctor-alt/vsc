#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int N;
    int a,b;
    cin>>N>>a>>b;
    int sum = 0,init = 0;

    while(true)
    {
        if(a == 0 && b == 0)
            break;
        int x = N%10;
        if(x == 0)
        {
            x = 10;
        }
        N /= 10;
        int w1 = a%10, w2 = b%10;
        sum = sum * 10 + (w1 + w2 + init)%x;
             cout<<"_____"<<endl;
         cout<<"zhi: "<<(w1 + w2 + init)%x<<endl;
        init = (w1 + w2) /x;
        a /= 10;
   
         
                        cout<<"jinwei: "<<(w1 + w2 + init)/x<<endl;
              cout<<"x:"<<x<<endl;
        cout<<"init:"<<init<<endl;
        b /= 10;
    }
    cout<<sum<<endl;
}