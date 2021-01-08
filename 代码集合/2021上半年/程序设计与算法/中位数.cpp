#include<iostream>
#include<vector>
using namespace std;
int getMedian(vector<int> &arr,int L,int R)
{
    for(int i = L + 1;i <= R;i++)
    {
        for(int j = i-1; j >= L && arr[j]  > arr[j + 1];--j)
            swap(arr[j],arr[j + 1]);
    }
    return arr[(L+R)/2];
}
int mom(vector<int> &arr,int L,int R)
{
    int arrLen = R - L + 1;
    int mLen = arrLen / 5,mR = 0;
    //向上取整
    if(arrLen % 5)
        ++mR;
    vector<int> mArr(mLen+mR);
    for(int i = 0;i < mLen; ++i)
    {
        int s = L + 5 * i , e = L + 4;
        mArr[i] = getMedian(arr,s,e);
    }
    if(mR)
        mArr[mLen] = getMedian(arr,L + 5 * mLen,R);
    mLen += mR;
    return select(mArr,0,mLen - 1,mLen/2);
}
int partition(vector<int> &arr,int L,int R,int pivot)
{
    int i = L - 1,j = R + 1,cur = L;
    while(cur < j)
    {
        if(arr[cur] < pivot)
            swap(arr[++i] ,arr[cur++]);
        else if(arr[cur] > pivot)
            swap(arr[--j],arr[cur]);
        else 
            ++cur;
    }
    return i + 1;
}
int BFPRT(vector<int> &arr,int L,int R,int K)
{
    return select(arr,L,R,K-1);
}
int select(vector<int> &arr,int L,int R,int K)
{
    if(L >= R)
        return arr[L];
    int pivot = mom(arr,L,R);
    int pos = partition(arr,L,R,pivot);
    if(K == pos)
        return arr[K];
    if(K < pos)
        return select(arr,L,pos-1,K);
    else 
        return select(arr,pos+1,R,K);
}



bool test()
{

}
int main()
{
    int N,K;
    cin>>N>>K;
    vector<int> arr(N);
    for(int i = 0;i < N;++i)
        cin>>arr[i];
    int ans = BFPRT(arr,0,N - 1,K);
    cout<<ans<<endl;
    return 0;
}