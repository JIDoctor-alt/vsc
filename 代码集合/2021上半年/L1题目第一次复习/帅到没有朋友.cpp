#include<iostream>
#include<set>
#include<vector>

using namespace std;
vector<set<int> > peo;
 int N,M;
bool Valid(int id){
    for(int i = 0;i < N;i++)
    {
        ///如果在朋友圈而且不是自己在朋友圈返回正确
        if(peo[i].count(id)&&peo[i].size()>1)return true;
    }
    ///没有朋友
    return false;
}
int main(){
    set<int> stu;
   
    cin>>N;
    set<int> result;
    peo.resize(N);
    for(int i = 0;i < N;i++)
    {
        int K;
        cin>>K;
        for(int j = 0;j < K;j++)
        {
            int numid;
            cin>>numid;
            stu.insert(numid);
            peo[i].insert(numid);
        }
    }
    cin>>M;
    for(int i = 0;i < M;i++){
        int testid;
        cin>>testid;
        if(!stu.count(testid) || !Valid(testid))
            if(!result.count(testid))
             result.insert(testid);
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