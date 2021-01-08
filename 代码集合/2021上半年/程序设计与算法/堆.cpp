#include<iostream>
using namespace std;
int n,typeNum;
int a[100100],t = 0;
void HeapPush(int u)
{
    a[++t] = u;//首先插入到数组尾部
    //p为该节点，pa为父结点。如果父结点元素要大则交换位置，
    //直到父结点小于等于插入的元素结束
    for(int p = t,pa = p/2; p > 1&&a[p] < a[p/2];p = pa)
    {
        pa = p/2;
        swap(a[p],a[pa]);
    }
    /*
    int pa = t;
    for(; a[pa/2] > u && pa > 1;pa /= 2 )
        a[pa] = a[pa/2];
    a[pa] = u;
    */
}
int HeapPop()
{
    int ans = a[1];//取出根结点的值
    swap(a[1],a[t--]);//数组尾部元素和根结点交换位置（先用后减）
    //从根节点开始执行下沉动作
    //（从根结点和 左节点开始判断，判断条件为是否有左孩子，再将最小的结点设置为根结点判断）
    for(int p = 1,c = 2;2*p <= t;p = c)
    {//查找左右子节点中最小的元素 2*i 和 2*i + 1
        c = 2*p;//c为根结点的左孩子
        //如果存在右孩子并且小于左孩子
        if(c < t && a[c + 1] < a[c])
            ++c;
        if(a[p] < a[c])
            break;
        //如果最小的子结点大于或者等于根结点则根结点下沉
        //交换位置
        swap(a[p],a[c]);
    }
    return ans;
}
int main()
{
    cin>>n;
    while (n--)
    {
        cin>>typeNum;
        if(typeNum == 1)
        {
            int u;
            cin>>u;
            HeapPush(u);
        }
        else 
        {
            cout<<HeapPop()<<endl;
        }
    }
    return 0;
}

/*a[i] >= a[2*i]&&a[i] >= a[2*i+1] //大根堆 
或
a[i] <= a[2*i]&&a[i] <= a[2*i+1]//小根堆*/