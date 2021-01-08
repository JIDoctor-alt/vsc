#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;
int N;
map<string,int> mes;
map<int,set<string> > anser;
//set函数自动排序，begin（）获取第一个元素的迭代器。注意输出格式
int MAXnum = -1;
int main(){
    cin>>N;
    while(N--)
    {
        string str1;
        string str2;
        cin>>str1>>str2;
        mes[str1]++;
        mes[str2]++;
        if(MAXnum < mes[str1])
            MAXnum = mes[str1];
        if(MAXnum < mes[str2])
            MAXnum = mes[str2];
        anser[mes[str1]].insert(str1);
        anser[mes[str2]].insert(str2);
    }

    cout<<*anser[MAXnum].begin()<<" "<<MAXnum;
    if(anser[MAXnum].size() != 1)
    {
        cout<<" "<<anser[MAXnum].size()<<endl;
    }
    return 0;
}