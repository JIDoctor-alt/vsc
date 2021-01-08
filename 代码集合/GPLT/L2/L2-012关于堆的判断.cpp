#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int a[1006];
int N,M;
void pushHead(int x)
{
    
    while(x != 1 && a[x/2] > a[x]){
        swap(a[x/2],a[x]);
        x /= 2;
    }

}
int find(int x){
    for(int i = 1;i <= N;++i)
    {
        if(x == a[i])
            return i;
    }
}
int main()
{
    cin>>N>>M;
    for(int i = 1;i <= N;++i)
    {
        cin>>a[i];
        pushHead(i);
    }

    for(int i = 0;i < M;++i){
        getchar();
        int x;
        string st1;
        cin>>x>>st1;

        if(st1 == "and"){//x，y是兄弟
            int y;
            string st2,st3;
            cin>>y>>st2>>st3;
            int xid = find(x), yid = find(y);
            cout<<(xid/2 == yid/2 ? "T\n" : "F\n");
        }else{
            string st2,st3;
            cin>>st2>>st3;
            if(st3 == "root")
            {
                cout<<(find(x) == 1 ? "T\n" : "F\n");
            }else{
                if(st3 == "parent"){//x是y的父结点
                    string st4;
                    int y;
                    cin>>st4>>y;
                    int xid = find(x),yid = find(y);
                    cout<<(xid == (yid/2) ? "T\n" : "F\n");
                }else{
                    string st4;
                    int y;
                    cin>>st4>>y;
                    int xid = find(x),yid = find(y);//x是y的一个子结点
                    cout<<((xid/2) == yid ? "T\n" : "F\n");
                }   
            }
        }
    }

    return 0;
}