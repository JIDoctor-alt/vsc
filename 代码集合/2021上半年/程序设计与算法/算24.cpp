#include<iostream>
#include<cmath>

#define EPS 1e-6
using namespace std;
double a[5];
//判断是否为零
bool Zero_Count(double x){
    //注意绝对值
    return abs(x) <= EPS;
}
//计算数组中的数是否能够为24
bool CountResult(double a[],int n)
{   
    //如果数组中只有一个元素了，那么就判断是否为24
    if(n == 1)
    {
        if(Zero_Count(a[0] - 24))
            return true;
        else return false;
    }
    double b[5];
    //用两重循环来枚举两个数之间进行运算
    
    for(int i = 0;i < n-1;i++)
        for(int  j = i+1;j < n;j++){
            int m = 0;
            //将将枚举的结果存入b数组中
           for(int k = 0;k < n;k++)
                //先将没有参加运算的数存入数组
                if(k != i && k != j)
                    b[m++] = a[k]; 
                //对两个数进行运算 
                
                    b[m] = a[i]+a[j];
                if(CountResult(b,m+1))return true;
                //减法有两种情况
                    b[m] = a[i] - a[j];
                if(CountResult(b,m+1))return true;
                    b[m] = a[j] - a[i];
                if(CountResult(b,m+1))return true;
                    b[m] = a[i]*a[j];
                if(CountResult(b,m+1))return true;

                //除法也有两种情况
                if(!Zero_Count(a[j])){
                    b[m] = a[i]/a[j];
                  if(CountResult(b,m+1))return true;
                }
                 if(!Zero_Count(a[i])){
                    b[m] = a[j]/a[i];
                   if(CountResult(b,m+1))return true;
                }
                 
            
        }
          return false; 
}
int main()
{
    while(true)
    {
        for(int i = 0;i < 4;i++)
        cin>>a[i];
        if(Zero_Count(a[0]))break;
        if(CountResult(a,4))
            cout<<"YES"<<endl;
        else 
            cout<<"NO"<<endl;
    }
    

    return 0;
}