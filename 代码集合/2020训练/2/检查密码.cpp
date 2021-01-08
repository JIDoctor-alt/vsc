#include<iostream>
#include<string>
using namespace std;
int N;
void judge(string &sx)
{
    bool fA = false,Fint = false,Fchar = false,Flaw = false;
    for(auto &c : sx)
    {
        if(isalpha(c))
            fA = true;
        if(isdigit(c))
            Fint = true;
        if(c == '.')
            Fchar = true;
        if(c != '.' && !isalpha(c) &&!isdigit(c))
            Flaw = true;
    }
    if(sx.size() < 6)
    {
        cout<<"Your password is tai duan le.\n";
        return;
    }
    if(Flaw)
    {
        cout<<"Your password is tai luan le.\n";
        return;
    }
    if(fA&&!Fint)
    {
        cout<<"Your password needs shu zi.\n";
        return;
    }
    if(Fint&&!fA)
    {
        cout<<"Your password needs zi mu.\n";
        return;
    }
    cout<<"Your password is wan mei.\n";


}
int main()
{
    cin>>N;
    getchar();
    for(int i = 0;i < N;++i)
    {
        string str;
        getline(cin,str);
        judge(str);   
    }
    return 0;
}