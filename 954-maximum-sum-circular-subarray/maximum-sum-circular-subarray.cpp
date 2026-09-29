 class Solution {

public:

    int maxSubarraySumCircular(vector<int>& nums) {

      int max_sum=nums[0];

      int min_sum=nums[0];

      int cur_max=nums[0];

      int cur_min=nums[0];

      int sum=0;

      int res=nums[0];

      int n=nums.size();

      for(int i=0;i<n;i++){

        sum=sum+nums[i];

    }

      for(int i=1;i<n;i++){

        cur_max=max(cur_max+nums[i],nums[i]);

        cur_min=min(cur_min+nums[i],nums[i]);

        max_sum=max(max_sum,cur_max);

        min_sum=min(min_sum,cur_min);

       



       

      }

      if(max_sum<0){

        return max_sum;

      }

      int a=sum-min_sum;

    res=max(res,max(a,max_sum));

      return res;



    }

};