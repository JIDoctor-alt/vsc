
///画出样例来
#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<set>
using namespace std;
const int MAX = 100005;
int N;
string fn[MAX],sn[MAX];  //名字，姓
int gender[MAX];      //性别
int pa[MAX]; //pa[i]表示i的父亲节点
map<string,int> mp; //根据孩子姓，查上一代是谁，例：mike jacksson的爹jack存在fn的那下标里
int flag ;
bool dfs(int a,int b,int h1,int h2)
{
    if(b == -1 || h1>= 5 && h2 >= 5)
        return true;
    if(a == b)
    {
        flag = 1;//直接确定答案
        if(h1 >= 5 && h2 >= 5)
            return true;//共同祖先在五代以及五代以外
        else 
            return false;//共同祖先在五代之内
    }
    return dfs(a,pa[b],h1,h2+1);
}
bool check(int x,int y)
{
    flag  = 0;
    int h = 1,tag = 1;
    
    while (x != -1&& !flag)
    {
        tag &= dfs(x,y,h,1);
        x = pa[x];
        h++;
    }
    return tag;
}
int main()
{
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        string s1,s2;
        cin>>s1>>s2;
        fn[i] = s1;
        //男 sson  女 sdottir
        if(s2.back() == 'n')
        {
            sn[i] = s2.substr(0,s2.length()-4);
            gender[i] = 1;
            mp[s1] = i;
        }
        else if(s2.back() == 'r')
        {
            sn[i] = s2.substr(0,s2.length()-7);
            gender[i] = 0;
            mp[s1] = i;
        }
        else 
        {
            sn[i] = s2.substr(0,s2.length() - 1);
            //m 为 男 f为女
            gender[i] = (s2.back() == 'm' ? 1 : 0);
            mp[s1] = i;
            pa[i] = -1;
        }
    }
    for(int  i = 0;i < N;++i)
    {
        if(pa[i] == -1)
            continue;
        int  p = mp[sn[i]];
        pa[i] = p; 
    }
    int M;
    cin>>M;
    while (M--)
    {
        string p1f,p1s,p2f,p2s;
        cin>>p1f>>p1s>>p2f>>p2s;

        //如果存在返回这个人的编号 不存在返回 -1
        int id1 = mp.count(p1f) ? mp[p1f] : -1;
        int id2 = mp.count(p2f) ? mp[p2f] : -1;

        if(id1 == -1 || id2 == -1)
            cout<<"NA"<<endl;
        else if(gender[id1] == gender[id2])
            cout<<"Whatever"<<endl;
        else
        {
            
            cout<<(check(id1,id2) ? "Yes\n" : "No\n");
        }
    }
    
    return 0;

}