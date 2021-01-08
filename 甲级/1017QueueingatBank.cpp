#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct  Peo
{
    int cost;
    int arriveTime;
    bool operator<(const Peo &e)const
    {
        return arriveTime < e.arriveTime;
    }
}p[10005];
/*bool cmp(Peo &e1,Peo &e2)
{
    return e1.arriveTime < e2.arriveTime;
}*/
int N,K,cnt , total;
int main()
{
    cin>>N>>K;
    for(int i = 1;i <= N;++i)
    {
        int hh,mm,ss,l;
        scanf("%d:%d:%d %d",&hh,&mm,&ss,&l);

        int sum = hh * 60 * 60 + mm * 60 + ss;

        if(sum > 17*60*60)
            continue;

        p[++cnt].cost = l*60;//注意l是以分钟为单位
        p[cnt].arriveTime = sum;
    }

    //sort(p + 1, p + cnt + 1,cmp);
    sort(p + 1, p + cnt + 1);
    priority_queue<int,vector<int>,greater<int> > pq;

    for(int i = 1;i <= K;++i)
        pq.push(8*60*60);

    for(int i = 1;i <= cnt;++i)
    {
        if(pq.top() <= p[i].arriveTime)
        { 
            pq.push(p[i].arriveTime + p[i].cost);
            pq.pop();
        }
        else 
        {
            int topTime = pq.top();
            total += topTime - p[i].arriveTime;
            pq.push(p[i].cost + topTime);
            pq.pop();
        }
    }

    (!cnt) ? printf("0.0\n")  : printf("%.1f\n",((double)total/60)/cnt);


    return 0;
}