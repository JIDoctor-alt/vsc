#include<iostream>
#include<vector>
#include<map>
#include<iomanip>
using namespace std;
int N,K,M;
bool visited[100100];
bool ms[100100];
int main()
{
    cin>>N;
    while (N--)
    {
        cin>>K;
        for(int i = 0;i < K;++i)
        {
            int id;
            cin>>id;
            if(K > 1)//之前自己帅，但现在有朋友了（K等于1说明没有朋友，自己一个人呆着）
                ms[id] = true;
        }
    }
    cin>>M;
    vector<int> res;
    for(int i = 0;i < M;++i)
    {
        int id;
        cin>>id;
        if(!ms[id]&&!visited[id])//没有朋友
        {
            res.push_back(id);
            visited[id] = true;
        }
    }
    int s = res.size();
    if(!s)
        cout<<"No one is handsome"<<endl;
    else
    {
        printf("%05d",res[0]);
        for(int i = 1;i < s;++i)
            printf(" %05d",res[i]);
    }
    return 0;
}