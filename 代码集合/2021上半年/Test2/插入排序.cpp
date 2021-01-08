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