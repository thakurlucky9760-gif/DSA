class Solution {
public:
    int first(vector<int>&nums,int target){
        int low=0;
        int n=nums.size();
        int high=n-1;
        int res=-1;
       
        while(low<=high){
           int guess=floor((low+high)/2);
            if(nums[guess]<target){
                low=guess+1;
            }
            if(nums[guess]>target){
                high=guess-1;
            }
            if(nums[guess]==target){
                res=guess;
                high=guess-1;
              
                
            }
        }
          return res;
    }
    int second(vector<int>&nums,int target){
        int low=0;
        int n=nums.size();
        int high=n-1;
        int res=-1;
       
        while(low<=high){
           int guess=floor((low+high)/2);
            if(nums[guess]<target){
                low=guess+1;
            }
            if(nums[guess]>target){
                high=guess-1;
            }
            if(nums[guess]==target){
                res=guess;
                low=guess+1;
                
                
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       
        return {first(nums, target), second(nums, target)};

        
    }
};