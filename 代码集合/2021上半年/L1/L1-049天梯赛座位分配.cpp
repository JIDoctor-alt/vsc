#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int s[110];
    int stream;
    for(int i = 0;i < N;++i)
    {
        cin>>stream;
        s[i] = stream * 10;
    }
    int k = 1;
    int num = 0;
    vector<vector<int> > stu;
    stu.resize(N);
    bool visited[110];
    memset(visited,false,sizeof(visited));
    while(num < N)
    {
        for(int i = 0;i < N;++i)
        {
            if((stu[i].size() < s[i]) && (!visited[i]))
            {
                stu[i].push_back(k);

                if(num != N-1)
                    ++k;
                else 
                    k += 2;
            }
            if(stu[i].size() == s[i] && !visited[i])
            {
                   visited[i] = true;
                   num++;
            }
        }
    }
    for(int i = 0;i < N;++i)
    {
        cout<<"#"<<(i+1)<<endl;
        int x = 1;
        for(int j = 0;j < stu[i].size();++j)
        {
            cout<<stu[i][j]<<(x % 10 ? " " : "\n");
            x++;
        }
    }

    return 0;
}