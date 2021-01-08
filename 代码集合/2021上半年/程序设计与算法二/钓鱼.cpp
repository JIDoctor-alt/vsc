#include<iostream>
#include<queue>
#include<cstring>

#include<utility>
#include<functional>
using  namespace std;
using pii = pair<int,int>;
//每个湖第一个时间片的钓鱼量f[i]，  每次减少d[i],湖之间的距离dis[i]
int f[10010],d[10010],t[10010];

int result[10010];//结果存储最后每个湖呆的时间
int maxresult;//结果存储最大的钓鱼量

//测试结果 用来保存每次测试时（各个湖所呆的时间）
int testTime[10010];
int testCount;//测试的最大钓鱼量
bool operator<(const pii & a,const pii & b)
{
    if(a.second == b.second)
        return a.first > b.first;
    else 
        return a.second < b.second;
}
int main()
{
    //n个湖，钓鱼的时间h
    int n;
    while (cin>>n && n)
    {
        maxresult  = 0;
        int timeNum;
        cin>>timeNum;
        //将小时转换成时间片 1个小时12个时间片
        timeNum *= 12;




        for(int i = 0;i < n;++i)
            cin>>f[i];
        for(int i = 0;i < n;++i)
            cin>>d[i];
        for(int i = 0;i < n-1;++i)
            cin>>t[i];
        
        //枚举第i个湖为终点
        for(int i = 0;i < n;++i)
        {
           //测试数组
            memset(testTime,0,sizeof(testTime));
            testCount = 0;

           
            
            //去除走路时间 (这里保留的是钓鱼的时间)
            if(i>0)timeNum -= t[i-1];


             //保存每个湖的最大钓鱼量
            priority_queue<pii> pq;
            //初始化最大钓鱼量
            for(int j = 0;j <= i;++j)
                pq.push({j,f[j]});
                
                //剩下的时间片 ,每个时间片选取最大的鱼量
            for(int j = 0;j < timeNum;j++)
            {
                auto v = pq.top();
                pq.pop();

                //每个湖呆的时间
                testTime[v.first] += 5;
                //最大钓鱼量
                testCount += v.second;
                
                //这里的钓完之后鱼量可能为负数
                v.second -= d[v.first];
                if(v.second < 0)v.second = 0;
                //改湖的鱼量减少d[i]
                pq.push({v.first,v.second});
            }

            //选取最大的钓鱼量
            if(maxresult < testCount)
            {
                maxresult = testCount;
                //结果数组重新赋值
                for(int j = 0;j < n;j++)
                    result[j] = testTime[j];
            }
            
        }

        cout<<result[0];
        for(int j = 1;j < n;++j)
            cout<<", "<<result[j];
        cout<<endl;
        cout<<"Number of fish expected: "<<maxresult<<endl;
        //注意每组数据之间有一空行！！！！
        cout<<endl; 
    }
    
    return 0;
}