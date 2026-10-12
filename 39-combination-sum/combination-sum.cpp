class Solution {
public:
    void fun(vector<int>& candidates, int n, int idx, int target,
             vector<int>& diary, int sum, vector<vector<int>>& res) {
        
            if(sum==target){
            res.push_back(diary);
            return;
            
        }
        if(idx==n || sum>target){
            return;
        }
        
        fun(candidates, n, idx + 1, target, diary, sum, res);
        if (sum + candidates[idx] <= target) {
                diary.push_back(candidates[idx]);
                sum += candidates[idx];
                fun(candidates, n, idx, target, diary, sum, res);
                diary.pop_back();
                sum -= candidates[idx];
            
            return;
        }
             }

        vector<vector<int>> combinationSum(vector<int> & candidates,
                                           int target) {
            int n = candidates.size();
            int sum = 0;
            int idx = 0;
            vector<int> diary;
            vector<vector<int>>res;

        fun(candidates, n, idx, target, diary, sum, res);
            return res;
        }
    };