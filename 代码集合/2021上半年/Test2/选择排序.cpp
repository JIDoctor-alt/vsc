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