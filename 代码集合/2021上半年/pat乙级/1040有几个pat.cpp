#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    int cnt = 0;
    for(int i = 0;i < str.size();++i)
    {
        if(str[i] == 'P')
        {
            string sw = str.substr(i,str.size() - 1);
            if(sw.find('A') != string::npos)
            {
                int x = sw.find('A');
                string ps = sw.substr(x,sw.size()-1);

                if(ps.find('T') != string::npos)
                {
                    ++cnt;
                }
            }
        }
        
        
    }
    cout<<(cnt % 1000000007)<<endl;
    return 0;
}