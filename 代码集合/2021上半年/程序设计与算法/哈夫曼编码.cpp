#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
    string str;
    while (cin>>str && str != "END")
    {
        sort(str.begin(),str.end());//首先要对字符串排序用于计算相同字符的个数
        int len = str.length();
        int j;
        priority_queue<int,vector<int>,greater<int> > pq;
        for(int i = 0;i < len;++i)
        {
            j = i;
            while(str[j] == str[j+1] && j < len -1)
                ++j;
            pq.push(j - i + 1);
            i = j;
        }
        //如果只有一个节点的情况
        int ans = (pq.size() == 1 ? pq.top() : 0);
        while (pq.size() > 1)//计算非叶子节点权值之和
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            ans += (a+b);//计数
            pq.push(a+b);
        }
        cout<<8 * len<<" "<<ans<<" ";
        cout<<fixed<<setprecision(1)<<(8 * len)/(ans*1.0)<<endl;   
    }
    return 0;
}