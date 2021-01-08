#include<iostream>
#include<algorithm>
#include<functional>
#include<utility>
#include<vector>

using namespace std;
using pii = pair<int,int>;


//按照电影的结束时间排序
bool cmp(pii & a,pii & b)
{
    return a.second < b.second;
}
int main()
{
    int N;
    
    while (true)
    {
       
        cin>>N;
        if(N== 0)break;
        vector<pii> stu;
        for(int i = 0;i < N;++i)
        {
              int s,e;
              cin>>s>>e;
              stu.push_back({s,e});
        }
        
        sort(stu.begin(),stu.end(),cmp);
        int ans = 1,countEnd = stu[0].second;
        for(int i = 1;i < stu.size();++i)
        {
             if(stu[i].first >= countEnd){
                 countEnd = stu[i].second;
                ans++;
                }
        }
        cout<<ans<<endl;
    }
  
    
    return 0;
}