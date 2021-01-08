#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>> v;
int n,k;
double z,r,result = 0.0;
bool visit[100010];
void dfs(int index,double power){
    if(visit[index] == true){
        //得道者
        result += power *v[index][0];
        return;
    }
    for(int i = 0;i < v[index].size();i++){
        dfs(v[index][i],power*(1-r/100));//每次都打折
    }
}

int main(){
    cin>>n>>z>>r;
    v.resize(n);
    for(int i = 0;i < n;i++){
        cin>>k;
        int temp;
        if(k == 0){//如果为0 就是得到这的编号
            cin>>temp;
            v[i].push_back(temp);
            visit[i] = true;///标记为得道者
        }else
        for(int j = 0;j < k;j++){
            cin>>temp;
            v[i].push_back(temp);
        }
    }
    dfs(0,z);//层第一个开始深度搜索。初始的功力为z
    cout<<(int)result<<endl;
    return 0;
}