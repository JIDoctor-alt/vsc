#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
    int N;
    cin>>N;
    set<int> stu;
    for(int i = 0;i < N;i++)
    {
        int num;
        cin>>num;
       
        if(stu.upper_bound(num) != stu.end())
        {
            stu.erase(*stu.upper_bound(num));
            stu.insert(num);
        }
        stu.insert(num);
    }
    cout<<stu.size()<<endl;
    return 0;

}