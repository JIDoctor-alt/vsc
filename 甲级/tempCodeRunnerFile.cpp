#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> a = {"zero","one","two","three","four","five","six","seven","eight","nine"};
int main()
{
    string str;
    cin>>str;
    int sum = 0;
    for(auto &c : str)
    {
        sum += (c - '0');
    }
    string test = to_string(sum);
    cout<<a[(test[0] - '0')];
    for(int i = 1;i < test.size();++i)
    {
        cout<<" "<<a[(test[i] - '0')];
    }
    cout<<endl;
    return 0;
}