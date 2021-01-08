#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
/*bool cmp  (char & n1,char & n2)
{
    return n1 - n2 > 0;
}*/
int main()
{
    string str;
    cin>>str;
    set<char> stu;
    int len = str.length();
    for(int i = 0;i < len;i++)
        stu.insert(str[i]);
    //sort(stu.begin(),stu.end(),cmp);
    map<char,int> mt;
    int index = 0;
    set<char>::reverse_iterator o;
    cout<<"int[] arr = new int[]{";
    for(o = stu.rbegin(); o != stu.rend();o++)
    {
        if(index)
            cout<<","<<*o;
        else 
            cout<<*o;
        mt[*o] = index ;
        index ++;
    }
   
    cout<<"};"<<endl;

    cout<<"int[] index = new int[]{";
    for(int i = 0;i < len;i++)
    {
        if(i)
            cout<<","<<mt[str[i]];
        else 
            cout<<mt[str[i]];
    }
    cout<<"};"<<endl;
    
    
    return 0;
}