#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
int index[10] = {0};
int main()
{
    set<int> stu;
    string str;
    getline(cin,str);
    for(int i = 0;i < str.length();++i)
        stu.insert(str[i]);
    set<int>::reverse_iterator fl;
    int  ans = 0;
    cout<<"int[] arr = new int[]{";
    for(fl = stu.rbegin();fl != stu.rend();++fl)
    {
        int num = (*fl - '0');
        if(ans)cout<<",";
        cout<<num;
        index[num] = ans++;
    }
    cout<<"};"<<endl;
    cout<<"int[] index = new int[]{";
    for(int i = 0;i < str.length();++i)
    {
        int num = (str[i] - '0');
        if(i)cout<<",";
        cout<<index[num];
    }
    cout<<"};"<<endl;

    return 0;
}