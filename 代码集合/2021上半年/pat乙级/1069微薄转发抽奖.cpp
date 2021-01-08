#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
int main()
{
    int M,N,S;
    map<string,int> ms;
    vector<string> res;
    res.push_back(" ");
    cin>>M>>N>>S;
    int ans = 0,index = S;
    for(int i = 0;i < M;++i)
    {
        string name;
        cin>>name;
        res.push_back(name);
    }
    if(M < S)
    {
        cout<<"Keep going..."<<endl;
    }
    else 
    {
        for(int i = S;i <= M;i += N)
        {
            while(ms[res[i]] >= 1)
            {
                ++i;
            }
           cout<<res[i]<<endl;
           ++ms[res[i]];
        }
   //     if(ans == 0)
    }
    return 0;

}