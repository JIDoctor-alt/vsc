#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int> > G;
vector<int> recnt;
int N;
double Z,R,sum = 0;
/*void dfs(int x,double ct)
{
    if(recnt[x] != 0)
    {
        sum += (ct * recnt[x]);
        return;
    }
    for(auto w : G[x])
    {
        dfs(w,ct*(1-R*0.01));
    }
}*///
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
   /// dfs(0,Z);
    cout<<(int)sum<<endl;
    return 0;
}