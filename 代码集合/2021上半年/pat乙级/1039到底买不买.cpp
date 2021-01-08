#include<iostream>
#include<string>

using namespace std;
int main()
{
    string str,wt;
    getline(cin,str);
    getline(cin,wt);
    int ans = wt.size(),tr = 0;
    int index;
    for(int i = 0;i < wt.size();++i)
    {
        if(str.find(wt[i]) != string::npos)
        {
            index = str.find(wt[i]);
            str.erase(index,1);
            wt.erase(i,1);
        }
        else 
        {
            ++tr;
        }
    }
    if(tr == 0)
    {
        cout<<"Yes"<<" "<<(str.size())<<endl;
    }
    else 
    {
        cout<<"No"<<" "<<tr<<endl;
    }
    return 0;
}