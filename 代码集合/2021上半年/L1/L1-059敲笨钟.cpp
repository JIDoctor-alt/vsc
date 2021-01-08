#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    int N;
    cin>>N;
    getchar();
    string str;
    while(N--)
    {
        getline(cin,str);
        int ans = 0;
        for(int i = 0;i < str.size();++i)
        {
            if(str[i] == 'o' && str[i + 1] == 'n' && str[i + 2] == 'g'&&(str[i + 3] == ',' || str[i + 3] == '.'))
                ans++;
        }
        if(ans == 2)
        {
            int index = 0;
            int j;
            for(j = str.size() - 1;j >= 0;--j)
            {
                if(str[j] == ' ')
                    index++;
                if(index == 3)
                    break;
            }
            string cs  = str.substr(0,j);
            cout<<cs<<" qiao ben zhong."<<endl;
        }
        else 
        {
            cout<<"Skipped"<<endl;
        }
    }
    return 0;
}