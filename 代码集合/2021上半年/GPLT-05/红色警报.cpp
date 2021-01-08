#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
vector<vector<int> > g;
vector<bool> visited;
bool connect[510][510];
int N,M,K;
void dfs(int x)
{
    visited[x] = true;
    for(auto w : g[x])
    {//遍历改城市的邻接点如果发生攻占就不会相连了
        if(!visited[w]&&connect[w][x])
            dfs(w);
    }
}
int countCity()
{
    
    fill(visited.begin(),visited.end(),false);
    int ans = 0;//计算连通分量
    for(int i = 0;i < N;++i)
    {   
        if(!visited[i])
        {
            dfs(i);
            ans++;//连通分量加一
        }
    }
    return ans;

}
int main()
{
    // 初始化所有结点都不是相连的
    memset(connect,false,sizeof(connect));
    cin>>N>>M;
    g.resize(N);
    visited.resize(N);
   

    for(int i = 0;i < M;++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        //这两个结点相连
        connect[y][x] = connect[x][y] = true;
    }
    cin>>K;
    //当前城市的连通分量
    int ag = countCity();
    for(int i = 0;i < K;i++)
    {
        int num;
        cin>>num;
        //攻占一个城市，该城市将和与他相连的城市分离
        for(int j = 0;j < N;j++)
            if(connect[j][num])
                connect[j][num] = connect[num][j] = false;
        //被攻占后的城市连通分量
        int testCountCity = countCity();
        //被攻占后连通分量加1或者不变说明没有报警（连通分量没有被破坏）
        if(testCountCity  == ag+1 || testCountCity == ag)
            cout<<"City "<<num<<" is lost."<<endl;
        else
            cout<<"Red Alert: City "<<num<<" is lost!"<<endl;
        

        if(i == N-1)//如果是最后一个被攻占
            cout<<"Game Over."<<endl;
        //用于和下一次攻占时候比较
        ag = testCountCity;
    }
    
    return 0;
}