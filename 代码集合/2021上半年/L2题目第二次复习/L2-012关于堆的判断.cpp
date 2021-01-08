#include<iostream>
#include<string>
using namespace std;
int a[1005];
int N,M;
void Headpush(int x,int i)
{
    a[i] = x;
    if(i == 1)
        return;
    while(i != 1)
    {
        if(a[i] < a[i/2])
        {
            swap(a[i],a[i/2]);
            i /= 2;
        }
        else 
            break;
    }
}
int findIndex(int x)
{
    for(int i = 1;i <= N;++i)
        if(a[i] == x)
                return i;
}
int main()
{
    cin>>N>>M;
    for(int i = 1;i <= N;++i)
    {
        int num;
        cin>>num;
        Headpush(num,i);
    }
    for(int i = 1;i <= M;++i)
    {
        int x;
        string str1;
        cin>>x;
        cin>>str1;
        if(str1 == "and")//x and y are siblings 
        {
            int y;
            string str2,str3;
            cin>>y;
            cin>>str2>>str3;
            int xindex = findIndex(x),yindex = findIndex(y);
            if(xindex/2 == yindex/2 && xindex != yindex)
                cout<<"T"<<endl;
            else 
                cout<<"F"<<endl;
        }
        else 
        {
            string str2,str3;
            cin>>str2>>str3;
            if(str3 == "root")//x is the root 
            {
                if(findIndex(x) == 1)
                    cout<<"T"<<endl;
                else 
                    cout<<"F"<<endl;
            }
            else  if(str3 == "parent")
            {
                string str4;
                int y;
                cin>>str4>>y;
                int xid = findIndex(x), yid = findIndex(y);
                if(xid == yid/2)
                {
                    cout<<"T"<<endl;
                }
                else 
                {
                    cout<<"F"<<endl;
                }
            }
            else if(str3 == "child")
            {
                string str4;
                int y;
                cin>>str4>>y;
                int xid = findIndex(x),yid = findIndex(y);
                if(xid/2 == yid)
                {
                    cout<<"T"<<endl;
                }
                else 
                {
                    cout<<"F"<<endl;
                }
            }
        }
    }
    return 0;
}