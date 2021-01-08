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
    
    while(startA != -1){
        st.push_back({startA,Peo[startA].data,Peo[startA].Next});
        startA = Peo[startA].Next; 
    }
   /* for(int i = 0;i < st.size();i++){
        cout<<st[i].address<<" "<<st[i].data<<" "<<st[i].Next<<endl;
    }*/
    int len = st.size();
    int ans = 0;
    vector<node> result;
    for(int i = 0,j = len-1;ans <= len;i++,j--){
        result.push_back({st[j].address,st[j].data,st[i].address});
        ans++;
        if(ans < len)
        result.push_back({st[i].address,st[i].data,st[j-1].address});
        ans++;
        
    }
    /*int l = 0,r  = len -1;
    while (true)
    {
        result.push_back({st[r].address,st[r].data,st[l].address});
        r--;
        if((r+1)-(l-1) == 1)break;
        result.push_back({st[l].address,st[l].data,st[r].address});
        l++;
        if((r+1)-(l-1) == 1)break;
    }*/
    

    for(int i = 0;i < len;i++)
        {   
            printf("%05d %d",result[i].address,result[i].data);
            if(i < len-1)printf(" %05d\n",result[i].Next);
            else printf(" -1\n");
        }

    return 0;
}