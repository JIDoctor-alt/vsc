#include<iostream>
#include<string>
using namespace std;
char M[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
int Valid(string &str)
{
    int sum  = 0;
    for(int i = 0;i < str.size()-1;++i)
    {
        if(isdigit(str[i]))
        {
            sum += (str[i] - '0')*weight[i];
        }
        else 
            return -1;
    }
    return sum%11;
}
int main()
{
    string str;
    int N , ans = 0;
    cin>>N;
    getchar();
    for(int i = 0;i < N;++i)
    {
        getline(cin,str);
        int fl = Valid(str);
        if(fl == -1)
        {
            cout<<str<<endl;
        }
        else 
        {
            if(M[fl] == str[17])
            {
                ++ans;
            }
            else 
            {
                cout<<str<<endl;
            }
        }
    }
    if(ans == N)
    {
        cout<<"All passed"<<endl;
    }
    return 0;
}