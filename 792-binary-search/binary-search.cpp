class Solution {
public:
    int search(vector<int>& nums, int target) {
      int low=0;
      int n=nums.size();
      int high=  n-1;
      int guess=floor((low+high)/2);
    while(low<=high){
        int guess=floor((low+high)/2);
        if(nums[guess]==target){
        return guess;
        }
        if(nums[guess]<target){
        low=guess+1;
        }
        if(nums[guess]>target){
        high=guess-1;
      }
    }
      return -1;
    }
};