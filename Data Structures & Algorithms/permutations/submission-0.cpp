class Solution {
public:

    void permutate(vector<int>& nums,
                   vector<bool>& map,
                   int i,
                   vector<int> result,
                   vector<vector<int>>& results){

        if(result.size() == nums.size()){
            results.push_back(result);
            return;
        }

        if(i == nums.size()){
            return;
        }

        if(map[i] == false){

            result.push_back(nums[i]);
            map[i] = true;

            permutate(nums, map, 0, result, results);

            result.pop_back();
            map[i] = false;
        }

        permutate(nums, map, i + 1, result, results);
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> result;
        vector<vector<int>> results;

        vector<bool> map(nums.size(), false);

        permutate(nums, map, 0, result, results);

        return results;
    }
};