#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX_N = 100005;
int N;
double C1[MAX_N],C2[MAX_N],E1[MAX_N],E2[MAX_N],C3[MAX_N];
int t1 = 0,t2 = 0;
int ansNum(double a[])
{
    int ans  = 0;
    for(int i = t1;i >= 0;--i){
        double c = abs(a[i]) + 0.05;
        if(abs(a[i]) >= 0.1)
            ++ans;
    }
    return ans;
}
void printPre(){
    
    int x = ansNum(C3);
    if(x == 0)
    {
        cout<<"0 0 0.0"<<endl;
    }else{
        cout<<x;
        for(int i = t1;i >= 0;--i){

            double c = (abs(C3[i]) + 0.05);
            if(abs(C3[i]) >= 0.1)
                printf(" %d %.1f",i,C3[i]);
        }
        cout<<endl;
    }
     x = ansNum(C1);
    if(x == 0)
    {
        cout<<"0 0 0.0"<<endl;
    }
    else{
        cout<<x;
        for(int i = t1;i >= 0;--i){
            int c = (abs(C1[i]) + 0.05);
            if(c >= 0.1)
                printf(" %d %.1f",i,C1[i]);
        }
        cout<<endl;
    }
}
int main()
{
    int n1;
    cin>>n1;
    for(int i = 0;i < n1;++i){
        int x;double y;
        cin>>x>>y;
        if(t1 == 0)
            t1 = x;
        C1[x] = y; 
    }
    int n2;
    cin>>n2;
    for(int i = 0;i < n2;++i)
    {
        int x;double y;
        cin>>x>>y;
        if(t2 == 0)
            t2 = x;
        C2[x] = y;
    }

    int m1 = t1,m2 = t2;
    int t  = m2;
    
    while(m1 >= m2){

        double x = C1[m1]/C2[m2];

        C3[m1 - m2] = x;//公因子


        for(int i = m1,j = t2;i >= 0 &&j >= 0;--i,--j){
            C1[i] -= C2[j] * x;
        }

        m1--;
    }
    printPre();

    return 0;
}