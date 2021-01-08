#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
struct stu
{
    int id;
    string str;
    int score;
};
vector<stu> ct;
int N,G,K;
bool cmp(stu &e1,stu &e2)
{
    if(e1.score != e2.score)
        return e1.score > e2.score;
    else 
        return e1.str < e2.str;
}
int main()
{
    cin>>N>>G>>K;
    int sum = 0;
    for(int i = 0;i < N;++i)
    {
        string w;
        int sc;
        cin>>w>>sc;
        ct.push_back({0,w,sc});
        if(60 <= sc)
        {
            if(sc >= G)
                sum += 50;
            else 
                sum += 20;
        }
    }

    cout<<sum<<endl;
    sort(ct.begin(),ct.end(),cmp);
    ct[0].id = 1;
    for(int i = 1;i < N;++i)
    {
        if(ct[i - 1].score == ct[i].score)
            ct[i].id = ct[i-1].id;
        else 
            ct[i].id = i + 1;
    }
    for(int i = 0;ct[i].id <= K && i < N;++i)
        cout<<ct[i].id<<" "<<ct[i].str<<" "<<ct[i].score<<endl;
    return 0;
}
