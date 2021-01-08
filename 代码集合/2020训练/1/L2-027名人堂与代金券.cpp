#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int N,K,G;
struct node
{
    int fid;
    string id;
   
    int score;
    bool operator<(const node& e)const
    {
        if(score != e.score)
            return score > e.score;
        else 
            return id < e.id;
    }
};

int main()
{
    cin>>N>>G>>K;
    vector<node> st;
    int ans = 0;
    for(int i = 0;i < N;++i)
    {
        string xid;
        int cs;
        cin>>xid>>cs;
        if(cs >= 60 && cs < G)
        {
            ans += 20;
            
        }
        if(cs >= G && cs <= 100)
        {
            ans += 50;
        }
        st.push_back({0,xid,cs});
    }

    cout<<ans<<endl;
    sort(st.begin(),st.end());

    int presocre = st[0].score,i = 1;
    st[0].fid = i;
    cout<<st[0].fid<<" "<<st[0].id<<" "<<st[0].score<<endl;
    for(int j = 1;j < st.size();++j)
    {
        ++i;
        if(st[j].score == st[j - 1].score)
        {
            st[j].fid = st[j - 1].fid;
        }
        else 
        {
            st[j].fid = i;
        }
        if(st[j].fid > K)
            break;
        cout<<st[j].fid<<" "<<st[j].id<<" "<<st[j].score<<endl;
    }

    return 0;
}