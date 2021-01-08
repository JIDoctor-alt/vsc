#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    string a;
    char b[50];
    int N,ans = 0;
    cin>>N;
    double temp = 0,sum = 0;
    for(int i = 0;i < N;++i)
    {
        cin>>a;
        sscanf(a.c_str(),"%lf",&temp);//以%lf的形式存入temp
        sprintf(b,"%.2f",temp);//以%.2f输出到b
        int flag = 0;
        for(int j = 0;j < a.size();++j)
        {
            if(a[j] != b[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag || temp < -1000 || temp > 1000)
        {
            cout<<"ERROR: "<<a<<" is not a legal number\n";
        }
        else 
        {
            sum += temp;
            ++ans;
        }
    }
    if(ans == 0)
    {
        cout<<"The average of "<<ans<<" numbers is Undefined\n";
    }
    else 
    {
        double ave = sum/ans;
        cout<<"The average of "<<ans<<" number"<<(ans == 1 ? "" : "s")<<" is ";
        printf("%.2f\n",ave);
    }
    return 0;
}