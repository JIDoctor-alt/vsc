#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
    int maxSubArray(vector<int>& nums) {
        vector<int> dp = vector<int>(nums.size()+1);
        dp[nums.size()] = -1;
        int n = int(nums.size());
        for(int i = 0;i < n;++i){
            dp[i] = nums[i];
        }
        for(int i = n - 1;i >= 0;i--)
        {
            if(dp[i + 1] > 0)
            {
                dp[i] = dp[i + 1] + nums[i];
            }else{
                dp[i] = nums[i];
            }
        }
        int maxS = dp[0];
        for(int i = 1;i < n;++i)
        {
            if(maxS < dp[i])
                maxS  = dp[i];
        }
        return maxS;
    }
    ///-2 1 -3 4 -1 2 1 -5 4
int main()
{
    vector<int> nums;
    int id;
    while(cin>>id)
    {
        nums.push_back(id);
    }
    cout<<maxSubArray(nums)<<endl;
    return 0;
}