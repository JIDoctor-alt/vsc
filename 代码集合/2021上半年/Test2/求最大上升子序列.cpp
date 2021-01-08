#include<iostream>
#include<algorithm>

using namespace std;
const int MAX = 1010;
int maxLen[MAX];
int D[MAX];
int main(){
    int N;
    cin>>N;
    for(int i = 1;i <= N;i++){
        cin>>D[i];
        maxLen[i] = 1;
    }

    for(int i = 2;i <= N;i++){
        //以j为终点的最长上升子序列
        for(int j = 1;j < i;j++){
            ///如果比终点小就加一
            if(D[i] > D[j])
                maxLen[i] = max(maxLen[i],maxLen[j] + 1);
        }
    }

    cout<<*max_element(maxLen+1,maxLen+N+1);
        


    return 0;
}