#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
using pii = pair<int,int>;
map<int,char> sex;
map<int,pii> pre;
bool visited[100005];
int N;

bool judge(int x,int y,int deep)
{   
    if(deep >= 5)
        return true;

    if(x == -1 || y == -1 || !pre.count(x)||!pre.count(y))
        return true;

    int xf = pre[x].first,xm = pre[x].second;
    int yf = pre[y].first,ym = pre[y].second;

    if((xf == yf && xf > 0 && yf > 0)|| (xm == ym && xm > 0 && ym > 0))
        return false;
    return judge(xf,ym,deep + 1)&&judge(xf,yf,deep + 1)&&judge(xm,yf,deep + 1)&&judge(xm,ym,deep + 1);

}
int main()
{
    cin>>N;
    for(int i = 0;i < N;++i)
    {
        int x,fa,mi;
        char c;
        cin>>x>>c>>fa>>mi;
        sex[x] = c;
        if(fa != -1)
        {      
            sex[fa] = 'M';
        }
        if(mi != -1)
        {
            sex[mi] = 'F';
        }
        pre[x].first = fa;
        pre[x].second = mi;
    }
    int K;
    cin>>K;
    for(int i = 0;i < K;++i)
    {
        int x,y;
        cin>>x>>y;
        if(sex[x] == sex[y])
        {
            cout<<"Never Mind"<<endl;
        }
        else 
        {
            if(judge(x,y,1))
                cout<<"Yes"<<endl;
            else 
                cout<<"No"<<endl;
        }
    }
    return 0;
}