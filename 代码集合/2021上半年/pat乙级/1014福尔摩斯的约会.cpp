#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    string str1,str2;
    string day[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int ans = 0;
    char c1,c2;
    int c3;
    for(int i = 0;i < 2;++i)
    {
        getline(cin,str1);
        getline(cin,str2);

        if(i == 0)
        {
            for(int k = 0;k < str1.size();++k)
            {
                if(str2.find(str1[k]) != string::npos && isupper(str1[k]))
                {
                    ++ans;
                    if(ans == 1)
                    {
                        c1 = str1[k];
                    }
                    if(ans == 2)
                    {
                        c2 = str1[k];
                        break;
                    }
                }
            }
        }
        if(i == 1)
        {
            for(int k = 0;k < str1.size();++k)
            {
                if(str1[k] == str2[k] && isalpha(str1[k]))
                {
                    c3 = k;
                    break;
                }
            }

        }

    }
    int s1 = c1 - 'A' ;
    int s2;
    if(isdigit(c2))
    {
        s2 = c2 - '0';
    }
    else 
    {
        s2 = 9 + (c2 - 'A' + 1);
    }
    cout<<day[s1]<<" ";
    printf("%02d:%02d",s2,c3);

    return 0;
}