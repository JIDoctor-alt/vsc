#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX_P = 100005;
struct peo
{
    int grade;
    int id,mora,ca;
};
bool cmp(peo &e1,peo &e2)
{
    if(e1.grade != e2.grade)
    {
        return e1.grade < e2.grade;

    }
    else 
    {
        int x1 = e1.mora + e1.ca;
        int x2 = e2.mora + e2.ca;

        if(x1 == x2)
        {
            if(e1.mora != e2.mora)
            {
               return e1.mora > e2.mora;
            }
            else 
            {   
                return e1.id < e2.id;
            }

        }
        else 
        {
            return x1 > x2;
        }
    }
}
peo stu[MAX_P];
int N,L,H;
int main()
{
    ios::sync_with_stdio(false);
    cin>>N>>L>>H;
    vector<peo> res;
    for(int i = 0;i < N;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        stu[i].grade = 4;
        stu[i].id  = a;
        stu[i].mora = b;
        stu[i].ca = c;
        if(b >= L && c >= L)
        {
            if(b >= H && c >= H)
            {
                stu[i].grade = 1;
            }
            else if( b >= H && c < H)
            {
                stu[i].grade = 2;
            }
            else if( b < H && c < H && b >= c)
            {
                stu[i].grade = 3;
            }
            res.push_back(stu[i]);
        }
    }
    sort(res.begin(),res.end(),cmp);
   // cout<<"================="<<endl;
    cout<<res.size()<<endl;
    for(auto w : res)
    {
        cout<<w.id<<" "<<w.mora<<" "<<w.ca<<endl;
    }
    return 0;
}