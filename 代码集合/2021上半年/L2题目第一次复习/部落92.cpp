#include<iostream>
#include<set>
#include<algorithm>

using namespace std;
int father[10005];
int find(int x)
{
    return x == father[x] ? x : find(father[x]);
}
void un(int x ,int y)
{
    int nx = find(x);
    int ny = find(y);
    if(nx == ny)return;

    if(nx < ny)father[ny] = nx;
    else 
        father[nx] = ny;
}
int main()
{
    for(int i = 0;i <= 10005;i++)
        father[i] = i;
    int N;
    cin>>N;
    set<int> total;
    while(N--)
    {
        int k,a;
        cin>>k>>a;
        total.insert(a);
        //注意这里是--操作之前的a已经输入一个数了
        while(--k)
        {
            int b;
            cin>>b;

            un(a,b);
            total.insert(b);
        }
    }
    int people = total.size();
    int ans = 0;
    for(int i = 1;i <= people;i++)
        if(father[i] == i)ans++;
    
    cout<<people<<" "<<ans<<endl;
    int Q;
    cin>>Q;
    while(Q--)
    {
        int wa,wb;
        cin>>wa>>wb;
        cout<<(find(wa) == find(wb) ? "Y" : "N")<<endl;
    }
    return 0;
}