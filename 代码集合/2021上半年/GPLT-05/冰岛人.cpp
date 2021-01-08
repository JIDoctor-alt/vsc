#include<iostream>
#include<string>
#include<map>
#include<set>
#include<queue>
using namespace std;
int N,M;
map<string,string> mp;
map<string,int> sex;
/*
map<string, string>mps

if(mps["aa"].empty())使用了empty方法后，mps会创建一个空的的mps["aa"] = ""
*/
bool Valid(string a,string b)
{
    
    set<string> smt1,smt2;
    bool flag = true;
    string name = a;

    for(int i = 0;i < 4 && !name.empty();++i)
    {
        smt1.insert(name);
        name = mp[name];
    }
    while(!name.empty())
    {
        smt2.insert(name);
        name = mp[name];
    }

    name = b;
    for(int i = 0;i < 4 && !name.empty();++i)
    {
        if(smt1.count(name) || smt2.count(name))
        {
            flag = false;
            break;
        }
        name = mp[name];
    }

    while (flag &&!name.empty())//这里
    {
        if(smt1.count(name))
        {
            flag = false;
            break;
        }
        name = mp[name];
    }
    
    return flag;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>N;
    
    for(int i = 0;i < N;++i)
    {
        string n1,n2;
        cin>>n1>>n2;
        //sson 男  sdottir女 
        //m 男  f女
        char c = n2[n2.size()-1];
        if(c == 'm' || c == 'n')
            sex[n1] = 1;
        else 
            sex[n2] = 0;
            //不是维京人是查不到它们的父亲的！！！
        /*
        if(c == 'm' || c == 'f'){
            mp[n1] = n2.substr(0,n2.size()-1);
        }*/
        if(c == 'n'){
            mp[n1] = n2.substr(0,n2.size()-4);
        }else if(c == 'r'){
            mp[n1] = n2.substr(0,n2.size()-7);
        }else
        {
            mp[n1] = "";
        }
        
    }
    cin>>M;
    for(int i = 0;i < M;++i)
    {
        string str1,str2,ct1,ct2;
        cin>>str1>>str2>>ct1>>ct2;
        //有一个人不在名单内
        if(mp.find(str1) == mp.end() || mp.find(ct1) == mp.end())
        {
            cout<<"NA"<<endl;
        }//两个人为同性
        else if(sex[str1] == sex[ct1])
        {
            cout<<"Whatever"<<endl;
        }
        else
        {
            if(Valid(str1,ct1))
                cout<<"Yes"<<endl;
            else 
                cout<<"No"<<endl;   
        }
        
    }
    return 0;
}