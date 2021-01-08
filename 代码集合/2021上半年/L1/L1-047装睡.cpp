#include<iostream>
#include<string>
using namespace std;
bool Valid(int x,int y)
{
    if(!((15 <= x && x <= 20) &&(50 <= y && y <= 70)))
        return false;
    return true;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string name;
        int s1,s2;
        cin>>name>>s1>>s2;
        if(!Valid(s1,s2))
            cout<<name<<endl;
    }
    return 0;
}