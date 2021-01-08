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