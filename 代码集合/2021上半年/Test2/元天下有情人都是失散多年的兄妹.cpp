#include<iostream>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;
struct node{
    int f,m,sex;//父亲母亲，性别
};
node v[100010];
int level[100010];
bool exist[100010];

int main(){
    int n,m,id,father,mother,a,b;
    cin>>n;
    char c;
    for(int i = 0;i < n;i++){
        cin>>id>>c>>father>>mother;
        v[id].f =father;
        v[id].m = mother;
        if(c=='M')v[id].sex = 0;///男性
        else v[id].sex = 1;//女性
        exist[id] = true;
        v[father].sex = 0;//父亲为男性
        v[mother].sex = 1;//母亲 为女性
    }
    cin>>m;
    for(int i = 0;i < m;i++){
        fill(level,level+100010,0);//将数组都置为0
        cin>>a>>b;
        if(v[a].sex  == v[b].sex){
            cout<<"Never Mind"<<endl;
            continue;
        }
        queue<int> q;
        q.push(a);
        q.push(b);
        level[a] = 1;
        level[b] = 1;
        set<int> s;
        int flag = 0;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            int size = s.size();

            //把他们的父母放入set中，如果大小改变就有相同祖先
            s.insert(top);

            if(size == s.size()){
                //关系没有出五福
                cout<<"No"<<endl;
                flag  = 1;
                break;
            }
            //这个人不存在(对于一个人的父母，可能不存在id总)
            if(exist[top] == false)continue;
            if(level[top] <= 4){
                int fa = v[top].f;
                int mo = v[top].m;
                if(fa != -1){
                    q.push(fa);
                    level[fa] = level[top] + 1;
                }
                if(mo != -1){
                    q.push(mo);
                    level[mo] = level[top] + 1;
                }
            }
        }
        if(flag == 0)cout<<"Yes"<<endl;
    }
    return 0;
}
/*
我用的方法是广度优先，然后把每个人和她们的祖先压入一个set
里面，判断set前后有没有大小改变，如果没改变说明重复了
，所以有相同的祖先，所以输出NO，用level数组标记她们当前的层数
在push一层的时候令她们的层数为上一层加1，一直到五层判断结束
。如果结束了还没有输出过No，那么就输出yes，其实后来想到可以
用数组标记的方法，不用集合来这么复杂的
有三个注意点：1.开始有三个测试点不过，
*/