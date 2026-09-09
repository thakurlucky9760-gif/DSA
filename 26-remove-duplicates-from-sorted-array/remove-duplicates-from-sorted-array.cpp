class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int off =0;
        int unique=1;
        int cm=1;

        while (cm<nums.size()){
            if(nums[cm]==nums[cm-1]){
                cm++;
                continue;

            }
            else{
                nums[off+1]=nums[cm];
                off++;
                unique++;
                cm++;
            }
        }
        return unique;
    }
};