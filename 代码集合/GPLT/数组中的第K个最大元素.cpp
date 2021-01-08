  #include<iostream>
  #include<vector>
  using namespace std;
  
  int findKthLargest(vector<int>& nums, int k) {
        int x =  quickSort(0,nums.size()-1,k,nums);
        return nums[x];
    }

    int partion(int l,int r,vector<int> nums){
        int k = nums[r];
        int i = l - 1;
        for(int j = l;j  < r;++j){
            if(nums[j] < k){
                ++i;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i + 1],nums[r]);
        return i + 1;
    }

    int quickSort(int s,int e,int k,vector<int>& nums){
        if(s >= e && s == k - 1)
            return s;

        int  m = partion(s,e,nums);
        
        if(m == k - 1)
            return m;
        else if(m < k -1)
            return quickSort(m + 1, e,k,nums);
        else if(m > k - 1)
            return quickSort(s ,m - 1,k,nums);
    }