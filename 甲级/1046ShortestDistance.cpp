#include<iostream>
#include<algorithm>
using namespace std;
int dis[100005];
int main()
{
    int n;
    cin>>n;
    int sum = 0;
    for(int i = 1;i <= n;++i)
    {
       cin>>dis[i];
       sum += dis[i];
       dis[i] = sum;
    }
    int k;
    cin>>k;
    while(k--)
    {
        int x,y;
        cin>>x>>y;
        if(x > y)
            swap(x,y);
        int temp = dis[y - 1] - dis[x-1];
        cout<<min(temp,sum - temp)<<endl;
    }
    return 0;
}