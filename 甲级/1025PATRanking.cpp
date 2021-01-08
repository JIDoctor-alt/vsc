#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int N,K;
struct node
{
    string name;
    int final_rank;
    int location_number;
    int local_rank;
    int score;
};
bool cmp1(node &e1,node &e2)
{
    if(e1.score != e2.score)
         return e1.score > e2.score;
    else 
        return e1.name < e2.name;
}
vector<node> mergedRanklist;
int main()
{
    cin>>N;

    for(int i = 0;i < N;++i)
    {
        cin>>K;
        vector<node> t(K);
        for(int j = 0;j < K;++j)
        {
            string id;
            int sc;
            cin>>id>>sc;
            t[j].name = id;
            t[j].score = sc;
            t[j].location_number = i + 1;
       
        }

        sort(t.begin(),t.end(),cmp1);

        t[0].local_rank = 1;
        mergedRanklist.push_back(t[0]);
        for(int i = 1;i < t.size();++i)
        {
            t[i].local_rank = i + 1;
            if(t[i].score == t[i-1].score)
                t[i].local_rank = t[i-1].local_rank;
            
            mergedRanklist.push_back(t[i]);
        }
    }
    sort(mergedRanklist.begin(),mergedRanklist.end(),cmp1);
    mergedRanklist[0].final_rank = 1;
    for(int i = 1;i < mergedRanklist.size();++i)
    {
        mergedRanklist[i].final_rank = i + 1;
        if(mergedRanklist[i].score == mergedRanklist[i - 1].score)
            mergedRanklist[i].final_rank = mergedRanklist[i-1].final_rank;
    }
    cout<<mergedRanklist.size()<<endl;
    for(auto &e : mergedRanklist)
    {
        cout<<e.name<<" "<<e.final_rank<<" "<<e.location_number<<" "<<e.local_rank<<endl;
    }
    return 0;
}