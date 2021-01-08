#include<iostream>

using namespace std;
void Merge(int a[],int s,int m ,int e,int temp[]){
    int pb = 0;
    int p1 = s,p2 = m + 1;
    while(p1 <= m && p2 <= e){
        
        if(a[p1] < a[p2]){
            temp[pb++] =  a[p1++];
        }else{
            temp[pb++] = a[p2++];
        }
    }

    while (p1 <= m)
    {
        temp[pb++] = a[p1++];
    }
    
    while (p2 <= e)
    {
        temp[pb++] = a[p2++];
    }

    for(int i = 0;i <= e-s+1;i++){
        a[i+s] = temp[i];
    }
    
}
void MergeSort(int a[],int s,int e,int temp[]){
    if(s < e){
        int m = s + (e - s);
        MergeSort(a,s,m,temp);
        MergeSort(a,m+1,e,temp);
        Merge(a,s,m,e,temp);
    }
}
int main(){
    
    return 0;
}