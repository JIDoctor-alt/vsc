#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
const int MAX_C = 6;
struct edge
{
    int fullmark,options,CorrectO;
    char w[MAX_C];
};
edge stu[1005];
bool judge(int x,char c)
{
    for(int i = 0;i < stu[x].CorrectO;++i)
    {
        if(c == stu[x].w[i])
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int N,M;
    cin>>N>>M;
    for(int i = 0;i < M;++i)
    {
        int score,numops,answer;
        cin>>score>>numops>>answer;
        stu[i].fullmark = score;
        stu[i].options = numops;
        stu[i].CorrectO = answer;
        for(int j = 0;j < answer;++j)
        {
            cin>>stu[i].w[j];
        }
    }
    for(int i = 0;i < N;++i)
    {
        string str;
        getline(cin,str);
        int cnt = 0;
        for(int d = 0; d < str.size();++d)
        {
            if(str[i] == '(')
            {
                ++cnt;
                int c = (str[d + 1] - '0');
                ++d;
                int us = 0;
                while(true)
                {
                    ++d;
                    if(isalpha(str[d]))
                    {
                        if(judge(cnt,str[d]))
                        {
                            cout<<str[d];
                        }
                    }
                    if(str[d] == ')')
                    {
                        break;
                    }
                }
            }
        }
        cout<<endl;
    }

    return 0;
}