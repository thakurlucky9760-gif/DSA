class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sum=nums[0];
        int min_sum=nums[0];
    
    
        int res=abs(nums[0]);
        int n=nums.size();
        for(int i=1;i<n;i++){
            int v1=nums[i];
            int v2=max_sum+nums[i];
            int v3=min_sum+nums[i];
            max_sum=max(v1,v2);
        
            min_sum=min(v1,v3);
        
            int a= abs(min_sum);
            int b=abs(max_sum);

            res=max(res,max(a,b));
        }
        return res;
    }
};