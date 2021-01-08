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
vector<bool> visited(100100,false);
bool flag;
map<int,pii> ms;
bool DFS(int x,int y,int sum)
{
    //异性并且关系出了五服
    if(sum >= 5)
        return true;
        //ID未确定
    //或者是父亲或者母亲的id为-1找不到
    if(x == -1 || y == -1 || !ms.count(x) || !ms.count(y))
        return true;
    //两个人分别的父亲和母亲
    int fax = ms[x].first,max = ms[x].second;
    int fay = ms[y].first,may = ms[y].second;
    //是否为同一个父亲或者同一个母亲时
    if((fax > 0 && fax == fay && fay > 0)||(max == may && max > 0 && may > 0))
        return false;
    //判断下一代sum++
    ++sum;
    //两个父亲是否 或者 第一个父亲和第二个母亲 或者 第一个的母亲和第二个的父亲 或者第一个的母亲和第二个母亲
    return (DFS(fax,fay,sum) && DFS(fax,may,sum) && DFS(max,fay,sum)&&DFS(max,may,sum));
}
bool judge(int x,int y)
{
    
    return DFS(x,y,1);
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
        ms[id].first = father_id;
        ms[id].second = mother_id;
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