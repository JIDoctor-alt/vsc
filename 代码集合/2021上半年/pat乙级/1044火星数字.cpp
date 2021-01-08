#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str1[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
    string str2[12] = {"tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
    int N;
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        int num;
        cin>>num;
        int w = num / 13, t = num % 13;
        if(w)
        {
            cout<<str2[w]<<" ";
        }
        cout<<str1[t]<<endl;
    }
    return 0;
}