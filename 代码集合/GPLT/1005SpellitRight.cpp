#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    string input;
    getline(cin,input);
    int sum = 0;
    for(int i = 0;i < int(input.size());++i){
        sum += (input[i] - '0');
    }
    string st = to_string(sum);
    int x = (st[0] - '0');
    cout<<str[x];
    for(int i = 1;i < int(st.size());++i){
        x = (st[i] - '0');
        cout<<" "<<str[x];
    }
}