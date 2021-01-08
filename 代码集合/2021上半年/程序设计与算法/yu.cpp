#include<iostream>
using namespace std;
int N,M;
int cost[100100];
bool Valid(int c)
{
    int m = 1;//总月数
    int curCost = 0;//本月花销
    for(int i = 0;i < N;++i)
    {
        if(cost[i] > c)
            return false;
            //一定要是大于如果是等于也可以算在一个fajo月中！！
        if(curCost + cost[i] > c)
        {
            curCost = cost[i];
            ++m;
            if(m > M)
                return false;
        }
        else 
        {
            curCost += cost[i];
        }
    }
    return true;
}
int main()
{
    cin>>N>>M;
    int L = 1 << 30,R  = 0;
    for(int i = 0;i < N;++i)
    {
        cin>>cost[i];
        L = min(L,cost[i]);
        R += cost[i];
    }
    int lastPos = 0;
    while (L <= R)
    {
        int mid = L + (R-L)/2;
        if(Valid(mid))
        {
            lastPos = mid;
            R = mid - 1;
        }
        else 
        {
            L = mid + 1;
        }
    }
    cout<<lastPos<<endl;
    return 0;
    
}