#include<iostream>
using namespace std;
int a[100010];
int main()
{
    ios::sync_with_stdio(false);
    int N;
    cin>>N;

    int P;
    cin>>P;
    for(int i = 0;i < N;++i)
    {
        cin>>a[i];
    }
    int ans = 0;
    for(int i = 0;i < N - 1;++i)
    {
        for(int j = i + 1;j < N;++j)
        {
            int x = a[i], y = a[j];
            if(x + y > P && x + P > y && y + P > x)
            {
                ++ans;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}