#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int N;
int a[1010];
int main()
{
    cin>>N;
    int b1 = 0, ans = 0,b2 = 0,b3 = 0,ans4 = 0,b5 = -1;
    double b4 = 0;
    vector<int> st;
    for(int i = 0;i < N;++i)
    {
        cin>>a[i];
        if(a[i] % 5 == 0 && a[i] % 2 == 0)
        {
            b1 += a[i];
        }
        if(a[i] % 5 == 1)
        {
            ++ans;
            if(ans % 2 == 0)
            {
                b2 -= a[i];
            }
            else 
            {
                b2 += a[i];
            }
            st.push_back(a[i]);
        }
        if(a[i] % 5 == 2)
        {
            ++b3;
        }
        if(a[i] % 5 == 3)
        {
            ++ans4;
            b4 += a[i];
        }
        if(a[i] % 5 == 4)
        {
            if(b5 < a[i])
            {
                b5 = a[i];
            }
        }
    }
    b4 /= ans4;
    if(b1 == 0)
    {
        cout<<"N";
    }
    else 
    {
        cout<<b1;
    }
    cout<<" ";
    if(ans == 0)
    {
        cout<<"N ";
    }
    else
    {
        cout<<b2<<" ";
    }
    if(b3 == 0)
    {
        cout<<"N ";
    }
    else 
    {
        cout<<b3<<" ";
    }
    if(ans4 == 0)
    {
        cout<<"N ";
    }
    else 
    {
        cout<<fixed<<setprecision(1)<<b4<<" ";
    }

    if(b5 == -1)
    {
        cout<<"N";
    }
    else 
    {
        cout<<b5;
    }
    return 0;
}