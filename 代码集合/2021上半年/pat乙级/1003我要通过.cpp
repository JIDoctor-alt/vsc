#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{
    string str;

    int N;
    cin>>N;
    getchar();
    while (N--)
    {
        bool flag = true;
        getline(cin,str);
        set<char> st;
        for(int i = 0;i < str.size();++i)
        {
            if(str[i] == 'P' || str[i] == 'A' || str[i] == 'T'|| str[i] == ' ')
            {
                if(str[i] == 'P' || str[i] == 'A' || str[i] == 'T')
                    st.insert(str[i]);
            }
            else 
            {
                flag = false;
            }
        }
        if(flag)
        {
            if(st.size() != 3)
                    flag = false;
        }
        for(int i = 0;i < str.size();++i)
        {
            if(str[i] == 'P' &&str[i+1] == 'A' && str[i+2] == 'T'&& i + 2 < str.size())
                flag = true;
        }
        int pindex = -1;
        for(int i = 0;i < str.size();++i)
        {
            if(str[i] == 'P')
                pindex = i;
            if(pindex != -1 && str.substr(i,2) == "AT" && i + 1 < str.size())
                flag = true;
        }
        if(flag)
            cout<<"YES"<<endl;
        else    
            cout<<"NO"<<endl;
    }
    
    return 0;
}