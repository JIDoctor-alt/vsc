#include<iostream>

using namespace std;

void SelectionSort(int a[],int size)
{
    //从第0个位置开始放最小的元素
    for(int i = 0;i < size - 1;++i)
    {
        //先是假定第i个位置的元素最小
        int tmpMin = i;
        //从后面查找最小元素的下标
        for(int j = i+1;j < size;j++)
        {
            //如果后面的元素小于这个元素就更新tmpMin（记录最小元素的下标）的值
            if(a[j] < a[tmpMin])
                tmpMin = j;     
        }
        //每次找到最小元素之后，将位置i的元素与最小元素的位置进行交换
        int  tmp = a[i];
        a[i] = a[tmpMin];//最小的元素
        a[tmpMin] = tmp;
    }
}
void insertSort(int a[],int size)
{
    for(int i = 1;i < size ;i++)
    {
        int temp = a[i];//要插入的元素
        //a[i]是最左的无需元素，每次将a[i]放到有序元素集合中的合适位置
        for(int j = 0;j < i;j++)
            if(a[j] > a[i]){//找到位置
            //要把a[i]放到位置j，原下标j到i-1的元素都往后移一个位置（这里的a[i]元素直接被有序元素覆盖掉）
               //后移元素
               for(int k = i;k > j;k--)
                     a[k] = a[k-1];
                a[j] = temp;//插入
                break;//插入完成就直接跳出循环进行下一次插入操作
            }

    }
}
void Merge(int a[],int L,int mid,int R,int temp[])
{
    //将数组的a[L,mid]和a[mid+1,R]合并到temp,并保证tmp有序，然后再拷贝回a[L,R]
    //归并操作时间复杂度：O(R-L+1)即O(n)
    int pb = 0;
    int p1 = L,p2 = mid+1;

    while(p1 <= mid && p2 <= R){
        if(a[p1] < a[p2])
           temp[pb++] = a[p1++];
        else 
            temp[pb++] = a[p2++];
    }

    while(p1 <= mid)
       temp[pb++] = a[p1++];
    while(p2 <= R)
        temp[pb++] = a[p2++];
    for(int i = 0;i < R - L +1;i++)
        a[L+i] = temp[i];
}
//
void MegeSort(int a[],int L,int R,int temp[])
{
    if(L < R){
        int mid = (L+R)/2;
    MegeSort(a,L,mid,temp);
    MegeSort(a,mid+1,R,temp);

    Merge(a,L,mid,R,temp);
    }

    
}
void BubbleSort(int a[],int size)
{
      //每次要将未排序部分的最大值移动到下标i的位置
    for(int i = size - 1;i >= 0;i--){
          ///依次比较相邻的两个元素
        for(int j = 0;j < i;j++)
        {
            if(a[j] > a[j+1])
                swap(a[j],a[j+1]);
        }
    }
}
void QuickSort(int a[],int s,int e)
{   
    //边界必须不能相等
    if(s >= e)return;
    int k = a[s];
    int i = s,j = e;
    //int m = s + (e - s)/2;
    //
    while(i != j)
    {
        //还要判断i和j的大小
        while(k <= a[j] && i < j)
            --j;
        swap(a[i],a[j]);
        while(k >= a[i] && i < j)
            ++i;
        
        swap(a[i],a[j]);
    }//处理完后a[i]=k

    QuickSort(a,s,i-1);
    QuickSort(a,i+1,e);
}
void print(int a[],int size)
{
    for(int i = 0;i < size;i++)
        cout<<a[i]<<" ";
}
int main()
{
    int a[5];
    int N;
    cin>>N;
    for(int i = 0;i < N;i++)
        cin>>a[i];
 //   SelectionSort(a,N);
   // insertSort(a,N);
   int b[5];
 //  BubbleSort(a,N);
 //   MegeSort(a,0,N-1,b);
    QuickSort(a,0,N-1);
    print(a,N);
    return 0;
}