#include<iostream>
#include<algorithm>

using namespace std;
struct DATE{
    int id,fid,mid,num,area;//编号，父亲，母亲，孩子，总面积
    int cid[10];
}data[1005];
struct node{
    int id,people;
    double num,area;
    bool flag = false;
}ans[10000];
int father[10000];
bool visit[10000];
int find(int x){
    while(x != father[x])
        x = father[x];
    return x;
}
void un(int a,int b){
    int faA = find(a);
    int faB = find(b);
    if(faA > faB) father[faA] = faB;
    else 
        father[faB] = faA;
}
int cmp(node & a,node & b){
    if(a.area != b.area)
        return a.area > b.area;
    else
    {
        return a.id < b.id;
    }
    
}

int main(){
    int n,k,cnt = 0;
    cin>>n;
    for(int i = 0;i < 10000;i++)
        father[i] = i;
    for(int i = 0;i < n;i++){
        cin>>data[i].id>>data[i].fid>>data[i].mid>>k;
        visit[data[i].id] = true;
        if(data[i].fid != -1){
            //父亲没有过世
            visit[data[i].fid] = true;
            un(data[i].fid,data[i].id);//这个人和它的父亲并集
        }
        if(data[i].mid != -1){
            visit[data[i].mid] = true;
            un(data[i].mid,data[i].id);
        }
        for(int j = 0;j < k;j++){
            cin>>data[i].cid[j];//这个人的子女
            visit[data[i].cid[j]]  = true;
            un(data[i].id,data[i].cid[j]);//子女
        }
        cin>>data[i].num>>data[i].area;//房子数量和总面积面积
    }
    for(int i = 0;i < n;i++){
        int id = find(data[i].id);//找到这个人的父节点
        ans[id].id = id;
        ans[id].num += data[i].num;//总的房产数量
        ans[id].area += data[i].area;//总的房子面积
        ans[id].flag = true;
    }
    for(int i = 0;i < 10000;i++){
        if(visit[i]){
            //表示已经加入集合
            ans[find(i)].people ++;//这个人的家庭人口数
        }
        if(ans[i].flag){
            cnt++;
        }
    }
    for(int i = 0;i < 10000;i++){
        if(ans[i].flag){
            //人均房产数
            ans[i].num = (double)(ans[i].num * 1.0 /ans[i].people);
            //人均房产面积
            ans[i].area = (double)(ans[i].area*1.0/ans[i].people);
        }
    }
    sort(ans,ans+10000,cmp);
    cout<<cnt<<endl;//有多少个家庭
    for(int i = 0;i < cnt;i++){
        printf("%04d %d %.3f %.3f\n",ans[i].id,ans[i].people,ans[i].num,ans[i].area);
    }
    return 0;
}