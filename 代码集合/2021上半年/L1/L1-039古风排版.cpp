#include<iostream>
#include<string>
using namespace std;
const int MAX_V = 1010;
char c[MAX_V][MAX_V];
int main()
{
    int N;
    cin>>N;
    string str;
    getchar();
    getline(cin,str);
    int M;
    if(str.size() % N)
        M = str.size() / N + 1;
    else 
        M = str.size() / N;
    
    int ans = 0;
    for(int i = 0;i < M ;i++)
    {
        for(int j = 0;j < N;++j)
        {
            if(ans >= str.size())
                c[i][j] = ' ';
            else 
                c[i][j] = str[ans];
            ++ans;
        }
    }
    for(int i = 0;i < N;++i)
    {
        for(int j = M-1 ;j >= 0;--j)
        {
            cout<<c[j][i];
        }
        cout<<endl;
    }
    return 0;
}