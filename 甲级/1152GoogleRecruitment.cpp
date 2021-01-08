#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
bool judge(int x)
{
    for(int i = 2;i <= sqrt(x);++i)
    {
        if(x % i == 0)
            return false;
    }
    return true;
}
int  N,K;
int main()
{
    cin>>N>>K;
    getchar();
    string str,answer = "";
    getline(cin,str);
    
    for(int i = 0;i < str.size() - K + 1;++i)
    {
        string testnum = str.substr(i,K);
        if(judge(stoi(testnum)))
        {
            answer = testnum;
            break;
        }
    }
    cout<<(answer != "" ? answer+"\n" : "404\n");

    return 0;
}