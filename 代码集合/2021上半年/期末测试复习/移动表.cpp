#include<iostream>
#include<algorithm>
using namespace std;
int a[1002];
int main()
{
    int T;
    cin>>T;
    int N;
    while(T--)
    {
        cin>>N;
        int x,y;
        fill(a,a + 1002,0);
        for(int i = 0;i < N;++i)
        {
            cin>>x>>y;
            x = (x + 1)/2, y = (y + 1)/2;
            if(x > y)
                swap(x,y);
            for(int e = x ;e <= y;++e)
            {
                ++a[e];
            }
        }
        cout<<10*(*max_element(a,a + 1002))<<endl;
    }
}