#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a1,a2;
    cin>>a1>>a2;
    int r[a1][a2];
    for(int i = 0;i < a1 ;++i)
    {
        for(int j = 0;j < a2;++j)
        {
            cin>>r[i][j];
        }
    }
    
    int b1,b2;
    cin>>b1>>b2;
    int c[b1][b2];
    for(int i = 0;i < b1;++i)
    {
        for(int j = 0;j < b2;++j)
        {
            cin>>c[i][j];
        }
    }
    if(a2 != b1)
    {
        cout<<"Error: "<<a2<<" != "<<b1<<endl;
    }
    else 
    {
        cout<<a1<<" "<<b2<<endl;
        for(int i = 0;i < a1 ;++i)
        {
            
            for(int j = 0;j < b2;++j)
            {
                int sum = 0;
                for(int k = 0;k < a2;++k)
                {
                    sum += r[i][k]*c[k][j];
                }
                if(j!=0)
                    cout<<" ";
                cout<<sum;
            }
            cout<<endl;
        }
    }
    return 0;
}