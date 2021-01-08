#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
using pii = pair<int,int>;
map<int,char> gender;
int N,K;
vector<vector<int> > pre(100005),rG(100005);
bool judge(int x,int y)
{
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    set<int> st;
    pq.push({1,x});
    while(!pq.empty())
    {
        auto v = pq.top();
        int x = v.second;
        pq.pop();
        if(v.first > 5)
            continue;

        if(x == y)
            return false;

        st.insert(x);

        for(auto &e : pre[x])
        {
            pq.push({v.first + 1,e});
        }
    }

    for(auto &w : st)
    {
        for(auto &e : rG[w])
        {
            priority_queue<pii,vector<pii>,greater<pii> > pnxy;
            pnxy.push({1,e});
            while(!pnxy.empty())
            {
                auto v = pnxy.top();
                pnxy.pop();

                if(v.first > 5)
                    continue;
                
                if(v.second == y)
                    return false;

                for(auto &wx : rG[v.second])
                {
                    pnxy.push({v.first + 1,wx});
                }
            }
        }
    }

    return true;
}
int main()
{
    cin>>N;
    while(N--)
    {
        int id,fid,mid;
        char c;
        cin>>id>>c>>fid>>mid;
        gender[id] = c;
        if(fid != -1)
        {
            gender[fid] = 'M';
            pre[id].push_back(fid);
            rG[fid].push_back(id);
        }
        if(mid != -1)
        {
            gender[mid] = 'F';
            pre[id].push_back(mid);
            rG[mid].push_back(id);
        }
    }
    cin>>K;
    while(K--)
    {
        int a,b;
        cin>>a>>b;
        if(gender[a] == gender[b])
        {
            cout<<"Never Mind\n";
        }
        else 
        {
            cout<<(judge(a,b) ? "Yes\n" : "No\n");
        }
    }

    return 0;
}