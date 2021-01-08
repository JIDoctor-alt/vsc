#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
using namespace std;
using pii = pair<int,int>;
map<int,vector<int> > G;
map<int,vector<int> > rG;
map<int,char> gender;
int N,K;
bool judge(int x,int y)
{
    queue<pii> pq;
    set<int> st;
    pq.push(make_pair(x,1));
    while(!pq.empty())
    {
        auto v = pq.front();
        pq.pop();
        if(v.second > 5)
            continue;
        int x = v.first;
        st.insert(x);
        for(auto w : G[x])
        {
            pq.push(make_pair(w,v.second + 1));
        }
    }

    for(auto i : st)
    {
        queue<pii> pq;
        pq.push(make_pair(i,1));

        while (!pq.empty())
        {    
            auto x = pq.front();
            pq.pop();
            if(x.second > 5)
                continue;
            if(x.first == y)
                return false;
            for(auto w : rG[x.first])
                pq.push(make_pair(w,x.second + 1));
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