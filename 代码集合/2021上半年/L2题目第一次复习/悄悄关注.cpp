#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>

using namespace std;
struct node{
    string str;
    int number;
};
bool cmp(node & a,node & b){
    return a.str < b.str;
}
int main(){
    int N;
    cin>>N;
    vector<string> stu;
    map<string,int> m;
    for(int i = 0;i < N;i++)
    {
        string name;
        cin>>name;
        m[name] = 1;
      //  stu.push_back(name);
    }

    int M;
    cin>>M;
    //map<string,int> m;
    vector<node> snode;
    //
    int sum = 0;
    for(int i = 0;i < M;i++){
        string nam;int total;
        cin>>nam>>total;
        sum  += total;
        snode.push_back({nam,total});
    }
    double ave = sum/(1.0*M);
    sort(snode.begin(),snode.end(),cmp);
    vector<string> result;
    int flag = 0;
    for(int i = 0;i < M;i++){
        //如果点赞次数大于平均数且不再关注表中 
        if(snode[i].number > ave &&m.find(snode[i].str)==m.end()){
            //result.push_back(snode[i].str);
            cout<<snode[i].str<<endl;
            flag = 1;
        }
    }
    if(!flag){
        cout<<"Bing Mei You"<<endl;
    }
   
    

}