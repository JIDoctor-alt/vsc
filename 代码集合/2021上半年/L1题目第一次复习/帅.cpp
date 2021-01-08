#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
 int N,M;
int main(){
    set<int> stu; 
    cin>>N;
    vector<int> result;
    for(int i = 0;i < N;i++)
    {
        int K;
        cin>>K;
        for(int j = 0;j < K;j++)
        {
            int numid;
            cin>>numid;
            //存在列表中
            if(K>1)
             stu.insert(numid);//在列表中且不是自己在里面
         
        }
    }
    cin>>M;
    for(int i = 0;i < M;i++){
        int testid;
        cin>>testid;
        if(!stu.count(testid))
            if(find(result.begin(),result.end(),testid)==result.end())
                 result.push_back(testid);
    }
    int len = result.size();
    int flag = 0;
    if(len)
    for(auto i : result)
    {
        if(flag)cout<<" ";
        printf("%05d",i);
        flag = 1;
    }
    else 
    {
        cout<<"No one is handsome"<<endl;
    }
    return 0;
}