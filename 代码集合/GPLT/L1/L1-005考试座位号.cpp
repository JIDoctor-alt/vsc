#include<iostream>
#include<string>
using namespace std;
struct node
{
    string id;
    int setId;
};
node a[1005];
int N;
int main()
{
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        string id;
        int x,y;
        cin>>id>>x>>y;
        a[x].id = id;
        a[x].setId = y;
    }
    int M;
    cin>>M;
    for(int i = 0;i < M;++i)
    {
        int sid;
        cin>>sid;
        cout<<a[sid].id<<" "<<a[sid].setId<<endl;
    }
    return 0;
}