
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
bool check(int x,int y)
{
    //这两个人的父结点
    vector<int> level1(100100,0),level2(100100,0);
    set<int> c1;
    //将第一个人的父结点插入c1,并且记录每个结点的深度（第几代）
    c1.insert(x);//!!!注意这里的情况 y的父亲节点可能是x
    while (pa[x] != -1)
    {
        level1[pa[x]] = level1[x] + 1;
        if(pa[x] == y)return false;
        c1.insert(pa[x]);
        x = pa[x];
    }
    
    while (pa[y] != -1)
    {
        level2[pa[y]] = level2[y] + 1;
        if(c1.count(pa[y]))
        {
            if(level1[pa[y]] < 4 || level2[pa[y]] < 4)
                return false;
            else 
                return true;
          
        }
        y = pa[y];
    }
    
    return true;
    
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