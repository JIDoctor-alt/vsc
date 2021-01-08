#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct node{
    double s,e;
    bool operator < (const node & n)const
    {
        return s  < n.s;
    }
}Stall[1100];

int main()
{
    int n,d;
    int t = 0;
    while(cin>>n>>d && n )
    {
        t++;
        int flag = 0;
        for(int i = 0;i < n;i++)
        {
            double x,y;
            cin>>x>>y;
            //岛屿到平面的距离超过了雷达的距离
            if(y > d){
                flag = 1;
            }
            //勾股定理求出雷达的范围
            double x1 = sqrt(d*d - y*y);
            Stall[i].s = x - x1;
            Stall[i].e = x + x1;
        }
        if(flag){
            cout<<"Case "<<t<<": "<<"-1"<<endl;
            continue;
        }
         //按照起点从小到大排序
        sort(Stall,Stall+n);
        //从第一个岛屿判断（最右边的端点作为判断条件）
        double firstNoConverd = Stall[0].e;
        int ans = 1;
        for(int i = 1;i < n;++i)
        {
            //如果下一个岛屿的最左端在firstNoConverd的左边那么可以被前一个雷达覆盖不用在加雷达
            if(Stall[i].s <= firstNoConverd)
            {
                 //这个时候还要判断这个岛屿的范围
                //如果它的右端点在前一个右端点的前面那么这个firstNoConverd要更新
                firstNoConverd = firstNoConverd < Stall[i].e ? firstNoConverd : Stall[i].e;
            }
            else 
            { //到该岛屿不能被上一个覆盖的时候用新的雷达
                firstNoConverd = Stall[i].e;
                ans++;
            }
        }
        cout<<"Case "<<t<<": "<<ans<<endl;
        
    }
    return 0;
}