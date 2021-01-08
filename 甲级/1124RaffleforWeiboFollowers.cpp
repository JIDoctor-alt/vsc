#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
set<string> pro;
int main()
{
    int M,N,S;
    cin>>M>>N>>S;
    int ans = 1,cnt = 0;
    for(int i = 0;i < M;++i)
    {
        string name;
        cin>>name;
        if(pro.count(name))
            continue;

        if((ans == S && cnt == 0)||(ans == N && cnt != 0))
        {
          //  cout<<"---------\n";
            cout<<name<<endl;
            pro.insert(name);
            ans = 0;
            ++cnt;
        }
        ++ans;
    }
    if(cnt == 0)
        cout<<"Keep going...\n";
    return 0;
}