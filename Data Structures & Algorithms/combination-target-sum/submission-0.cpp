class Solution {
public:

    void combine(vector<int>nums, int target,int i,vector<int>result,vector<vector<int>>&results){
        if(target==0){
            results.push_back(result);
            return;
        }
        if(i==nums.size()||target<0){
            return;
        }
        result.push_back(nums[i]);
        combine(nums,target-nums[i],i,result,results);
        result.pop_back();
        combine(nums,target,i+1,result,results);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>result;
        vector<vector<int>>results;

        combine(nums,target,0,result,results);
        return results;
    }
};
