#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
using pii = pair<string,string>;
int main()
{
    vector<pii> res;
    map<string,int> sex;
    vector<string> ves;
    map<string,bool> visited;
    int N;
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        int id;
        string name;
        cin>>id>>name;
        sex[name] = id;
        ves.push_back(name);
    }
    for(int i = 0;i < N;++i)
    {
         string n = ves[i];
         int ix = sex[n];
         if(!visited[n])
         {
             visited[n] = true;
             for(int j = N-1 ;j >= 0;--j)
             {
                 string nx = ves[j];
                 int in = sex[nx];
                 if(!visited[nx]&& (ix + in) == 1)
                 {

                     visited[nx] = true;
                     res.push_back({n,nx});
                     break;
                 }
             }
         }
         else 
         {
             continue;
         }
    }
    for(auto &w : res)
    {
        cout<<w.first<<" "<<w.second<<endl;
    }
    return 0;
}