#include<iostream>
#include<algorithm>
#include<chrono>
#include<functional>
using namespace std;
using namespace std::chrono;
//冒泡排序
int temp[10000000];
int a[10000000];
void MoSort(int a[],int size){

    for(int  i = size - 1;i > 0;i--){
        for(int j = 0;j < i;j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
//选择排序
void selectSort(int a[],int size){
    for(int i = 0;i < size - 1;i ++){
        int  minIndex = i;
        for(int j = i+1;j < size;j++){
            if(a[minIndex] > a[j]){
                minIndex = j;
            }
        }
        int temp = a[minIndex];
        a[minIndex] = a[i];
        a[i] = temp;
    }
}//(size的平方)
//插入排序
void InsertSort(int a[],int size){
    for(int i = 1;i < size;i++){

        for(int j = 0;j < i;j++){
            if(a[i] < a[j]){

                int temp = a[i];
                for(int k = i;k > j;k--)
                    a[k] = a[k-1];
                a[j] = temp;
                break;
            }
        }
    }
}
//归并排序

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

//快速排序
void swap(int & a,int & b){
    int temp = a;
    a = b;
    b = a;
}
void QuickSort(int a[],int s,int e){
    if(s < e)return;
    int k = a[s];
    int i = s,j = e;
    while(i != j){
        while( j > i && a[j] >= k)
            j--;
        swap(a[i],a[j]);
        while( j > i && a[i] <= k)
            i++;
        swap(a[i],a[j]);

    }
    QuickSort(a,s,i-1);
    QuickSort(a,i+1,e);
}
//系统sort

int main(){
    int N;
    cin>>N;
    for(int i = 0;i < N;i++)
        cin>>a[i];
    
    //冒泡排序
    auto itM1 = high_resolution_clock::now();
    MoSort(a,N);
    auto itM2 = high_resolution_clock::now();

    cout<<"冒泡排序： "<<duration_cast<milliseconds>(itM2-itM1).count()<<" ms"<<endl;

    //选择排序
    auto itS1 = high_resolution_clock::now();
    selectSort(a,N);
    auto itS2 = high_resolution_clock::now();

    cout<<"选择排序： "<<duration_cast<milliseconds>(itS2-itS1).count()<<" ms"<<endl;

    //插入排序
    auto itI1 = high_resolution_clock::now();
    InsertSort(a,N);
    auto itI2 = high_resolution_clock::now();
    
    cout<<"插入排序： "<<duration_cast<milliseconds>(itI2-itI1).count()<<" ms"<<endl;

    //归并排序
    auto itMger1 = high_resolution_clock::now();
    MergeSort(a,0,N-1,temp);
    auto itMger2 = high_resolution_clock::now();

    cout<<"归并排序： "<<duration_cast<milliseconds>(itMger2-itMger1).count()<<" ms"<<endl;

    //快速排序
    auto Q1 = high_resolution_clock::now();
    QuickSort(a,0,N-1);
    auto Q2 = high_resolution_clock::now();
    cout<<"快速排序： "<<duration_cast<milliseconds>(Q2-Q1).count()<<" ms"<<endl;

    //系统sort排序
    auto it1 = high_resolution_clock::now();
    sort(a+0,a+N);
    auto it2 = high_resolution_clock::now();
    
    //毫秒
    cout<<"系统sort: "<<duration_cast<milliseconds>(it2-it1).count()<<" ms"<<endl;
 
    return 0;
}
