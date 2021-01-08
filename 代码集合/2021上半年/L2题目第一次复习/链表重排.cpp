#include<iostream>
#include<vector>

using namespace std;
struct node{
    int address;
    int data;
    int Next;
}Peo[100100];
int main(){
    int startAddress,N;

    cin>>startAddress>>N;

    vector<node> st;

    for(int i = 0;i < N;i++){
        int a,b,c;
        cin>>a>>b>>c;
        //st.push_back({a,b,c});
        Peo[a].address = a;
        Peo[a].data = b;
        Peo[a].Next = c;
    }
    int startA  = startAddress;
    
    while(N--){
        st.push_back({startA,Peo[startA].data,Peo[startA].Next});
        startA = Peo[startA].Next; 
    }
    for(int i = 0;i < N;i++){
        cout<<st[i].address<<" "<<st[i].data<<" "<<st[i].Next<<endl;
    }
    /*for(int i = 0,j = N-1;i != j;i++,j--){
        cout<<st[j].address<<" "<<st[j].data<<" "<<st[i].address<<endl;
        cout<<st[i].address<<" "<<st[i].data<<" "<<st[j-1].address<<endl;
    }*/

    return 0;
}