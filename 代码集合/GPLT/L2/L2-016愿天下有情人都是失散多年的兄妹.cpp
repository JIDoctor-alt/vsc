#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
using pii = pair<int,int>;
map<int,pii> pre;
int N,K;
map<int,int> sex;
vector<vector<int> > p(100005);
bool judge(int x,int y){
    set<int> st;
    priority_queue<pii> pq;
    pq.push({1,x});
    while(!pq.empty()){
        auto v = pq.top();
        pq.pop();
        if(v.first > 5)
            continue;
        int x = v.second;
        if(x == y)
            return false;
        st.insert(x);

        int fd = pre[x].first;
        if(fd != -1)
        {
            pq.push({v.first + 1,fd});
        }
        int md = pre[x].second;
        if(md != -1){
            pq.push({v.first + 1,md});
        }
    }

    for(auto w : st){

        priority_queue<pii> pq;
        pq.push({1,w});
        while(!pq.empty()){
            auto v = pq.top();
            pq.pop();
            
            if(v.first > 5)
                continue;
            
            int x = v.second;
            if(x == y)
                return false;
            
            for(auto e : p[x]){
                pq.push({v.first + 1,e});
            }
        }

    }

    return true;
}
int main()
{
    cin>>N;
    for(int i = 0;i < N;++i){
        int id,fd,md;
        char c;
        cin>>id>>c>>fd>>md;
        pre[id] = make_pair(fd,md);
        if(c == 'M')
        {
            sex[id] = 1;
        }else{
            sex[id] = 0;
        }
        if(fd != -1)
        {
            sex[fd] = 1;
            p[fd].push_back(id);
        }
        if(md != -1)
        {
            sex[md] = 0;
            p[md].push_back(id);
        }
    }
    cin>>K;
    while(K--){
        int x,y;
        cin>>x>>y;
        if(sex[x] == sex[y]){
            cout<<"Never Mind"<<endl;
        }else{
            cout<<(judge(x,y) ? "Yes\n" : "No\n");
        }
    }

    return 0;
}