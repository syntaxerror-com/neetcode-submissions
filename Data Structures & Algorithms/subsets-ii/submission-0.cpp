class Solution {
public:

    void subsets(vector<int>nums,int i,vector<int>result,vector<vector<int>>&results){
        if(i==nums.size()){
            return;
        }
        result.push_back(nums[i]);
        results.push_back(result);

        subsets(nums,i+1,result,results);
        result.pop_back();
        while(i<nums.size()-1&&nums[i]==nums[i+1]){
            i++;
        }
        subsets(nums,i+1,result,results);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>result;
        vector<vector<int>>results;
         sort(nums.begin(), nums.end());
        results.push_back({});
        subsets(nums,0,result,results);
        return results;
    }
};
