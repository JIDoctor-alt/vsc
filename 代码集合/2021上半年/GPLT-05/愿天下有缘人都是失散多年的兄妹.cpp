#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<vector>
#include<set>
using namespace std;
using pii = pair<int,int>;
int N,K;
map<int,pii> peo;
map<int,int> sex;
bool check(int mes1,int mes2)
{
    queue<int> pq;
    //带查找的两个元素入队
    pq.push(mes1);
    pq.push(mes2);
    //设置set集合用来判断是否有共同祖先
    set<int> ms;
    //所有结点（人）的辈分默认为0
    vector<int> level(100010,0);
    //带查找的两个人的辈分设置为1
    level[mes1] = 1;
    level[mes2] = 1;
    while (!pq.empty())
    {   //取出队头元素
        int v = pq.front();
        pq.pop();//出队列
        //计算加入之前的set集合中的人数
        int nu = ms.size();
        //将这个人加入的set集合。
        ms.insert(v);
        //如果发现加入前和加入后元素个数没有变化说明存在相同祖先（即编号相同的元素，这正是利用了set集合不存储
        //相同元素的特点
        if(ms.size() == nu)
            return false;
        //结点是否存在（信息表中是否存在这个人）
        if(peo.count(v) == 0)continue;
        //只有辈分小于5的才判断
        if(level[v] <= 4)
        {
            //得到这个人父亲母亲
            int fa = peo[v].first;
            int ma = peo[v].second;
            //存在父亲或者母亲的话加入到队列（辈分为儿子的辈分加一）
            if(fa != -1)
            {
                pq.push(fa);
                level[fa] = level[v] + 1;
            }
            if(ma != -1)
            {
                pq.push(ma);
                level[ma] = level[v] + 1;
            }
        }
    }
    return true;
}
int main()
{
    cin>>N;
    while (N--)
    {
        int a,af,am;
        char c;
        cin>>a>>c>>af>>am;
         peo[a]= make_pair(af,am);

        if(c == 'M')
            sex[a] = 1;
        if(c == 'F')
            sex[a] = 0;

            sex[af] = 1;
            sex[am] = 0;
    }
    cin>>K;
    while (K--)
    {
        int stu1,stu2;
        cin>>stu1>>stu2;
        if(sex[stu1] == sex[stu2])
            cout<<"Never Mind"<<endl;
        else 
            cout<<(check(stu1,stu2) ? "Yes\n" : "No\n");
    }
    
    return 0;
}