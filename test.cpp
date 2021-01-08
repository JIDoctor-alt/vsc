#include<iostream>
#include<cstring>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

/*
pair 默认对first升序，当first相同时对second升序；
// 如果两个对象的first和second依次相等，则这两个对象相等；该运算使用元素的==操作符。
*/

const int N = 100010;
int n,m,T;
int last[N],score[N];
bool st[N];
pair<int,int> orders[N];
int main()
{
    cin>>n>>m>>T;//t时刻以内的m条订单
    for(int i = 0;i < m;++i)
    {
        cin>>orders[i].first>>orders[i].second;
    }
    sort(orders,orders + m);
     for(int i = 0;i < m;++i)
    {
        cout<<orders[i].first<<" "<<orders[i].second<<endl;
    }
    //m以后的订单不用管了
    for(int i = 0;i < m && orders[i].first <= T;++i)
    {
        int j = i;
        while(j < m && orders[i] == orders[j])//多少订单
        {
            ++j;
        }
        //t 时刻，编号为id的店收到一个订单
        int t = orders[i].first, id = orders[i].second;

        //每经过 1 个时间单位，如果外卖店没有订单，则优先级会减少 1，最低减 到 0；
        score[id] -= t - last[id] - 1;//优先级（上一个时刻，这一刻不算在内）
        if(score[id] < 0)
        {
            score[id] = 0;
        }
        /*如果某家外卖店某时刻优先级大于 5，则会被系统加入优先缓存中；
        如果 优先级小于等于 3，则会被清除出优先缓存*/
        if(score[id] <= 3)//
        {
            st[id] = false;
        }
        last[id] = t;//保留id最后一个订单的时间


//-------------------------下面开始计算这一时刻的-----------
    //而如果外卖店有订单，则优先级不减反加，每有一单优先级加 2。 
        score[id] += (j - i)*2;

        if(score[id] > 5)
        {
            st[id] = true;
        }

        i = j -  1;//后面有个i++
    }

//最后更新到所有店主在T时刻的状态
    for(int i = 1;i <= n;++i)
    {
        if(last[i] < T)//等于T时已经计算完毕
        {
            score[i] -= T - last[i];
            if(score[i] <= 3)
            {
                st[i] = false;
            }
        }
    }

    int res = 0;
    for(int i = 1;i <= n;++i)
    {
        res += st[i];
    }
    cout<<res<<endl;
    return 0;
}
/*
2 6 6
1 1 
5 2 
3 1 
6 2 
2 1 
6 2

*/