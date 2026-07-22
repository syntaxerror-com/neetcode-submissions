class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;

        sort(nums.begin(), nums.end());

        int longest = 1;
        int current = 1;

        for (int i = 1; i < nums.size(); i++) {

            // Ignore duplicates
            if (nums[i] == nums[i - 1])
                continue;

            // Consecutive number found
            if (nums[i] == nums[i - 1] + 1)
                current++;

            // Sequence broken
            else
                current = 1;

            longest = max(longest, current);
        }

        return longest;
    }
};