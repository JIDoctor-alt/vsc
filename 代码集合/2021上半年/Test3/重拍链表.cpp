#include<iostream>
#include<vector>

using namespace std;
struct node{
    int id,data,next;//地址，值，下一个结点

};
int main(){
    int begin,n;
    cin>>begin>>n;//开始的地址,结点的个数
    node a[100010];
    vector<node> v,ans;
    for(int i = 0;i < n;i++){
        int tbegin,tdata,tnext;
        cin>>tbegin>>tdata>>tnext;
        a[tbegin] = {tbegin,tdata,tnext};
    }
    while(begin != -1){
        v.push_back(a[begin]);//从头开始
        begin = a[begin].next;//下一个地址
    }
    int l = 0,r = v.size()-1;//最后一个的下标
    //重排链表  每次加入ans中对应的下标都要移动
    while(true){
        ans.push_back(v[r]);//从后向前
        r--;
        if((r+1)-(l-1) == 1)break;
        ans.push_back(v[l]);
        l++;
        if((r+1)-(l-1) == 1)break;
    }
    for(int i = 0;i < ans.size();i++){
        if(i != ans.size()-1)
            printf("%05d %d %05d\n",ans[i].id,ans[i].data,ans[i+1].id);
        else
        {
            printf("%05d %d -1\n",ans[i].id,ans[i].data);
        }
        
    }
    return 0;
}