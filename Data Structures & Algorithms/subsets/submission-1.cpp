class Solution {
public:
    void subset(vector<int>nums,int i,vector<int>result,vector<vector<int>>&results)
    {
     results.push_back(result);
     for(int key=i;key<nums.size();key++){
         result.push_back(nums[key]);
         subset(nums, key + 1, result, results);
         result.pop_back();
     }
    }    
vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>result;
        vector<vector<int>>results;
        subset(nums,0,result,results);
       return results;
    }
};
