class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxValue = *max_element(nums.begin(), nums.end());
        int curr = 0, maxLengthFound = 0;

        for (int n : nums) {
            if (n == maxValue) {
                curr++;
                maxLengthFound = max(maxLengthFound, curr);
            } else {
                curr = 0;
            }
        }

        return maxLengthFound;
    }
};