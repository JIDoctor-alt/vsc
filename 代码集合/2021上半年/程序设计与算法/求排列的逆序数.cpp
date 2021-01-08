#include<iostream>

using namespace std;
long long ans = 0;
void Merge(int a[],int s,int m,int e,int temp[]){
    int pb = 0;
    int p1 = s,p2 = m+1;
    int x = m+1;
    for(int i = s;i <= m;i++){
        for(int j = x;j<= e;j++){
            if(a[i] > a[j]){
                ans += (e-j+1);
                x = j;
                break;
            }
        }
    }
    while(p1 <= m && p2 <= e){
        if(a[p1] > a[p2]){
            temp[pb++] = a[p1++];
            //ans += (e-p2);
        }else{
            temp[pb++] = a[p2++];
          
        }
    }

    while(p1 <= m){
        temp[pb++] = a[p1++];
    }
    while(p2 <= e){
        temp[pb++] = a[p2++];
    }
    for(int i = 0;i < e-s+1;i++)
        a[s+i] = temp[i];
}
void MergeSort(int a[],int  s,int e,int temp[]){
    if(s < e){
        int m = s + (e-s)/2;
        MergeSort(a,s,m,temp);
        MergeSort(a,m+1,e,temp);
        Merge(a,s,m,e,temp);
    }
}
int main(){
    int n;
    cin>>n;
    int a[100010],tem[100010];

    for(int i = 0;i < n;i++)
        cin>>a[i];
    MergeSort(a,0,n-1,tem);
    /*cout<<endl;
    for(int i = 0;i < n;i++)
        cout<<a[i]<<" ";*/
    cout<<ans<<endl;
    return 0;
}