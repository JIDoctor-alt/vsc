#include<iostream>
#include<vector>
#include<map>
#include<numeric>
#include<set>
#include<algorithm>

using namespace std;
const int MAX_P = 100005;
int pre[MAX_P];
struct edge
{
    int id,fid,mid,numchild,home,homearea;
    int child[MAX_P];
};
struct node
{
    int peohome, h,ha;
}ans[MAX_P];
struct pe
{
    int id, p, hnum,area;
};
int find(int x)
{
    return pre[x] == x ? x : find(pre[x]);
}
void un(int x,int y)
{
    int nx = find(x);
    int ny = find(y);
    if(nx < ny)
        pre[ny] = nx;
    else 
        pre[nx] = ny;
}
vector<edge> stu;
int N;
map<int,int> peo;
bool cmp(pe &x1,pe &x2)
{
    double a1 = x1.area/(x1.p * 1.0);
    double a2 = x2.area/(x2.p * 1.0);
    if(a1 != a2)
        return a1 > a2;
    else 
        return x1.id < x2.id;
}
int main()
{
    cin>>N;
    stu.resize(N);
    iota(pre, pre + MAX_P, 0);
    for(int i = 0;i < N;++i)
    {
        int ourself,fater,mater,k,num,area;
        cin>>ourself>>fater>>mater>>k;
        peo[ourself] = 1;
        stu[i].id = ourself;
        stu[i].fid = fater;
        stu[i].mid = mater;
        if(fater != -1)
        {
            un(ourself,fater);
            peo[fater] = 1;
        }

        if(mater != -1)
        {
            un(ourself,mater);
            peo[mater] = 1;
        }

        for(int j = 0;j < k;++j)
        {
            int x;
            cin>>x;
            stu[i].child[j] = x;
            peo[x] = 1;
            un(ourself,x);
        }
        cin>>num>>area;
        stu[i].home = num;
        stu[i].homearea = area;
    }
    set<int> cnt;
    for(int i = 0;i < N;++i)
    {
        int id = stu[i].id;
        id = find(id);
        cnt.insert(id);
        ans[id].h += stu[i].home;
        ans[id].ha += stu[i].homearea;
    }
    for(auto i : peo)
    {
        int id = find(i.first);
        ans[id].peohome ++;
    }
    cout<<cnt.size()<<endl;
 //   sort(cnt.begin(),cnt.end(),cmp);
    vector<pe> res;

    for(auto w : cnt)
    {
        res.push_back({w,ans[w].peohome,ans[w].h,ans[w].ha});
    }
    sort(res.begin(),res.end(),cmp);
    for(auto w : res)
    {
        //cout<<w.id<<" "<<w.p<<" "<<(w.hnum/(w.p * 1.0))<<" "<<(w.area/(1.0 * w.p))<<endl;
        printf("%04d %d",w.id,w.p);
        printf(" %.3f %.3f\n",(w.hnum/(w.p * 1.0)),(w.area/(1.0 * w.p)));
    }
    return 0;
}