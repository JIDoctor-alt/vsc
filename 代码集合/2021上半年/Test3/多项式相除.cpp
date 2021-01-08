#include<iostream>
#include<cmath>
#include<vector>

using namespace std;
double c1[100010],c2[100010],c3[100010];
int max1 = 0,max2 = 0,N1,N2;
int printNum(double w[])
{
    int ans = 0;
    for(int i = max1;i >= 0;i--)
        if(abs(w[i])+0.05 > 0.1)ans++;
    return ans;//返回有多少项
}
void printfResul(double u[])
{
    int cnt = printNum(u);
    if(!cnt){
        cout<<"0 0 0.0"<<endl;
    }else{
        cout<<cnt;
        for(int i = max1;i >= 0;i--)
        {
            if(abs(u[i]) +0.05 > 0.1)
                printf(" %d %.1f",i,u[i]);
        }
         cout<<endl;
    }
   
}
int main(){
    cin>>N1;
    
    for(int i = 0;i < N1;i++)
    {
        int e,c;
        cin>>e>>c;
        c1[e] = c;
        max1 = max1 > e ? max1 : e;
    }
    cin>>N2;
    
    for(int i = 0;i < N2;i++)
    {
        int e,c;
        cin>>e>>c;
        c2[e] = c;
        max2 = max2 > e ? max2 : e;
    }
    int t1 = max1,t2 = max2;
    // int tq = t1 - t2;
    while(t1 >= t2)
    {
       
        //商的系数
        double q  = c1[t1]/c2[t2];
        c3[t1-t2] = q;//商为指数幂相减
        for(int i = t1,j=t2;j >= 0;j--,i--)
        {
            //求余数
            //系数 为  被除数 减去 除数乘以商（指数是从
            //被除数算起，没有减去的部分保持原来的不变)
            c1[i] -= q*c2[j];
        }
       // while (abs(c[t1]) < 0.1)t1--;
       t1--;//余数降幂
    }
    printfResul(c3);
    printfResul(c1);

    

    return 0;
}