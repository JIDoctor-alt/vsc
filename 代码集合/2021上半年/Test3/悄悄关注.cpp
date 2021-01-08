#include<iostream>
#include<map>
#include<set>
using namespace std;
int  main(){
    int n,m,sum = 0,cnt ,flag = 0;
    string str;
    cin>>n;
    set<string> s;
    for(int i = 0;i < n;i++){
        cin>>str;
        s.insert(str);//关注的n个用户
    }
    cin>>m;//对m个用户点赞
    map<string,int> mt;
    for(int i = 0;i < m;i++){
        //点赞的数量
        cin>>str>>cnt;
        mt[str] = cnt;
        sum += cnt;
    }
    //点赞的平均数
    sum /= m;
    for(auto it : mt){
        //被该用户点赞次数大于其点赞平均数、且不在其关注列表上的人
        if(it.second > sum && s.find(it.first) == s.end()){
            //map集合中升序输出
            cout<<it.first<<endl;
            flag = 1;
        }
    }
    if(flag == 0)cout<<"Bing Mei You";
    return 0;
}