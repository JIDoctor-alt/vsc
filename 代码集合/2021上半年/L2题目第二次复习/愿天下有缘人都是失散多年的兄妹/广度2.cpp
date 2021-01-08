#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
using namespace std;
//注意：父母可能不在记录中
using pii = pair<int,int>;
map<int,vector<int> > G;
map<int,vector<int> > rG;
map<int,char> gender;
vector<bool> visited(100005);
map<int,pii> me;
int N,K;
bool judge(int x,int y)
{
    queue<int> pq;
    pq.push(x);
    pq.push(y);
    set<int> st;
    vector<int> level(100005,0);
    level[x] = 1;
    level[y] = 1;
    while(!pq.empty())
    {
        auto v = pq.front();
        pq.pop();
        int size = st.size();
        st.insert(v);
        if(size == st.size())
        {
            return false;
        }
        if(me.count(v) == 0)
            continue;
        if(level[v] <= 4)
        {
            int fa = me[v].first;
        int ma = me[v].second;
        if(fa != -1)
        {
            pq.push(fa);
            level[fa] = level[v] + 1;
        }
        if(ma != -1)
        {
            pq.push(ma);
            level[ma] = level[v] + 1;
        }
        }
        
    }
    return true;
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
        me[id].first = fid;
        me[id].second = mid;
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