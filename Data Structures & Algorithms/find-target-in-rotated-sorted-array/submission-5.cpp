class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        if(nums.size() == 1 && target == nums[0]){
            return 0;
        }

        while(right > 0 && nums[right] > nums[right-1]){
            right--;
        }

        int pivot = right;

        if(pivot == 0){
            left = 0;
            right = nums.size() - 1;
        }
        else if(target >= nums[0]){
            left = 0;
            right = pivot - 1;
        }
        else{
            left = pivot;
            right = nums.size() - 1;
        }

        while(left <= right){
            int mid = (left + right) / 2;

            if(nums[mid] > target){
                right = mid - 1;
            }
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else{
                return mid;
            }
        }

        return -1;
    }
};