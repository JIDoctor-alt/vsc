#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> a,b;
void adjustHeap(int low,int high)
{
    //第一个元素为堆顶元素
    int i = low,j = 2*i;
    //大根堆做下沉操作
    while(j <= high)
    {
        //找到孩子节点最大的与其交换位置
        if(j + 1 <= high && b[j + 1] > b[j])
                ++j;
        if(b[j] > b[i])
        {
            swap(b[j],b[i]);
            i = j;
            j = 2*i;
        }
        else 
        {
            break;
        }
    }
}
int main()
{
    cin>>N;
    a.resize(N+1);
    b.resize(N+1);
    for(int i = 1;i <= N;++i)
        cin>>a[i];
    for(int i = 1;i <= N;++i)
        cin>>b[i];

    int  p = 2;
    //判断是否是插入排序，前面是否已经排好
    while(p <= N && b[p-1] <= b[p])
        ++p;
    int index = p;//插入排序过程中未排序序列中的第一个元素
    ///后面是否和初始相同
    while(p <= N && a[p] == b[p])
        ++p;
    if(p == N + 1)
    {

        cout<<"Insertion Sort\n";
        sort(b.begin() + 1,b.begin() + index + 1);
        for(int i = 1;i <= N;++i)
        {
            cout<<(i != 1 ? " " : "")<<b[i];
        }
        cout<<endl;
    }
    else 
    {
        cout<<"Heap Sort\n";
        p = N;
        //找到堆排序中未排序序列的最后元素的位置
        while(p >= 2 && b[p-1] <= b[p])
            --p;
            //此时p的位置为为排序序列的末尾
        //--p;
        swap(b[1],b[p]);//第一个元素为未排序序列中的最大值，将其插入到排序序列的首部
        //对未排序序列进行堆调整
        adjustHeap(1,p-1);
        for(int i = 1;i <= N;++i)
        {
            cout<<(i != 1 ? " " : "")<<b[i];
        }
        cout<<endl;
    }
    
    return 0;
}