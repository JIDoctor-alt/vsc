#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
using pii = pair<int,int>;
//一个存储父结点，一个存储子结点
map<int,vector<int> > G,rG;
//性别
map<int,char> gender;
int N,K;

bool judge(int x,int y)
{
    queue<pii> pq;
    //人的编号，以及辈分（从一开始）
    pq.push(make_pair(x,1));
    //第一个人以及第一个人五代以内的人的集合
    set<int> ms;
    while (!pq.empty())
    {
        auto v = pq.front();
        pq.pop();
        //超过五代就跳过此次循环（这个人丢掉）
        if(v.second > 5)
            continue;
        //五代以内就加入到集合中
        ms.insert(v.first);
        //在将其邻接点，父亲母亲加入到测试队列中（父结点）
        for(auto w : G[v.first])
            pq.push(make_pair(w,v.second+1));  
    }
    
    //对x五代以内家族每个人判断其五代以内是否有y
    for(auto w : ms)
    {
        queue<pii> pq;
        //选择的结点查看五代以内是否有y
        pq.push(make_pair(w,1));
        while (!pq.empty())
        {
            auto v = pq.front();
            pq.pop();
            //前提是这个人必须是五代以内
            if(v.second > 5)   
                continue;
            //这个人是y就直接跳出（找到答案）
            if(v.first == y)
                return false;
            //通过反图来测试子结点（儿子）
            for(auto i : rG[v.first])
                pq.push(make_pair(i,v.second+1));
        }
        
    }
    return true;

}
int main()
{
    cin>>N;
    while (N--)
    {
        int id,father_id,mother_id;
        char c;
        cin>>id>>c>>father_id>>mother_id;
        gender[id] = c;
        if(father_id != -1)
        {
            gender[father_id] = 'M';
            G[id].push_back(father_id);
            rG[father_id].push_back(id);
        }
        if(mother_id != -1)
        {
            gender[mother_id] = 'F';
            G[id].push_back(mother_id);
            rG[mother_id].push_back(id);
        }
    }
    cin>>K;
    while (K--)
    {
        int na,nb;
        cin>>na>>nb;
        if(gender[na] == gender[nb])
            cout<<"Never Mind"<<endl;
        else 
            cout<<(judge(na,nb) ? "Yes\n" : "No\n");
    }
    
    return 0;
}