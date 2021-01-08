#include<iostream>
#include<algorithm>
using namespace std;
const int max_num = 100001;
double c1[max_num],c2[max_num],c3[max_num];
//A 除以 B
int max1 ,max2;
int printNum(double w[])
{
    int ans  = 0;
    for(int i = max1;i >= 0;--i)
        if(abs(w[i]) + 0.05 > 0.1)//精确到0.0 ,必须最小为0.1
            ++ans;
    return ans;
}
void printPa(double u[])
{
    int cnt = printNum(u);
    if(!cnt)
    {
        cout<<"0 0 0.0"<<endl;//：零多项式是一个特殊多项式，对应输出为0 0 0.0
    }
    else 
    {
        cout<<cnt;
        for(int i = max1;i >= 0;--i)
        {
            if(abs(u[i]) + 0.05 > 0.1)
                printf(" %d %.1f",i,u[i]);
        }
        cout<<endl;
    }
}
int main()
{
    int x;
    cin>>x;
    int t1 = -1,t2 = -1;
    for(int i = 0;i < x;++i)
    {
        int e1,cx;
        cin>>e1>>cx;
        if(t1 == -1)
            t1 = e1;
        c1[e1] = cx;
    }
    cin>>x;
    for(int i = 0;i < x;++i)
    {
        int e2,cx;
        cin>>e2>>cx;
            if(t2 == -1)
                t2 = e2;
        c2[e2] = cx;
    }
    max1 = t1,max2 = t2;
    while(t1 >= t2)
    {
        double q = c1[t1]/c2[t2];
        c3[t1 - t2] = q;
        for(int i = t1,j = t2; j >= 0;j--,i--)
        {
            c1[i] -= q*c2[j];
        }
        --t1;
    }
    printPa(c3);
    printPa(c1);
    return 0;
}