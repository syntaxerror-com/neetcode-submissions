class Solution {
public:

    void combine(vector<int>nums,int target,int i,vector<int>result,vector<vector<int>>&results){
        if(target==0){
            results.push_back(result);
            return;
        }
        if(target<0||i==nums.size()){
            return;
        }
        result.push_back(nums[i]);
        combine(nums,target-nums[i],i+1,result,results);
        result.pop_back();
        while(i + 1 < nums.size()&&nums[i]==nums[i+1]){
            i++;
        }
        combine(nums,target,i+1,result,results);

    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>result;
        vector<vector<int>>results;
        combine(nums,target,0,result,results);
        return results;
    }
};
