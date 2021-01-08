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
void DFS(int x,int sum)
{
    visited[x] = true;
    //sum等于5的时候就要在向下继续了，
    //对第一个人深搜的时候，会设置（当sum为第五代的时候设置为true）已经访问过
   if(sum >= 5)
        return;
    for(auto w : G[x])
    {
        if(!visited[w])
           DFS(w,sum+1);
        else //如果发现搜索过程中出现被访问过的结点，说明在第一次搜索的过程中被搜索过，即与第一个人有公共祖先
         {  
             flag = false;
             return;
         }  
    }
}
bool judge(int x,int y)
{
    //每次测试都要将visited初始化，并且标志值也要设置为true(每次测试标志可能变化)
    fill(visited.begin(),visited.end(),false);
    flag = true;
    DFS(x,1);
    DFS(y,1);
    return flag;
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