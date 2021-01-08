#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int N;
    char c;
    cin>>N>>c;
    if(N < 7)
    {
        cout<<c<<endl;
        cout<<(N - 1)<<endl;
    }
    else 
    {
        int ans = 1, i = 1;
        while (ans <= N)
        {
            ++i;
            ans += 2 * (2 * i - 1);
        }
        if(ans > N)
        {
            ans -= 2*(2*i - 1);
            --i;
        }
        int nx = i;
        for(int k = 1;k <= nx;++k)
        {
            for(int j = 1;j < k;++j)
            {
                cout<<" ";
            }
            for(int j = 0;j < 2*(nx-k) + 1;++j)
            {
                cout<<c;
            }
            cout<<endl;
        }
        for(int k = 1; k < nx;++k)
        {
            for(int j = 1;j < nx - k;++j)
            {
                cout<<" ";
            }
            for(int j = 0;j < 2*k + 1;++j)
            {
                cout<<c;
            }
            cout<<endl;
        }
        cout<<(N - ans)<<endl;
        
    }
    return 0;
}