#include<iostream>

using namespace std;
int H[100100],Hsize = 0;

void BTree(int num)
{
    H[++Hsize] = num;
    int i = Hsize;
    //先插入到最后的位置，判断父结点是否比它要大
    //大的话就要上移，父结点需要和num换位置
   // for(;H[i/2] > num;i/=2)
  //          H[i] = H[i/2];
    //跳出循环说明找到位置
    while(H[i/2] > num)
    {
        H[i] = H[i/2];
        i /= 2;
    }
    H[i] = num;

}
int DeletHeap()
{
    int MinHeap ;
    int  temp;
    if(Hsize == 0){
        cout<<"堆空"<<endl;
        return -1;
    }
    
     MinHeap = H[1];//堆顶元素
    //取出最后一个元素并减小堆
    temp = H[Hsize--];
    
    int Parent = 1,Child;
    for(;2*Parent <= Hsize;Parent = Child)
    {
        Child = 2*Parent;
        if(Child != Hsize && H[Child] > H[Child+1])
            Child++;

        if(temp <= H[Child])break;
        else
        {
            H[Parent] = H[Child];
        }
        
    }
    H[Parent] = temp;
    
    return MinHeap;
    
    
}
int main()
{
    int n,type;H[0] = -1;
    cin>>n;
    while(n--){
        cin>>type;
        if(type == 1){
            int number;
            cin>>number;
            BTree(number);
        }else if(type == 2){
            cout<<DeletHeap()<<endl;
        }
    }
    return 0;
}