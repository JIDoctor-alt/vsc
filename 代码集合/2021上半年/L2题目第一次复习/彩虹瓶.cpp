/*
其实问的就是有一个限制大小的栈辅助，
能不能把给定序列按顺序排好
*/
#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;
int n,m,k;
vector<int> v(1005);

bool judge(){
    stack<int> s;
    int cur = 1;//表示当前需要哪种编号的小球
    for(int i = 0;i < n;){
        if(cur == v[i]){
            //如果序列里的这个数就是瓶子能装的
            ++cur;
            ++i;
        }else if(!s.empty() && cur == s.top()){
            //如果栈顶的数是瓶子能装的
            ++cur;
            s.pop();
        }else{
            //都装不了只能暂时堆着，如果容量超过了，retrun false;
            if(s.size() == m)return false;
            s.push(v[i]);
            ++i;
        }
    }
    //最后把栈里面剩下的页装进瓶子里
    while(!s.empty()){
        if(cur == s.top()){
            ++cur;
            s.pop();
        }else
            return false;
    }
    return true;
}
int main(){
    cin>>n>>m>>k;
    while(k--){
        for(int i = 0;i < n;++i)cin>>v[i];
        if(judge()){
            cout<<"YES"<<endl;
        }else
        {
            cout<<"NO"<<endl;
        }
        
    }
    return 0;
}