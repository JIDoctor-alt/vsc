#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<utility>
#include<numeric>
using namespace std;
//这个结构体用来存取两个敌对关系的宾客
using pii = pair<int,int>;
//用来存取父亲节点
vector<int> p;
int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}
void un(int x,int y)
{
    x = find(x);
    y = find(y);
    if( x != y)
        p[x] = y;
}
//返回一个结构体，小的在左边，大的在右边
//（每次加入的时候可能存在大宾客为x，小宾客为y这里只是将两个编号交换一下达到存取的目的）
pii makeE(int x,int y)
{
    return {min(x,y),max(x,y)};
}
int main()
{
    int N,M,K;
    cin>>N>>M>>K;
    //用来存取朋友（这里没用）
    vector<set<int>> f(N+1);
    p.resize(N+1);
    iota(p.begin(),p.end(),0);

    //用来存取敌对关系的集合（小编号的宾客，大编号的宾客）
    set<pii> e;
    while(M--)
    {
        int x,y,r;
        cin>>x>>y>>r;
        //是朋友就并查集
        if(r == 1)
        {
            f[x].insert(y);
            f[y].insert(x);
            un(x,y);
        }
        else
        {
            //敌对关系加入集合 （小宾客，大宾客）
            e.insert(makeE(x,y));
        }
    }
    while(K--)
    {
        int x,y;
        cin>>x>>y;
        //没有敌对关系
        if(e.count(makeE(x,y))== 0)
        {
            //是朋友
            if(find(x) == find(y))
                cout<<"No problem"<<endl;
            else //不是朋友
                cout<<"OK"<<endl;
        }
        else//敌对关系
        {

            if(find(x) == find(y))
                cout<<"OK but..."<<endl;
            else 
                cout<<"No way"<<endl;
        }
        
    }
    return 0;
}