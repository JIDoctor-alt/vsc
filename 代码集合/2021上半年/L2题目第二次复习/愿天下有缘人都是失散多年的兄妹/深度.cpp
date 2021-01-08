#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
//五代以内（本人，父母，祖父母，曾祖父母，高祖父母，这可以是一个图结构，父母不会存在五代以内的
//注意测试数据的范围
using namespace std;
using pii = pair<int,int>;
map<int,vector<int> > G;
map<int,vector<int> > rG;
map<int,char> gender;
vector<bool> visited(100005);
int N,K;
bool flag;
void dfs(int x,int sum)
{
    visited[x] = true;
    if(sum >= 5)
        return;
    for(auto w : G[x])
    {
        if(!visited[w])
            dfs(w,sum + 1);
        else 
        {
            flag = false;
            break;
        }
    }

}
bool judge(int x,int y)
{
    flag = true;
    fill(visited.begin(), visited.end(),false);
    dfs(x,1);
    dfs(y,1);
    return flag;
}
int main()
{
    cin>>N;
    
    for(int i = 0;i < N;++i)
    {
        int id,fid,mid;
        char c;
        cin>>id>>c>>fid>>mid;
        gender[id] = c;
        if(fid != -1)
        {
            gender[fid] = 'M';
            G[id].push_back(fid);
            rG[fid].push_back(id);
        }
        if(mid != -1)
        {
            gender[mid] = 'F';
            G[id].push_back(mid);
            rG[mid].push_back(id);
        }
    }
    cin>>K;
    for(int i = 0;i < K;++i)
    {
        int x,y;
        cin>>x>>y;
        if(gender[x] == gender[y])
        {
            cout<<"Never Mind"<<endl;
        }
        else 
        {
            if(judge(x,y))
            {
                cout<<"Yes"<<endl;
            }
            else 
            {
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}