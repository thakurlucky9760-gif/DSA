class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        int res=0;
        unordered_map<int,int>f;
        f[0]++;

        for(int i=0;i<n;i++){
            sum+=nums[i];

            int red_part=sum-k;

            res=res+f[red_part];
            f[sum]++;
        }
        return res;
    }
};