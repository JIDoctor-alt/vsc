#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int maxValue = 1;
    string s;
    getline(cin,s);
    for(int i = 0;i < s.size();++i)
    {
        string str;
        for(int j = i;j < s.size();++j)
        {
            str += s[j];
            string c = str;
            reverse(c.begin(),c.end());
            if(str == c)
            {
                //cout<<maxValue<<endl;
                if(maxValue < c.size())
                {
                 //   cout<<str.size()<<endl;
                    maxValue = c.size();
                }
            }
        }
    }
    cout<<maxValue<<endl;
    return 0;
}