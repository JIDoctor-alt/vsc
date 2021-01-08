#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct peo{
    string name;
    int sco;
};//名字 分数
bool cmp(peo & a,peo & b){
    if(a.sco != b.sco)return a.sco > b.sco;
    return a.name < b.name;//字母升序
}
int main(){
    int n,g,k,sum = 0,rank[10001] = {0};
    //学生人数，分数线，进入的最低名次
    cin>>n>>g>>k;
    vector<peo> v(n);
    for(int i = 0;i < n;i++){
        cin>>v[i].name>>v[i].sco;
        if(v[i].sco >= 60)sum+= 20;
        if(v[i].sco >= g)sum+= 30;
    }
    sort(v.begin(),v.end(),cmp);
    rank[0] = 1;
    for(int i = 1;i < n;i++){
        if(v[i].sco == v[i-1].sco)
            rank[i] = rank[i-1];//排名
        else
        {
            rank[i] = i + 1;
        }
        
    }
    cout<<sum<<endl;
    for(int i = 0;rank[i] <= k && i < n;i++)
        cout<<rank[i]<<" "<<v[i].name<<" "<<v[i].sco<<endl;

    return 0;
}