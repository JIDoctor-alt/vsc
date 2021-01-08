#include<iostream>
#include<string>
using namespace std;
const int MAX_V = 110;
char ta[MAX_V][MAX_V];
int N;
char c;
bool Valid()
{
    for(int i = N -1;i >= 0;--i)
    {
        for(int j = N - 1; j >= 0;--j)
        {
            if(ta[i][j] != ta[N - 1 - i][N - 1 - j])
                return false;
        }
    }
    return true;
}
int main()
{
    string str;
    cin>>c>>N;
    getchar();
    for(int i = 0;i < N;++i)
    {
        getline(cin,str);
        for(int j = 0;j < str.size();++j)
            ta[i][j] = str[j];
    }
    if(Valid())
    {
        cout<<"bu yong dao le"<<endl;
    }
    for(int i = N - 1;i >= 0;--i)
    {
        for(int j = N - 1;j >= 0;--j)
        {
            if(ta[i][j] != ' ')
                cout<<c;
            else 
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}