#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

int N,M;
map<string,int> ms;
map<int,string> pf;
map<int,int> gender;
int pre[100005];
bool check(int x,int y)
{
    vector<int> va,vy;//从所检查结点向上遍历
    for(int i = x; i != -1;i = pre[i])
        va.push_back(i);
    for(int i = y; i != -1;i = pre[i])
        vy.push_back(i);

    if(va.back() != vy.back())
        return true;
    
    int i = va.size() - 1, j = vy.size() - 1;
    for(; i >= 0 && j >= 0 && va[i] == vy[j];)
        --i,--j;
    
    ++i,++j;
    return (i >= 4 && j >= 4);
}
int main()
{
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        string name,id;
        cin>>name>>id;
        //每个人的编号
        ms[name] = i;

        if(id.back() == 'n')
        {
            string fd = id.substr(0,id.size() - 4);
            pf[i] = fd;//每个人对应的父亲
            gender[i] = 1;
        }
        else if(id.back() == 'r')
        {
            string fd = id.substr(0,id.size() - 7);
            pf[i] = fd;
            gender[i] = 0;
        }
        else if(id.back() == 'm' || id.back() == 'f')
        {
            string fd = id.substr(0,id.size() - 1);
            pre[i] = -1;//没有父亲
            gender[i] = ((id.back() == 'm' ? 1 : 0));
        }
    }

    for(int i = 0;i < N;++i)
    {
        if(pre[i] == -1)
            continue;
        //i的父亲  转换为 id int型
        int x = ms[pf[i]];
        pre[i] = x;
    }

    cin>>M;
    while(M--)
    {
        string idx1,idx2, idy1,idy2;
        cin>>idx1>>idx2>>idy1>>idy2;
        int inx = ms.count(idx1) ? ms[idx1] : -1,iny = ms.count(idy1) ? ms[idy1] : -1;
        if(inx == -1 || iny == -1)
        {
            cout<<"NA\n";
        }
        else if(gender[inx] == gender[iny])
        {
            cout<<"Whatever\n";
        }
        else 
        {
            cout<<(check(inx,iny) ? "Yes\n" : "No\n");
        }
    }
    return 0;
}