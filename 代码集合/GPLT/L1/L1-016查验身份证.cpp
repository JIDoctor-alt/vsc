#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char M[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
int judge(string &str)
{
    int sum = 0;
    for(int i = 0;i < str.size() - 1;++i)
    {
        if(isdigit(str[i]))//isalpha是否为英文字母，isalnum检查是否为字母或数字
            sum += (str[i] - '0')*(weight[i]);
        else 
            return false;
    }
    int index = sum % 11;
    if(M[index] != str[str.size() - 1])
        return false;
    return true;
}
int main()
{
    int N;
    cin>>N;
    getchar();
    string str;
    int cnt = 0;
    for(int i = 0;i < N;++i)
    {
        getline(cin,str);
        if(!judge(str))
            cout<<str<<endl;
        else 
            ++cnt;
    }
    if(cnt == N)
        cout<<"All passed"<<endl;
    return 0;
}