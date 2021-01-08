#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N,M,K;
vector<int> postNum;
vector<bool> lost;
vector< vector<int> > g;
vector<bool> visited;
void bfs(int x)
{
    queue<int> pq;
    pq.push(x);
    visited[x] = true;
    while (!pq.empty())
    {
        int v = pq.front();
        pq.pop();
        for(auto w : g[v])
        {
            if(!visited[w]&&!lost[w]){
                visited[w] = true;
                pq.push(w);
            }
                
        }
    }
    
}
int getNum()
{
    fill(visited.begin(),visited.end(),false);
    int ans = 0;
    for(int i = 0;i < N;++i)
    {   //该城市没有访问，且没有丢失
        if(!visited[i]&&!lost[i])
        {//每次访问计数器加加
            ans++;
            bfs(i);
        }
    }
    return ans;
}
int main()
{
    cin>>N>>M;
    g.resize(N);
    visited.resize(N);
    lost = vector<bool>(N,false);
    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin>>K;
    postNum.push_back(getNum());
    while(K--)
    {
        int num;
        cin>>num;
        lost[num] = true;
        postNum.push_back(getNum());
        if(postNum.back() > postNum[postNum.size()-2])
            cout<<"Red Alert: City "<<num<<" is lost!"<<endl;
        else
            cout<<"City "<<num<<" is lost."<<endl;

        if(postNum.back() == 0)
            cout<<"Game Over."<<endl;
    }
    return 0;
}