#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int a[205];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        fill(a , a + 205, 0);
        int m;
        cin>>m;
        for(int i = 0; i < m;++i)
        {
            int x, y;
            cin>>x>>y;
            if(x > y)
            {
                swap(x,y);
            }
            x = (x + 1)/2 , y = (y + 1)/2;
            for(int e = x ; e <= y; ++e)
            {
                ++a[e];
            }
        }
        cout<<10*(*max_element(a, a + 205))<<endl;
    }
    return 0;
}