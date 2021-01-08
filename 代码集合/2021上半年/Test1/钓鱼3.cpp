#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
const int N  = 30;
struct node{
    int nf,idx;
    //void set(int nn,int ii){nf = nn;idx = ii;}
   //  node(int nn,int ii):nf(nn),idx(ii){}
   //  node():nf(),idx(){}
};
int nl,f[N],t[N],d[N],totf,stay[N],beststay[N];
typedef priority_queue<node> PQ;
bool operator < (const node & a,const node & b){
    if(a.nf == b.nf){//
        return a.idx > b.idx;
    }else
    {
        return a.nf < b.nf;
    }
    
}
int main(){
    int i,j;
    while (cin>>nl && nl)
    {   int time;
        cin>>time;
        time *= 12;
        int maxf = -1;
        for(i = 0;i < nl;i++)
            cin>>f[i];//第一次钓鱼的
        for(i = 0;i < nl;i++)
            cin>>d[i];//每次钓鱼减少
        for(i = 0;i < nl-1;i++)
            cin>>t[i];//i湖和第i+1个湖之间的距离
        for(i = 0;i < nl;i++)
        {
            memset(stay,0,sizeof(stay));
            totf = 0;
            if(i > 0)time -= t[i-1];//去除走路的时间
            node now;
            PQ pq;
            for(j = 0;j <= i;j++){//将钓鱼数初始化
               // now.set(f[j],j);
               now.idx = j;
               now.nf = f[j];//将所有钓鱼数入队列
             //   pq.push(node(f[j],j));
                pq.push(now);
            }
            //然后从生下的时间片中开始 在每个湖中取最大的
            for(j = 0;j < time;j++){
                //最大堆
                now = pq.top();
                pq.pop();
                //在这个湖的钓鱼时间加加
                stay[now.idx] += 5;
                //总钓鱼量加上来
                totf += now.nf;//总的钓鱼量

                //更改
                now.nf -= d[now.idx];//将该湖的最大鱼减少
                if(now.nf < 0)now.nf = 0;

                pq.push(now);

            }
            if(totf > maxf){
                maxf = totf;
                memcpy(beststay,stay,sizeof(stay));//将stay数组中的值复制给
                //beststay
            }

        }
        cout<<beststay[0];
        for(i = 1;i < nl;i++)
            cout<<", "<<beststay[i];
        cout<<endl;
        cout<<"Number of fish expected: "<<maxf<<endl;
    }
    return 0;
    
}