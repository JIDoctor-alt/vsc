#include<iostream>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
    string str,pw;
    int N;
    cin>>str>>N;
    vector<string> res;
    while(cin>>pw && pw != "#")
    {
        res.push_back(pw);
    }
    bool flag = false;
    int i;
    for(i = 0;i < res.size();++i)
    {
        pw = res[i];
        if(pw == str)
        {
            flag = true;
            cout<<"Welcome in"<<endl;
            break;
        }
        else
        {
            cout<<"Wrong password: "<<pw<<endl;
            if(i == N-1)
            {
                break;
            }
        }

        if(i == N-1)
        {
            break;
        }
        
    }
    if(!flag && i == N-1)
    {
        cout<<"Account locked"<<endl;
    }
    return 0;
}