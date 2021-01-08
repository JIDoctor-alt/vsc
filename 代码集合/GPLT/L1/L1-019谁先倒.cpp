#include<iostream>
using namespace std;
struct node
{
    /* data */
    int f1,f2,a1,a2;
};
//喝醉了才倒下，即超过酒量的时候，而不是等于酒量的时候
node te[110];
int N,x,y;
int main()
{
    cin>>x>>y;
    int s1 = x,s2 = y;
    cin>>N;
    for(int i = 0;i < N;++i){
        cin>>te[i].f1>>te[i].f2>>te[i].a1>>te[i].a2;
    }
    for(int i = 0;i < N;++i){
        int j1,j2,d1,d2;
        j1 = te[i].f1, j2 = te[i].f2;
        d1 = te[i].a1, d2 = te[i].a2;
        int sum = j1 + d1;

        if(j2 == sum && d2 != sum){
            x--;
        }
        if(j2 != sum && d2 == sum){
            y--;
        }
        if(x < 0){
            cout<<"A"<<endl;
            cout<<s2 - y<<endl;
            break;
        }
        if(y < 0){
            cout<<"B"<<endl;
            cout<<s1 - x<<endl;
            break;
        }
    }
    return 0;
}