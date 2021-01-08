int BinarySearch(int a[],int size,int p)
{
    int L = 0;//查找区间的左端点
    int R = size - 1;//查找区间的右端点
    //如果查找区间不为空就继续查找
    while(L <= R)
    {   //取查找区间正中元素的下标
        int mid = L + (R-L)/2;
        if(p == a[mid])
            return mid;
        else if(p > a[mid])
            L = mid + 1;//设置新的查找区间的左端点
        else 
            R = mid - 1;//设置新的查找区间的右端点
    }
    return -1;
}//复杂度O(log(n))
int LowerBound(int a[],int size,int p)
{
    int L = 0;//查找区间的左端点
    int R = size - 1;//查找区间的右端点
    int lastPos = -1;//到目前为止找到的最优解
    while(L <= R)//如果查找区间不为空就继续查找
    {
        int mid = L+(R-L)/2;//取查找区间正中元素的下标
        if(a[mid] >= p)
            R = mid - 1;
        else 
        {
            lastPos = mid;
            L = mid + 1;
        }
    }
    return lastPos;
}
int mid = (L + R)/2;//取查找区间正中元素的下标
int mid = L + (R - L)/2;