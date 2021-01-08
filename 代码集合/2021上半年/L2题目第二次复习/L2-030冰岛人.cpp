#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<string>
using namespace std;
const int MAX_PEO = 100005;
vector<int> pre;
vector<int> gender;
vector<string> sn,fn;
map<string,int> mp;
int N,M;
bool check(int x,int y)
{
    vector<int> stu1;
    while (x != -1)
    {
        stu1.push_back(x);
        x = pre[x];
    }
    vector<int> stu2;
    while(y != -1)
    {
        stu2.push_back(y);
        y = pre[y];
    }
    if(stu1.back() != stu2.back())
        return true;
    int i = stu1.size() - 1, j = stu2.size() - 1;
    for(;i >= 0 && j >= 0;--j,--i)
    {
        if(stu1[i] != stu2[j])
            break;
    }
    ++j,++i;
    return (i >= 4)&&(j >= 4);
}
int main()
{
    cin>>N;
    gender.resize(N);
    pre.resize(N);
    sn.resize(N);
    fn.resize(N);
    for(int i = 0;i < N;++i)
    {
        string  name1,str1;
        cin>>name1>>str1;
        fn[i] = name1;

        if(str1.back() == 'r')
        {
            gender[i] = 0;
            sn[i] = str1.substr(0,str1.size() - 7);
            mp[name1] = i;
            
        }
        else if(str1.back() == 'n')
        {
            gender[i] = 1;
            sn[i] = str1.substr(0,str1.size() - 4);
            mp[name1] = i;
        }
        else if(str1.back() == 'm')
        {
            gender[i] = 1;
            sn[i] = str1.substr(0,str1.size()-1);
            mp[name1] = i;
            pre[i] = -1;
        }
        else if(str1.back() == 'f')
        {
            gender[i] = 0;
            sn[i] = str1.substr(0,str1.size() - 1);
            pre[i] = -1; 
            mp[name1] = i;
        }
    }
    for(int i = 0;i < N;++i)
    {
        if(pre[i] == -1)
            continue;
        int x = mp[sn[i]];
        pre[i] = x;
    }
    cin>>M;
    while(M--)
    {
        string n1,s1,n2,s2;
        cin>>n1>>s1>>n2>>s2;

        int id1 = mp.count(n1) ? mp[n1] : -1;
        int id2 = mp.count(n2) ? mp[n2] : -1;

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