#include<iostream>
#include<cstring>
#include<numeric>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#define EPS 1e-7
using namespace std;
//首先将每个人的房产信息中的编号进行并查集，用数组存储每条信息，对每个存在的人设置map标志位1
//遍历每条信息，另外设置一个数组保存结果信息。查询该人的父结点，即最小的编号。将该编号的房产套数和总面积分别增加对应的数量。
//利用set数组存储最小的编号
//遍历map集合中人的编号，每次find父结点，即最小编号。将该编号对应的人口数量加1.遍历结束。结果中每个下标的人数即是家庭的总人数
//通过以上结果信息中存储了  家庭人数，家庭房产总数，家庭房产的总面积
struct node{
    int id,fd,md,k;
    int child[10005];
    int house,area;
};
node st[10005];
struct re{
    int id,ans,housenum,area;
};
struct anwers{
    int id,ans;
    double num,area;
};
int pre[10005];
re aow[10005];
int N;
map<int,int> pe;

int find(int x){
    return pre[x] == x ? x : find(pre[x]);
}
void un(int x,int y){
    int nx = find(x),ny = find(y);
    if(nx < ny)
        pre[ny] = nx;
    else 
        pre[nx] = ny;
}
bool cmp(anwers & e1,anwers & e2){
    if(e1.area != e2.area)
        return e1.area > e2.area;
    else 
        return e1.id < e2.id;
}
int main()
{
    iota(pre,pre + 10005,0);
    cin>>N;
    for(int i = 0;i < N;++i){
        cin>>st[i].id>>st[i].fd>>st[i].md>>st[i].k;
        int id = st[i].id;
        pe[id] = 1;
        if(st[i].fd != -1)
        {
            un(id,st[i].fd);
            pe[st[i].fd] = 1;
        }
        if(st[i].md != -1){
            un(id,st[i].md);
            pe[st[i].md] = 1;
        }
        for(int j = 0;j < st[i].k;++j){
                cin>>st[i].child[j];
                un(id,st[i].child[j]);
                pe[st[i].child[j]] = 1;
        }

        cin>>st[i].house>>st[i].area;
    }
    set<int> cnt;
    for(int i = 0;i < N;++i){
        int x = st[i].id;
        int id = find(x);


        cnt.insert(id);

        aow[id].id = id;

        aow[id].housenum += st[i].house;

        aow[id].area += st[i].area;

    }
    for(auto i : pe){
        int id = find(i.first);

        aow[id].ans++;
    }
    cout<<cnt.size()<<endl;

    vector<anwers> pos;
    for(auto w : cnt){
        int id = w,peo = aow[w].ans,h = aow[w].housenum,aw = aow[w].area;
        pos.push_back({id,peo,(h/(peo*1.0)),(aw/(peo*1.0))});
    }
    sort(pos.begin(),pos.end(),cmp);
    
    for(auto w : pos){
        printf("%04d %d %.3f %.3f\n",w.id,w.ans,w.num,w.area);
    }

    return 0;
}