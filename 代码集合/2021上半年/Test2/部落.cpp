#include<iostream>
#include<set>

using namespace std;
int father[10010];
int findFather(int x){
    //return x == father[x] ? x : findFather(father[x]);
    while(father[x]!=x)
        x = father[x];
    return x;
}
set<int> total;
void un(int a,int b){
    total.insert(a);
    total.insert(b);

    int fa = findFather(a);
    int fb = findFather(b);
    if( fa < fb)father[fb] = fa;
    else father[fa] = fb; 
}
int main(){
    for(int i = 0;i <= 10000;i++)father[i] = i;
    int n,k,t,s,q;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>k>>t;
        if(k == 1)un(t,t);
        for(int j = 1;j < k;j++){
            cin>>s;
            un(t,s);
        }
    }

    set<int> cnt;
    for(auto it = total.begin();it!= total.end();it++){
        cnt.insert(findFather(*it));
    }
    //总人数，部落数
    cout<<total.size()<<" "<<cnt.size()<<endl;
    cin>>q;
    for(int i = 0;i < q;i++){
        cin>>t>>s;
        cout<<(findFather(t) == findFather(s) ? 'Y' : 'N')<<endl;
    }
    return 0;
}