#include<iostream>
#include<cmath>
#define MAX_f 100005
using namespace std;
double c1[MAX_f],c2[MAX_f],c3[MAX_f];//1,2,商
int t1 = 0,t2 = 0;

int legalNum(double xtest[],int nx)
{
    int cnt = 0;

    for(int  i = nx ; i >= 0;--i)
    {
        double tes = abs(xtest[i]) + 0.05;
        if(tes >= 0.1)
            ++cnt;
    }
    return cnt;
}

void PrintResult()
{
    int ans = legalNum(c3,t1);
    if(ans == 0)
    {
        cout<<"0 0 0.0";
    }
    else 
    {
        cout<<ans;
        for(int i = t1; i >= 0;--i)
        {
            double pte = abs(c3[i]) + 0.05;
            if(pte >= 0.1)
                printf(" %d %.1f",i,c3[i]);
        }
    }
    cout<<endl;
    ans = legalNum(c1,t1);
    if(ans == 0)
    {
        cout<<"0 0 0.0\n";
    }
    else 
    {
        cout<<ans;
        for(int i = t1;i >= 0;--i)
        {
            double pte = abs(c1[i]) + 0.05;
            if(pte >= 0.1)
                printf(" %d %.1f",i,c1[i]);
        }
        cout<<endl;
    }
    

}
int main()
{
    int n1;
    cin>>n1;
    for(int i = 0;i < n1;++i)
    {
        int exnumber;
        double cxnumber;
        cin>>exnumber>>cxnumber;
        if(t1 == 0)
            t1 = exnumber;
        c1[exnumber] = cxnumber;
    }
    int n2;
    cin>>n2;
    for(int i = 0;i < n2;++i)
    {
        int exnumber;
        double cxnumber;
        cin>>exnumber>>cxnumber;
        if(t2 == 0)
            t2 = exnumber;
        c2[exnumber] = cxnumber;
    }
    int m1 = t1,m2 = t2;
    while(m2 <= m1)
    {
        double cx = c1[m1]/c2[m2];

        c3[m1 - m2] = cx;

        for(int i = m1,j = m2;i >= 0 &&j >= 0;--i,--j)
        {
            c1[i] -= c2[j] * cx;
        }
        m1--;
    }

    PrintResult();
    return 0;
}
