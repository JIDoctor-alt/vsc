#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
using pii = pair<int,double>;
vector<vector<int> > G;
vector<int> recnt;
int N;
double Z,R,sum = 0;
void bfs()
{
    queue<pii> pq;
    pq.push({0,Z});
    while (!pq.empty())
    {
        auto v = pq.front();
        pq.pop();
        int x = v.first;
        double cnt = v.second;
        if(recnt[x] != 0)
        {
            sum += recnt[x]*cnt;
            continue;
        }
        for(auto w : G[x])
        {
            pq.push({w,cnt*(1-0.01*R)});
        }
    }
    
}
int main()
{
    cin>>N>>Z>>R;
    G.resize(N);
    recnt.resize(N);
    int K;
    for(int i = 0; i < N;++i)
    {
        cin>>K;
        if(K == 0)
        {
            int cnt;
            cin>>cnt;
            recnt[i] = cnt;
        }
        else 
        {
            for(int j = 0;j < K;++j)
            {
                int num;
                cin>>num;
                G[i].push_back(num);
            }
        }
    }
    bfs();
    cout<<(int)sum<<endl;
    return 0;
}