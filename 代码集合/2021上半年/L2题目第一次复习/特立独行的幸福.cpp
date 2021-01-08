#include<iostream>
#include<map>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> cnt;
map<int,int> m;
bool visited[10010];
int Valid(int t){
  //  if(t == 2)return 2;
    //素数只能被1和本身整除
    for(int i = 2;i <= sqrt(t);i++)
        if(t%i==0)return 1;
    return 2;
}
int main(){

    fill(visited,visited+10010,false);
    int startnum,endnum;
    cin>>startnum>>endnum;
    int n;
    for(int i = startnum;i <= endnum;i++){
           
            n = i;
            if(visited[i])continue;
            
            cnt.clear();

            while(n!=1){

                int sum = 0;
                while(n){
                    sum += (n%10)*(n%10);
                    n /= 10;
                }

                if(find(cnt.begin(),cnt.end(),sum)!= cnt.end()){
                   // visited[sum] = true;
                    break;
                }

                cnt.push_back(sum);

                visited[sum] = true;//sum依赖于其他数

                n = sum;
            }

           /* if(n==1){
                m[i] = cnt.size()*Valid(i);     
            }*/
           /* if(n==1 && !visited[i])
                  cout<<i<<" "<<cnt.size()*Valid(i)<<endl;*/
            if(n == 1)
                m[i] = cnt.size()*Valid(i);


    }
    map<int,int>::iterator i;
    int ans = 0;
    for(i = m.begin();i!=m.end();i++){
        if(!visited[i->first])
           {
               cout<<i->first<<" "<<i->second<<endl;
               ans++;
           } 
    }
    if(!ans)
        cout<<"SAD"<<endl;
    return 0;
}