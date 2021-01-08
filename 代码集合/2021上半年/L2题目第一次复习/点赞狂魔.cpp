#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<algorithm>

using namespace std;
struct node{
    string nam;
    int fi;
    double ave;
};
bool cmp(node & a,node & b){
    if(a.fi != b.fi)return a.fi >b.fi;
    else return a.ave < b.ave;
}
int main(){
    int N;
    cin>>N;
    vector<node> v;

    for(int i = 0;i < N;i++){
        string name;
        int num;
        cin>>name;
        cin>>num;
        set<int> st;
        for(int j = 0;j < num;j++){
            int id;
            cin>>id;
            st.insert(id);
        }
       // m[name]={st.size(),1.0/num};
       int cishu = st.size();
        v.push_back({name,cishu,num/(1.0*cishu)});      
    }
    sort(v.begin(),v.end(),cmp);
    int le = v.size();
    int flag = 0;
    if(le >= 3){
        for(int i = 0;i < 3;i++)
        {
        if(flag)cout<<" ";
         cout<<v[i].nam;
        flag = 1;
        }

    }else{
       
     for(int i = 0;i < le;i++)
    {
        if(flag)
            cout<<" "<<v[i].nam;
        else 
            cout<<v[i].nam;
        flag = 1;
    }
    for(int j = le;j < 3;j++)
        cout<<" -";

    }
    
    return 0;
}