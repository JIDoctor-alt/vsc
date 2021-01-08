#include<iostream>
#include<algorithm>
#include<chrono>
#include<functional>
using namespace std;
using namespace std::chrono;
int a[10000000];
int main(){
    int N;
    cin>>N;
    for(int i = 0;i < N;i++)
        cin>>a[i];
    
    auto it1 = high_resolution_clock::now();
    //从小到大排序a[0]...a[N-1]
    sort(a+0,a+N);
    //从大到小排序
    //sort(a + 0,a + N,greater<int>());
    auto it2 = high_resolution_clock::now();
    //纳秒
    cout<<duration_cast<nanoseconds>(it2-it1).count() <<" ns"<<endl;
    //微妙
    cout<<duration_cast<microseconds>(it2-it1).count()<<" us"<<endl;
    //毫秒
    cout<<duration_cast<milliseconds>(it2-it1).count()<<" ms"<<endl;
    //系统方法，判断一段区间是否有序（默认升序）
    cout<<boolalpha<<is_sorted(a + 0,a + N);
    return 0;
}
