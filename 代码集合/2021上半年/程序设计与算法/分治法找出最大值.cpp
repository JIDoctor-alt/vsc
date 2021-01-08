#include<iostream>

using namespace std;
void swap(int & a,int & b){
    int temp = a;
    a = b;
    b = temp;
}
void quickSort(int d[],int s,int e){
    if(s >= e)return;
    int key = d[s];
    int i = s,j = e;
    while(i!=j){
        //大的在右边
        while(i < j&& d[j] >= key)
            j--;
        swap(d[i],d[j]);
        //小的在左边
        while(i < j && d[i] <= key)
            i++;
        swap(d[i],d[j]);
    }
    //key的左边
    quickSort(d,s,i-1);
    //key的右边
    quickSort(d,i+1,e);
    
}
int main(){
    int a[100010];
    int N;
    cin>>N;
    for(int i = 0;i < N;i++)
        cin>>a[i];
   // int m;
  //  cin>>m;
    quickSort(a,0,N-1);
   /* for(int i = N-1;i >= (N-m);i--)
        cout<<a[i]<<endl;*/
    cout<<a[N-1]<<endl;
    return 0;
}