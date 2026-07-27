class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        int maxvol = INT_MIN;

        while (i < j) {
            int volume = (j - i) * min(heights[i], heights[j]);
            maxvol = max(maxvol, volume);

            if (heights[i] < heights[j]) {
                i++;
            }
            else if (heights[j] < heights[i]) {
                j--;
            }
            else {
                i++;
                j--;
            }
        }

        return maxvol;
    }
};