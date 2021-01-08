#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
struct edge{
    int id;
    string name;
    int score;
};
vector<edge> stu;
int N,G,K,ans = 0;
bool cmp(edge &e1,edge &e2)
{
    if(e1.score != e2.score)
    {
        return e1.score > e2.score;
    }
    else 
    {
        return e1.name < e2.name;
    }
}
int main()
{
    cin>>N>>G>>K;
    for(int i = 1;i <= N;++i)
    {
        string n;
        int  s;
        cin>>n>>s;
        stu.push_back({i,n,s});

        if(s >= 60)
        {
            if(s < G)
            {
                ans += 20;
            }else if(s >= G && s <= 100)
            {
                ans += 50;
            }
        }
    }

    sort(stu.begin(),stu.end(),cmp);

    cout<<ans<<"\n";

    int cnt = 1,pre_score = stu[0].score,index = 1;
    cout<<cnt<<" "<<stu[0].name<<" "<<stu[0].score<<"\n";

    for(;cnt <= K;)
    {
        int x = stu[index].score;
        if(x == pre_score)
        {
            cout<<cnt;
        }
        else 
        {
            cnt = index + 1;
            if(cnt > K)
                break;
            cout<<cnt;
            pre_score = x;
        }
        cout<<" "<<stu[index].name<<" "<<stu[index].score<<"\n";

        ++index;
    }
    return 0;
}