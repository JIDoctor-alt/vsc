#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int ansg = 0, ansp = 0, anst = 0, ansl = 0;
void printP()
{
    while(true){
        if(ansg)
    {
        cout<<"G";
        --ansg;
    }
    if(ansp)
    {
        cout<<"P";
        --ansp;
    }
    if(ansl)
    {
        cout<<"L";
        --ansl;
    }
    if(anst)
    {
        cout<<"T";
        --anst;
    }
    if(!(ansg||ansp||ansl||anst))
    break;
    }
    
}
int main()
{
    string str;
    getline(cin,str);
    
    for(int i = 0;i < str.length();++i)
    {
        char c = towupper(str[i]);
        if(c == 'G')
            ++ansg;
        else if(c == 'P')
            ++ansp;
        else if(c == 'T')
            ++anst;
        else if(c == 'L')
            ++ansl;
    }
    printP();
    return 0;
}